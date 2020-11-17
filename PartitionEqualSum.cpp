#include <iostream>
#include <map>
#include <vector>

using std::vector;
using std::map;

bool canThreePartsEqualSum(vector<int>& A) {

	int sz = A.size();
	for(int i = 1; i!=sz; i++)
		A[i]+=A[i-1];
	int left, right, mid;
	for(int i=0; i!=sz-2; i++)
	{
		if(2*A[i] == A[sz-1] - A[i])
		{
			for(int j = i+1; j!=sz-1; j++)
				if(A[i] == A[sz-1] - A[j])
					return true;
		}
	}
	return false;
  }

int main()
{
	vector<int> A = {1,13,14,-15,13,5,-16,-3,-12,42};
	std::cout<<canThreePartsEqualSum(A);
}

/*
while(left<right)
{
	mid = (left+right)/2;
	if(A[mid]-A[i] == A[sz-1]-A[mid] == )
		return true;
	if(A[mid]-A[i] < A[sz-1]-A[mid])
		left = mid + 1;
	else
		right = mid;
}
8*/
