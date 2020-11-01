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

void place_queens(int, int, vector<int>, vector<int>, vector<int>, vector<int>);

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


	vector<int> column(n, 1), sub_cell(2*n-1, 1), add_cell(2*n-1, 1), queen_pos(n, -1);
	place_queens(2, n, column, sub_cell, add_cell, queen_pos);
	return store_queen(master, n);
}

void place_queens(int row, int nq, vector<int> columnq, vector<int> sub_cellq, vector<int> add_cellq, vector<int> queen_posq)
{
	if(row==nq)
	{
		master.push_back(queen_posq);
		return;
	}

	for(int col = 0; col < nq; col++)
	{
		if(columnq[col] && sub_cellq[nq-1 + col - row] && add_cellq[col + row])
		{
			queen_posq[row] = col;
			columnq[col] = 0;
			sub_cellq[nq-1 + col - row] = 0;
			add_cellq[col + row] = 0;
			place_queens(row+1, nq, columnq, sub_cellq, add_cellq, queen_posq);
			queen_posq[row] = -1;
			columnq[col] = 1;
			sub_cellq[nq-1 + col - row] = 1;
			add_cellq[col + row]	= 1;
		}
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
