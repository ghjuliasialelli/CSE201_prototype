# arXiv API : useful info
Here's the complete user manual (https://arxiv.org/help/api/user-manual#_calling_the_api). This is a recap of the most useful info.


For each method, the base url is
http://export.arxiv.org/api/query?{parameters}

------------------------------------

parameters: `search_query` (string), `id_list` (comma-delimited string), `start` (int), `max_results`	(int)


If only `search_query` is given (`id_list` is blank or not given), then the API will return results for each article that matches the search query.

If only `id_list` is given (`search_query` is blank or not given), then the API will return results for each article in `id_list`.

If BOTH `search_query` and `id_list` are given, then the API will return each article in `id_list` that matches search_query. This allows the API to act as a results filter.


Template queries : 
---

Searching using the author's name : http://export.arxiv.org/api/query?search_query=au:Einstein



Calling the API :
---
- incorporate a 3 second delay in your code
- maximum number of results returned from a single call (max_results) is limited to 30000
