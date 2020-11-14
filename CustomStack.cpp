#include <iostream>
#include <vector>

using std::vector;

class CustomStack {
    private:
    vector<int> stack;
    size_t sz;
    public:
    CustomStack(int maxSize) {
        sz = maxSize;
    }

    void push(int x) {
        if(stack.size() < sz)
            stack.push_back(x);
    }

    int pop() {
		int i = stack.size();
		if(i == 0) return -1;
        int b = *stack.rbegin();
        stack.erase(--stack.end());
        return b;
    }

    void increment(int k, int val) {
        for(int i = 0; i < k && i < stack.size(); i++)
            stack[i]+=val;
    }
};

int main()
{
	CustomStack* obj = new CustomStack(4);
	obj->push(3);
	obj->push(4);
	obj->push(5);
	std::cout<<obj->pop();
	obj->increment(3, 100);
	std::cout<<obj->pop();
}
