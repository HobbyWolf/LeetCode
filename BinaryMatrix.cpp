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

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		if(m==0 || n==0 || m!=n)
			return -1;
		if(grid[0][0] != 0 || grid[m-1][n-1] != 0)
			return -1;

		vector<int> binVector;
		binVector.push_back(0);
		grid[0][0] = 1;
		unsigned int k = 0;
		while(k < binVector.size())
		{
			auto top = binVector[k];
			int x = top / m;
			int y = top % m;
			if(x == m-1 && y == n-1)
				return grid[x][y];

			for(int i = -1 ; i < 2; i++)
				for(int j = -1; j < 2; j++)
				{
				int dx = x + i, dy = y + j;
				if(dx > -1 && dx < m && dy > -1 && dy < n && grid[dx][dy] == 0)
				{
					binVector.push_back(dx*m + dy);
					grid[dx][dy] = grid[x][y] + 1;
				}

			}
			k++;
		}
		return -1;


  }

  int main()
  {
	  vector<vector<int>> A{{0,1}, {1,0}};
	  std::cout<<shortestPathBinaryMatrix(A);
  }
