#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		heights.push_back(0);
		int resmax = 0;
		for (size_t i = 0; i < heights.size(); i++)
		{
			if (s.empty() || heights[i]>heights[s.top()])
				s.push(i);
			else
			{
				int temp = s.top();
				s.pop();
				int newsize = heights[temp] * (s.empty() ? i : i - s.top() - 1);
				resmax = newsize > resmax ? newsize : resmax;
				i--;
			}
		}
		return resmax;
	}
};