#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include <bits/stdc++.h>
#include<list>
#include<queue>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::max;
using std::list;
using std::find;
using std::queue;


vector<string> printVertically(string s) {
	vector<string> vertString;
	int i = -1, length = -1, words=0;

	for(auto it = s.begin(); it!=s.end(); it++)
	{
		if(*it == ' ')
		{
			words++;
			length = max(length, i);
			i = -1;
			continue;
		}
		i++;
		if(i > length)
		{
			vertString.push_back({});
			vertString[i] = string(words-vertString[i].size(), ' ');
		}
		vertString[i] += (string(words - vertString[i].size(), ' ') + *it);
	}
	return vertString;

    }

	int main()
	{
		string s = "VCIU PLBAUER OPCTOW TIBVLFVPOF FZ QPR SVUOWXZG ALQCR NHFKVJPLK GJTGKBFGH QLCXCXABF ODOHBQXRYY EYIGYXJZJV JKO SEXPZNO UWVSU TD OHLDJFEI YUHOLKTGUR HDMBSBO";
		string s2 = "TO BE OR NOT TO BE";
		vector<string> res = printVertically(s2);
		for(auto a:res)
			std::cout<<a<<"->";
	}
