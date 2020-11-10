#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::vector;
using std::min;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		vector<vector<int>> sorter = {};
		vector<int> res;
		int sz = nums.size();
		for(int i = 0; i < sz; i++)
			for(int j = 0; j < nums[i].size(); j++)
			{
				if((i+j) >= sorter.size())
					sorter.push_back({});
				sorter[i+j].push_back(nums[i][j]);
			}
		for(int i = 0; i < sorter.size(); i++)
			for(int j = sorter[i].size() - 1; j>=0; j--)
				res.push_back(sorter[i][j]);

    return res;
}

int main()
{
	vector<vector<int>> A = {{1,2,3,4,5,6,10,11,12,20,30},{6,7},{8},{9,10,11},{12,13,14,15,16}};
	auto res = findDiagonalOrder(A);
	for(auto b:res)
		std::cout<<b<<" ";
}
