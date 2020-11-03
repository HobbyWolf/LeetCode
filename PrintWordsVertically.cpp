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
	string k;
	k.reserve(101);
	vector<string> vertString(200, k);
	int i = 0, length = 0;

	for(auto it = s.begin(); it!=s.end(); it++)
	{
		if(*it == ' ')
		{
			length = max(length, i);
			for(int j = i; j<200; j++)
				vertString[j].push_back(' ');
			i = 0;
			continue;
		}
		vertString[i].push_back(*it);
		i++;
	}
	length = max(length, i);
	for(i = 0 ; i< length+1 ; i++)
	{
		while(vertString[i].back() == ' ') vertString[i].pop_back();
	}

	return std::vector<string>(vertString.begin(), vertString.begin()+length);

    }

	int main()
	{
		string s = "VCIU PLBAUER OPCTOW TIBVLFVPOF FZ QPR SVUOWXZG ALQCR NHFKVJPLK GJTGKBFGH QLCXCXABF ODOHBQXRYY EYIGYXJZJV JKO SEXPZNO UWVSU TD OHLDJFEI YUHOLKTGUR HDMBSBO";
		vector<string> res = printVertically(s);
		for(auto a:res)
			std::cout<<a<<"->";
	}
