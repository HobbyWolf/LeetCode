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

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		vector<int> stack(pushed.size(), -1);
		int i = 0, j = 0;
		for(auto a:pushed)
		{
			stack[i++] = a;
			while(i>0 && stack[i-1] == popped[j]){
				i--;
				j++;
			}
		}
		return i == 0;
    }

	int main()
	{
		vector<int> pushed = {1,0};
		vector<int> popped = {1,0};
		std::cout<<validateStackSequences(pushed, popped);
	}
