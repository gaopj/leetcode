#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int res = 0;
		while (l<r)
		{
			res = max(res, min(height[l], height[r])*(r - l));
			if (height[l] <= height[r])
			{
				int k = l;
				while (k < r&&height[k] <= height[l])
					k++;
				l = k;
			}
			else 
			{
				int k = r;
				while (k >l&&height[r] >= height[k])
					k--;
				r = k;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> i;
	i.push_back(2);
	i.push_back(3);
	i.push_back(10);
	i.push_back(5);
	i.push_back(7);
	i.push_back(8);
	i.push_back(9);
	//i.push_back(8);
	//i.push_back(9);
	//i.push_back(10);
	Solution s;
	int res=s.maxArea(i);
	return 0;
}
