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

		queue<pair<int,int>> binQueue;
		binQueue.push(pair<int,int>(0,0));
		grid[0][0] = 1;

		vector<vector<int>> directions = {{1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1,1}};
		while(!binQueue.empty())
		{
			auto top = binQueue.front();
			int x = top.first;
			int y = top.second;
			if(x == m-1 && y == n-1)
				return grid[x][y];

			for(auto dir : directions)
			{
				int dx = x + dir[0], dy = y + dir[1];
				if(dx > -1 && dx < m && dy > -1 && dy < n && grid[dx][dy] == 0)
				{
					binQueue.push(pair<int,int>(dx,dy));
					grid[dx][dy] = grid[x][y] + 1;
				}

			}
			binQueue.pop();
		}
		return -1;


  }

  int main()
  {
	  vector<vector<int>> A{{0,1}, {1,0}};
	  std::cout<<shortestPathBinaryMatrix(A);
  }
