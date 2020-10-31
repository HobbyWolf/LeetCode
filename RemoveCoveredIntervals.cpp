
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::max;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int count = 0;
        sort(intervals.begin(), intervals.end());

		int left = -1, right = -1;
		for(auto & v:intervals){
			if(v[0] > left && v[1] > right){
				left = v[0];
				++count;
			}
			right = max(right, v[1]);
			}

		return count;
    }

int main()
{
	vector<vector<int>> inp{{1,2},{1,4}};
	std::cout<<removeCoveredIntervals(inp);
}
