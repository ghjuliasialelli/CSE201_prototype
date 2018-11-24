// we proceed to percent encoding to search tweets with Twitters streaming API 
// run a Twurl command to execute the search https://api.twitter.com/1.1/search/tweets.json?q=ourQuery
// we URL encode 'ourQuery' before making the search requests 


// cgicc namespace reference : http://www.gnu.org/software/cgicc/doc/namespacecgicc.html

using namespace std ;
using namespace cgicc ;


// Convert an ASCII string to a URL-safe string. 
// std::string cgicc::form_urldecode(	const std::string & 	src	 ) 
// For example, '!' is converted to "%21" and ' ' is converted to '+' (' ' can also be converted to '%20')
string form_urldecode(const string & )  ; 


// Convert encoded characters in form data to normal ASCII.
// std::string cgicc::form_urlencode	(	const std::string & 	src	 ) 	
// For example, "%21" is converted to '!' and '+' is converted to a space.
string form_urlencode(const string & 	 ) 	

int main() {
    return 0 ; 
}