#include <iostream>
#include <vector>
#include <unordered_map>
#include <typeinfo>


using std::pair;
using std::unordered_map;
using std::vector;


bool checkIfExist(vector<int>& arr) {
        unordered_map<int, bool> hash;
        for(auto a:arr){
            if(hash[2*a] || (a%2 == 0 && hash[a/2]))
                return true;
            else
				hash.insert(pair<int,bool>(a, true));
        }
        return false;


    }

int main()
{
	vector<int> Aa = {0,0};
	std::cout<<checkIfExist(Aa);
}
