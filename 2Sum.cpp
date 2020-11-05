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
// Logic:
/*
In this case, there is only once solution. For each element in vector, check if target-num is in map. If not add th number to map with the index.
Continue until a match is found.
*/

vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> trackSum;
        int sz = nums.size(), diff_num;

        for(int i = 0 ; i < sz ; i++)
        {
            diff_num = target - nums[i];
            auto it = trackSum.find(diff_num);
            if(it != trackSum.end())
                return {i, it->second};
            trackSum[nums[i]] = i;
        }
        return {-1, -1};
    }


	int main()
	{
		vector<int> a = {2,7,11,15};
		vector<int> ans = twoSum(a, 9);
		for (auto a: ans)
			std::cout<<a<<" ";
	}
