#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include <bits/stdc++.h>
#include<list>
#include<queue>
#include<set>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::max;
using std::list;
using std::find;
using std::queue;
using std::min;
using std::multiset;

bool detectCapitalUse(string word) {
    if(word.size()==1) return 1;
    bool flag = (word[1] >= 'a');
    bool flag2 = (word[0] >= 'a');
    if(flag2 - flag > 0)
        return 0;
    for(auto a : string(word.begin() + 1, word.end())){
        if((a >= 'a') != flag)
            return 0;
    }
    return 1;


  }
  int main()
  {
      string word = "ABC";
      std::cout<<detectCapitalUse(word);
  }
