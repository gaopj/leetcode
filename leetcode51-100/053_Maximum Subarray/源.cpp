#include<vector>

using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = nums[0];
		int now = nums[0];
		int i = 1;
		for (; i < nums.size(); i++)
		{
			if (now < 0)
			{
				now = nums[i];
				if (now>max)
					max = now;
			}
			else
			{
				now += nums[i];
				if (now>max)
					max = now;
			}
		}
		return max;
	}
};