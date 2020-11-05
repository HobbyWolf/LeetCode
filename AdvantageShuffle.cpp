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

// Logic
/* Sort the array. For every element in B find the upperbound in A.
Else return the first element.
*/

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
  	multiset<int> s(begin(A), end(A));
	unsigned int i;
  	for (i = 0; i < B.size(); i++) {
	  	auto p = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
	  	A[i] = *p;
	  	s.erase(p);
  	}
  return A;
}
int main()
{}
