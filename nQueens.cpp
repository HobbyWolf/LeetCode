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

vector<vector<vector<int>>> master;

void place_queens(int, int, list<int>, list<int>, list<int>);

void solveNQueens(int n) {


	list<int> col, sub_cell, add_cell, col_temp;
	for(int i = 1; i<=n ; i++)
		col.push_back(i);
	for(int j = 1; j<n/2.0+1; j++)
	{
		col_temp = col;
		sub_cell.push_back(j-1);
		add_cell.push_back(j+1);
		col_temp.remove(j);
		std::cout<<"1 - >"<<j<<std::endl;
		place_queens(2, n, col_temp, sub_cell, add_cell);
	}
}

void place_queens(int start, int nq, list<int> colq, list<int> sub_cellq, list<int> add_cellq)
{

	while(start <= nq)
	{
		for(auto a:colq)
		{
			int start_temp = start;
			auto colq_temp = colq;
			auto sub_cellq_temp = sub_cellq;
			auto add_cellq_temp = add_cellq;
			auto it_sub = find(sub_cellq.begin(), sub_cellq.end(), a-start);
			auto it_add = find(add_cellq.begin(), add_cellq.end(), a+start);
			if(it_sub == sub_cellq.end() && it_add == add_cellq.end())
			{
				std::cout<<start<<"- >"<<a<<std::endl;
				sub_cellq_temp.push_back(a-start);
				add_cellq_temp.push_back(a+start);
				colq_temp.remove(a);
				place_queens(++start_temp, nq, colq_temp, sub_cellq_temp, add_cellq_temp);
			}
		}
		break;
	}
}

int main()
{
	solveNQueens(4);
}
