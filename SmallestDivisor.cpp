#include <iostream>
#include <vector>
#include <algorithm>

using std::sort;
using std::upper_bound;
using std::vector;

int get_Sum(vector<int>& nums, int res)
    {
        int sum = 0, i;
        auto it = nums.begin();
		auto new_it = it;
		for(i = 1; new_it!=nums.end(); i++)
		{
			sum+=((i-1)*(new_it-it));
			it = new_it;
			new_it = upper_bound(it, nums.end(), i*res);
		}
		sum+=(--i*(nums.end()-it));
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
	int left = 1, right = 1000000, mid, sum;
	sort(nums.begin(), nums.end());
    while(left<right){
		mid = (left+right)/2;
        sum = get_Sum(nums, mid);
        if(sum>threshold)
            left = mid + 1;
        else
            right = mid;
	}
	return left;
}

int main()
{
	 vector<int> nums = {19};
	 int threshold = 5;
	 std::cout<<smallestDivisor(nums, threshold);
}
