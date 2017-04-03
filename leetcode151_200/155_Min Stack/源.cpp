#include<vector>
#include<limits.h>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	vector<long long> stk;
	long long  min;
	MinStack() {
		min =INT_MAX;
	}
	void push(int x) {
		stk.push_back(x);
		if (min > x)
			min = x;
	}

	void pop() {
		stk.pop_back();
		min = findmin(stk);
	}

	int top() {
		return stk[stk.size() - 1];
	}

	int getMin() {
		return min;
	}

	private: int findmin(vector<long long> nums)
	{
				 long long min1 = INT_MAX;
				 for (size_t i = 0; i < nums.size(); i++)
				 {
					 min1 = (min1>nums[i] ? nums[i] : min1);
				 }
				 return min1;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/