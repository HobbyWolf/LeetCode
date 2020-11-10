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

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int sum = 0;
        map<int, int> lab_count;
        int sz = values.size();
        for(int i = 0; i != sz && num_wanted > -1 ; i++)
            if(++lab_count[labels[i]] <= use_limit){
                sum+=values[i];
                num_wanted--;
            }
        return sum;

    }

int main()
{
	vector<int> A = {5,4,3,2,1}, B = {1,1,2,2,3};
	int x = 3, y = 1;
	std::cout<<largestValsFromLabels(A, B, x, y);
}
