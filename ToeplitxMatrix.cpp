
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

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		unsigned int i;
		for(auto it = matrix.begin(); it != --matrix.end(); it++)
		{
			auto it2 = it + 1;
			for(i = 0; i < (*it).size()-1; i++)
			{
				if((*it)[i] != (*it2)[i+1])
					return false;
			}
		}
		return true;
    }

int main()
{
	vector<vector<int>> A = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
	std::cout<<isToeplitzMatrix(A);
}
