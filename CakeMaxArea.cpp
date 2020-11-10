
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::vector;
using std::min;

int getMaxLen(vector<int>& A, int& len){
	A.push_back(0);
    A.push_back(len);
    sort(A.begin(), A.end());
    long long int max = 0;
    for(unsigned int i = 0; i < A.size() - 1; i++)
        max = (max < A[i+1] - A[i])?A[i+1] - A[i]:max;

return max;
}

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int maxH = getMaxLen(horizontalCuts, h);
        long long int maxV = getMaxLen(verticalCuts, w);
        return (maxH*maxV)%(1000000007);
    }

int main()
{

}
