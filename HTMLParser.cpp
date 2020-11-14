#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;


string entityParser(string text) {
        map<string, char> html = {{"&quot", '\"'}, {"&apos", '\''}, {"&amp", '&'}, {"&gt", '>'},{"&lt", '<'}, {"&frasl", '/'}};
		string res = "";
		for(auto it = text.begin(); it !=text.end(); it++)
		{
			if(*it == '&'){
				int count = 0;
				string key = "";
				for(auto it2 = it; it2 != text.end() && count < 6 && *it2 != ';'; it2++, count++)
					key+=*it2;
				if(html[key]){
					res+=html[key];
					it+=count;
					continue;
				}
			}
			res+=*it;
		}
		return res;
    }

int main()
{
	string entry = "x &gt; y &amp;&amp; x &lt; y is always false";
	std::cout<<entityParser(entry);
}
