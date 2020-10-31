#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::map;
using std::pair;

void clean(map<int, int>& );

int trap(vector<int>& height) {

        if(height.empty())
            return 0;
        map<int, int> hist;
        int INTMAX = *max_element(height.begin(), height.end());
        for(int i=0 ; i <= INTMAX; i++)
            hist.insert(pair<int, int>(i, 0));

        for (auto a:height)
            hist[a]++;

        clean(hist);

        int start = 0, sum = 0;

        for(auto a:height)
        {
            std::cout<<a<<" : "<<std::endl;
            hist[a]--;
            for(auto it = hist.begin(); it!=hist.end(); it++)
                std::cout<<it->first<<" : "<<it->second<<std::endl;
            if((--hist.end())->second == 0)
            {
                clean(hist);
                if(!hist.empty())
                    start = (--hist.end())->first;
                continue;
            }

            if(start >= a)
                sum+=(start-a);
            else
                start = a;
        }

        return sum;

    }

    void clean(map<int, int>& lol)
    {
        auto it = --lol.end();
        while(!lol.empty() && it->second == 0)
        {
            lol.erase(it--);
        }
        // for(auto it = lol.begin(); it!=lol.end(); it++)
        //     std::cout<<it->first<<" : "<<it->second<<std::endl;
    }

int main()
{
    vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> b{5,5,1,7,1,1,5,2,7,6};
    std::cout<<trap(b);
}

//Better solution for water tripping problem

/*
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}

//With left and right iterator.

int trap(vector<int>& height) {
    auto l = height.begin(), r = height.end() - 1;
    int level = 0, water = 0;
    while (l != r + 1) {
        int lower = *l < *r ? *l++ : *r--;
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
*/
