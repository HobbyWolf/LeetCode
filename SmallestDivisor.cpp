#include <iostream>
#include <vector>
#include <algorithm>

using std::sort;
using std::upper_bound;
using std::vector;

int smallestDivisor(vector<int>& nums, int threshold) {
	int res = 1, sum = 1000001, i;
	sort(nums.begin(), nums.end());
	for( ; sum>threshold ; res++){
		sum = 0;
		auto it = nums.begin();
		auto new_it = it;
		for(i = nums[0]/res; new_it!=nums.end(); i++)
		{
			sum+=((i-1)*(new_it-it));
			it = new_it;
			new_it = upper_bound(it, nums.end(), i*res);
		}
		sum+=(--i*(nums.end()-it));
	}


	return --res;
}

int main()
{
	 vector<int> nums = {2,3,5,7,11};
	 int threshold = 11;
	 std::cout<<smallestDivisor(nums, threshold);
}
