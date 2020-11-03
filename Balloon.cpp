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
using std::min;

int maxNumberOfBalloons(string text) {
	vector<int> count(5, 0);
	for(auto a: text)
	{
		if(a=='b') count[0]++;
		else if(a=='a') count[1]++;
		else if(a=='l') count[2]++;
		else if(a=='o') count[3]++;
		else if(a=='n') count[4]++;
	}
    return min(min(count[2], count[3])/2, min({count[0], count[1], count[4]}));
    }

int main()
{
	string s = "loonbalxballpoon";
	string s2 = "nlaebolko";
	std::cout<<maxNumberOfBalloons(s2);
}
