#include<iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

string tictactoe(vector<vector<int>>& moves)
{
	// 8 ways to win.
	  vector<int> A(8,0), B(8,0);
      for(unsigned int i=0; i < moves.size(); i++)
	  {
          int r=moves[i][0], c=moves[i][1];
          vector<int>& player = (i%2==0)?A:B;
          player[r]++;
          player[c+3]++;
          if(r==c) player[6]++;
          if(r+c==2) player[7]++;
      }
      for(int i=0; i<8; i++)
	  {
          if(A[i]==3) return "A";
          if(B[i]==3) return "B";
      }
      return moves.size()==9 ? "Draw":"Pending";
  }
