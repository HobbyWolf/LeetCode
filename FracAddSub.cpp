#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include <bits/stdc++.h>
#include<list>
#include<queue>
#include<set>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::max;
using std::list;
using std::find;
using std::queue;
using std::min;
using std::multiset;
using std::unordered_map;
using std::to_string;

string fractionAddition(string expression) {
	vector<vector<int>> A;
	int sz = expression.size(), denom;
	int sign = 1, lcm = 1, sum=0;
	string s = "";
 	for(int i = 0; i < sz;)
	{
		sign = 1;
		if(expression[i] == '+' || expression[i] == '-')
		{
			if(expression[i] == '-')
				sign = -1;
			i++;
		}
		denom = expression[i+2] - '0';
		A.push_back(vector<int>(sign*(expression[i]-'0'), denom));
		lcm = (lcm*denom)/(std::__gcd(lcm, denom));
		i+=3;
	}
	for(auto it = A.begin(); it!= A.end(); it++)
	{
		sum+=(((*it)[0])*(lcm/(*it)[1]));
	}
	if (sum<0)
		s+='-';
	int gcd = std::__gcd(abs(sum), lcm);
	return string(s+to_string(abs(sum)/gcd)+'/'+to_string(lcm/gcd));

    }

int main()
{
	string s = "-1/2+1/2+1/3";
	std::cout<<fractionAddition(s);
}
