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

vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l]))
				res[k] = A[r] * A[r--];
            else
				res[k] = A[l] * A[l++];
        }
        return res;
    }

int main()
{
	vector<int> B = {-3, -2, -1, 0, 1, 2, 3};
	vector<int> C = {3, 4, 5, 6};
	vector<int> Kmag = sortedSquares(C);
	for(auto a:Kmag)
		std::cout<<a<<" ";
}
