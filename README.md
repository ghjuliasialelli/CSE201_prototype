# CSE201_prototype

Important files : 
---

arXiv.md : 
----
Description of arXiv's API and how to use it to meet our needs.


file.cpp : 
----

allows us to write the content of an URL onto a file. By default, the file is .xml (because that's the format we obtain when proceeding to a HTTP request with arXiv's API).

To use it (everything is written in the cpp file) : 


g++ file.cpp -o main `pkg-config --libs libcurl`   
  

./main http://export.arxiv.org/api/query?search_query=au:Einstein


For now, we have to pass the URL in the terminal. Working on automating it. 
