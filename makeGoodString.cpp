#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include <bits/stdc++.h>
#include<list>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::max;
using std::list;
using std::find;

string makeGood(string s) {

		if(s == "")
			return s;
        for(unsigned int i = 0; i < s.size()-1; i++)
        {
            if(abs(s[i] - s[i+1]) == 32){
                s.erase(i, 2);
                return makeGood(s);
            }
        }
        return s;
    }

	int main()
	{
		string B = "abBAcC";
		string C = "LeEeetCodeEe";
		string s = makeGood(C);
		std::cout<<s;
	}
