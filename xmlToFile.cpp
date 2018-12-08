/* First draft of XML parsing from an url. For now, it std out the line where the element was found.
Goal : make it write into a file ? 

to compile : use the g++ flags: `pkg-config --cflags glibmm-2.4 libxml++-2.6 --libs` .
you need to have installed curlpp, glibmm and libxml++ */ 

/* shouldnt need those headers 
#include <cstdlib>  // thats the C library <stdlib.h>
#include <cstdio>   // thats the C library <stdio.h>
#include <unistd.h> // thats the unix standard header 
#include <curl/curl.h> */ 

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <libxml++/libxml++.h>  //xml parser library 

#include <iostream>             // Header that defines the standard input/output stream objects
#include <string>

using namespace curlpp::options;


int main() {
    curlpp::Cleanup myCleanup;

    std::string url = "http://export.arxiv.org/api/query?search_query=all:electron&start=0&max_results=1" ;
    curlpp::Easy request ;  

    // specify the url 
    request.setOpt(curlpp::options::Url(url));

    // Configure curlpp to use stream
    std::ostringstream responseStream;
    curlpp::options::WriteStream streamWriter(&responseStream);
    request.setOpt(streamWriter);

    // Collect response
    request.perform();
    std::string re = responseStream.str();  // convert stream to string

    // parse the XML with libxml++

    /* Careful : libxml++ requires the full namespace when selecting tags
    This won’t work: *p/text()
    But this will: *[local-name() = 'p']/text()
    */ 

    xmlpp::DomParser doc;
    doc.parse_memory(re);

    xmlpp::Document* document = doc.get_document();
    xmlpp::Element* root = document->get_root_node();
    // or : xmlpp::Element* root = new xmlpp::Element(r);


    /* we search for the element with id ‘some_id’. After outputting how many elements match that criteria (should be 1), 
    we output the line in the XML at which the element occurs. */
    xmlpp::NodeSet elemns = root->find("descendant-or-self::*[@id = 'some_id']");
    std::cout << elemns[0]->get_line() << std::endl;
    std::cout << elemns.size() << std::endl;

    return 0 ; 
}


