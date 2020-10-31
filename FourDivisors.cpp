#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include <bits/stdc++.h>

using std::vector;

int find_divisors(int);

int sumFourDivisors(vector<int>& nums) {

        int sum = 0;
        for(auto a:nums)
        {
            sum+=find_divisors(a);
			std::cout<<a<<" : "<<sum<<std::endl;
        }
        return sum;
    }

int find_divisors(int num)
    {
        int count = 0;
        int sum = 1 + num;
        int sq_num = sqrt(num);
        if (num/float(sq_num) == sq_num)
        {
            count--;
            sum-=sq_num;
        }

        for(int i = 2; i <= sq_num; i++)
		{
			if(num%i == 0)
            {
                count+=2;
                sum+=i;
                sum+=(num/i);
            }
            if (count > 2)
                return 0;
		}

        if (count < 2)
            return 0;
        return sum;
    }

	int main()
	{
	    vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
	    vector<int> b{1,2,3,4,5,6,7,8,9,10};
	    std::cout<<sumFourDivisors(b);
	}
