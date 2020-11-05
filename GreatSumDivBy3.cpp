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
using std::min;

// Logic:
/*
In each iteration, the 3 cells of the dp array is kept such that the remainder stays 0, 1, 2 respectively.
If we add rem = 0 number to all the cells, the remainder does not change. rem[2] + (num%3 == 1) = rem[0].
Do this recursively for all elements of the array.
*/

int maxSumDivThree(vector<int>& A) {
        vector<int> dp = {0, 0, 0}, dp2;
        for (int a : A) {
            dp2 = dp;
            for (int i: dp2) {
                dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
            }
        }
        return dp[0];
    }

int main()
{
    std::vector<int> v = {3,5,6,2,1,0,9,6,10};
    std::cout<<maxSumDivThree(v);
}
