#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;


bool validTicTacToe(vector<string>& board) {
        vector<int> A(8, 0), B(8, 0);
        int c_X=0, c_O=0;
		char win = ' ';
		vector<int>& player = A;
        for(int k = 0; k < 9; k++)
		{
			int i = k/3, j = k%3;
			if(board[i][j] == 'X'){
				player = A;
				c_X++;
			}
			else if(board[i][j] == 'O'){
				player = B;
				c_O++;
			}
			else continue;

			player[i]++;
			player[j+3]++;
			std::cout<<j<<"->"<<player[j+3]<<" ";

			if(i == j) player[6]++;
			if(i+j == 2) player[7]++;
		}

		std::cout<<c_O<<c_X<<win;
		if((c_O > c_X) || (c_O == c_X && win == 'A') || (c_X > c_O + 1) || (c_X > c_O && win == 'B'))
			return false;

		return true;

    }

	int main()
	{
		vector<string> board = {"XO ", "XO ", "XO "};
		std::cout<<validTicTacToe(board);
	}
