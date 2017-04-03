#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty() || nums.size()== 0)
			return false;
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums[m] == target)
				return true;
			if (nums[m]>nums[l])
			{
				if (nums[m]>target && nums[l] <= target)
				{
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}
			else if (nums[m]<nums[l])
			{
				if (nums[m]<target && nums[r] >= target)
				{
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}
			else
			{
				l++;
			}
		}
		return false;
	}
};