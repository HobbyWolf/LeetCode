#include<iostream>
#include<string>

using std::string;

string generateTheString(int n) {
	return string((n-1), 'a') + string(n%2, 'a') + string((n-1)%2, 'b');

}

int main()
{
	std::cout<<generateTheString(5);
}
