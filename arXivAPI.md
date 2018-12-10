# arXiv API : useful info
Here's the complete user manual (https://arxiv.org/help/api/user-manual#_calling_the_api). This is a recap of the most useful info.


For each method, the base url is
http://export.arxiv.org/api/query?{parameters}

------------------------------------

parameters: `search_query` (string), `id_list` (comma-delimited string), `start` (int), `max_results`	(int)


If only `search_query` is given (`id_list` is blank or not given), then the API will return results for each article that matches the search query.

If only `id_list` is given (`search_query` is blank or not given), then the API will return results for each article in `id_list`.

If BOTH `search_query` and `id_list` are given, then the API will return each article in `id_list` that matches search_query. This allows the API to act as a results filter.


Filter queries : 
---

- Searching using the author's name : http://export.arxiv.org/api/query?search_query=au:Einstein
- Publication's id : http://export.arxiv.org/api/query?search_query=hep-ph/9807350
            
            with "hep-ph" standing for the name of the subcategory
            and "9807350" standing for the identification number of the article
           
- Title : ".../search_query=ti:blabla"
- `id_list`: ".../search_query=id_list:blabla"
- Journal reference : ".../search_query=jr:blabla"
- Booleans: AND, OR, ANDNOT

  Example : http://export.arxiv.org/api/query?search_query=au:del_maestro+AND+ti:checkerboard

- Sorting by date :  http://export.arxiv.org/api/querysearch_query=ti:"electronthermalconductivity"&sortBy=lastUpdatedDate&sortOrder=ascending
  
  `sortBy` can be "relevance", "lastUpdatedDate", "submittedDate"
  
  `sortOrder` can be either "ascending" or "descending"


To obtain metadata from the article's ID : 
http://export.arxiv.org/api/query?id_list=1812.03164


Calling the API :
---
- incorporate a 3 second delay in your code
- maximum number of results returned from a single call (max_results) is limited to 30000


Outline of an Atom feed
---
In the metadate of the query
- The <id> element serves as a unique id for this query, and is useful if you are writing a program such as a feed reader that wants to keep track of all the feeds requested in the past. This id can then be used as a key in a database. The id is guaranteed to be unique for each query.
  
The <entry> metadata
- The <title> element contains the title of the article returned
- The <id> element contains a url that resolves to the abstract page for that article :
  
  <id xmlns="http://www.w3.org/2005/Atom">
    http://arxiv.org/abs/hep-ex/0307015
  </id>
  
  If you want only the arXiv id for the article, you can remove the leading http://arxiv.org/abs/ in the <id>.
  
- The <published> tag contains the date in which the first version of this article was submitted and processed.
  
- There is one <author> element for each author of the paper in order of authorship. Each <author> element has a <name> sub-element which contains the name of the author.

- For each entry, there are up to three <link> elements, distinguished by their rel and title attributes.

  <link xmlns="http://www.w3.org/2005/Atom" title="pdf" href="http://arxiv.org/pdf/hep-ex/0307015v1" rel="related" type="application/pdf"/>
  
  rel=alternate	; title=-	; refers to an abstract page ; always present	
  
  rel=related	; title=pdf	; refers to a pdf ; always present	
  
  rel=related	; title=doi	; resolved doi ; not always present	

- If the author has provided a journal reference for the article, then there will be a <arxiv:journal_ref> element with this information:


  
