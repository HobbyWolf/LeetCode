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

vector<vector<int>> master;

void place_queens(int, int, list<int>, list<int>, list<int>, vector<int>);

vector<vector<string>> store_queen(vector<vector<int>> master_q, int n)
{
	vector<vector<string>> queens;

	for(auto comb: master_q)
	{
		vector<string> board;
		board.reserve(n);
		for(auto row:comb)
		{
			string q(n, '.');
			q[row-1] = 'Q';
			board.push_back(q);
		}
		queens.push_back(board);
	}
	return queens;
}

vector<vector<string>> solveNQueens(int n) {


	list<int> col, sub_cell, add_cell, col_temp;
	for(int i = 1; i<=n ; i++)
		col.push_back(i);
	for(int j = 1; j<=n; j++)
	{
		sub_cell.clear();
		add_cell.clear();
		vector<int> queen_pos;
		queen_pos.reserve(n);
		queen_pos.emplace_back(j);
		col_temp = col;
		sub_cell.push_back(j-1);
		add_cell.push_back(j+1);
		col_temp.remove(j);
		place_queens(2, n, col_temp, sub_cell, add_cell, queen_pos);
	}
	return store_queen(master, n);
}

void place_queens(int start, int nq, list<int> colq, list<int> sub_cellq, list<int> add_cellq, vector<int> queen_posq)
{
	if(start>nq)
		master.push_back(queen_posq);
	while(start <= nq)
	{
		for(auto a:colq)
		{
			auto queen_posq_temp = queen_posq;
			int start_temp = start;
			auto colq_temp = colq;
			auto sub_cellq_temp = sub_cellq;
			auto add_cellq_temp = add_cellq;
			auto it_sub = find(sub_cellq.begin(), sub_cellq.end(), a-start);
			auto it_add = find(add_cellq.begin(), add_cellq.end(), a+start);
			if(it_sub == sub_cellq.end() && it_add == add_cellq.end())
			{
				queen_posq_temp.push_back(a);
				sub_cellq_temp.push_back(a-start);
				add_cellq_temp.push_back(a+start);
				colq_temp.remove(a);
				place_queens(++start_temp, nq, colq_temp, sub_cellq_temp, add_cellq_temp, queen_posq_temp);
			}
		}
		break;
	}
}

int main()
{
	solveNQueens(5);
}


// Optimized solution

/*
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};
*/
