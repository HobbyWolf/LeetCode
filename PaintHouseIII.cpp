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


int minCost(vector<int>& houses){//, vector<vector<int>>& cost, int m, int n, int target) {
	int init_neigh = 0, color = -1;
	int target = 3;
	for(int a : houses)
		if(a!=0 && color != a)
		{
			color = a;
			init_neigh++;
			if(init_neigh > target)
				return -1;
		}
	return init_neigh;

}

int main()
{
	vector<int> hses = {0,0,1,1,2,0,0,2,2,0,0,3,3,1,1,1};
	std::cout<<minCost(hses);
}

// Solutions from the web

// Solution 1
/*
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int init_neigh = 0, color = -1;
        for(int a : houses)
		if(a!=0 && color != a)
		{
			color = a;
			init_neigh++;
			if(init_neigh > target)
				return -1;
		}

        int INF = 1000000000;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n, INF)));

        for (int c = 1; c <= n; c++)
            if (houses[0] == c)
                dp[0][1][c - 1] = 0;
            else if (!houses[0])
                dp[0][1][c - 1] = cost[0][c - 1];

        for (int i = 1; i < m; i++)
            for (int k = 1; k <= min(target, i + 1); k++)
                for (int c = 1; c <= n; c++) {
                    if (houses[i] && c != houses[i]) continue;
                    int same_neighbor = dp[i - 1][k][c - 1];
                    int diff_neighbor = INF;
                    for (int c_ = 1; c_ <= n; c_++)
                        if (c_ != c)
                            diff_neighbor = min(diff_neighbor, dp[i - 1][k - 1][c_ - 1]);
                    int paint_cost = cost[i][c - 1] * int(!houses[i]);
                    dp[i][k][c - 1] = min(same_neighbor, diff_neighbor) + paint_cost;
                }
        int res = *min_element(dp.back().back().begin(), dp.back().back().end());
        return (res < INF) ? res : -1;
    }
*/


// Solution 2
/*
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        vector<vector<int>> dp(n+1, vector<int>(target+1, INT_MAX));

        for (int i = 1;i <= n;i++) {
            dp[i][1] = 0;
        }

        for (int i = 0;i < m;i++) {
            for (int t = min(target, i+1);t > 0;t--) {
                int minC0 = 0;
                int minC1 = 0;

                for (int c = 1;c <= n;c++) {
                    if (dp[c][t-1] < dp[minC0][t-1]) {
                        minC1 = minC0;
                        minC0 = c;
                    } else if (dp[c][t-1] < dp[minC1][t-1]) {
                        minC1 = c;
                    }
                }

                for (int c = 1;c <= n;c++) {
                    if (houses[i] != 0 && houses[i] != c) {
                        dp[c][t] = INT_MAX;
                        continue;
                    }

                    int v;
                    if (minC0 != c) {
                        v = dp[minC0][t-1];
                    } else {
                        v = dp[minC1][t-1];
                    }

                    v = min(v, dp[c][t]);

                    if (v != INT_MAX && houses[i] == 0) {
                        v += cost[i][c-1];
                    }

                    dp[c][t] = v;
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 1;i <= n;i++) {
            ans = min(ans, dp[i][target]);
        }

        return ans != INT_MAX? ans : -1;
    }
*/
