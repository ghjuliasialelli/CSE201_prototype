#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <iostream>
#include <fstream> // Stream class to both read and write from/to files.

using namespace curlpp::options;
using namespace std ; 

int main(int, char **)
{
	try
	{
		// That's all that is needed to do cleanup of used resources.
		curlpp::Cleanup myCleanup;

		// Set the URL.
		//curlpp::options::Url myUrl(std::string("http://inspirehep.net/textmining/?ln=en&fbclid=IwAR1JJVUiVazrFK6hgM_gWiPJQw1eP_wLWWC7bnjMrg6BqQ-EObuo2Acj048"));
		curlpp::options::Url myUrl(std::string("http://export.arxiv.org/api/query?search_query=all:electron&start=0&max_results=1")) ; 
		// Our request to be sent.
		curlpp::Easy myRequest;


		// OPTION 1 : the content of that URL will be printed in std::cout
		myRequest.setOpt(myUrl);
		myRequest.perform();


		// OPTION 2 : put the content of the URL within a string stream
		/* 
		std::ostringstream os;
		curlpp::options::WriteStream ws(&os);
		myRequest.setOpt(ws);
		myRequest.perform();  

		std::cout << os << std::endl ;  
		*/


		// OPTION 3 : writing the content of the URL onto a file
		/* 
		std::ofstream outfile ("test.txt");
  		outfile << os << std::endl;
  		outfile.close();
		*/ 
	}

	catch(curlpp::RuntimeError & e)
	{
		std::cout << e.what() << std::endl;
	}

	catch(curlpp::LogicError & e)
	{
		std::cout << e.what() << std::endl;
	}
    
  return 0;
}
