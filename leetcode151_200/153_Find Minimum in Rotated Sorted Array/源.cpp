#include<vector>
using namespace std;
#define MIN(x,y)  ((x)<(y)?(x):(y))
class Solution {
public:
	int res = 99999;
	void findMingpj(vector<int>& nums, int s, int e)
	{
		if (s>e)
			return;
		else if (s == e)
		{
			if (nums[s] < res)
				res = nums[s];
		}
		else if (e - 1 == s)
			res = MIN(MIN(nums[s],nums[e]),res);
		else
		{
			int mid = (s + e) / 2;
			if (nums[mid] < res)
				res = nums[mid];
			if (nums[mid]>nums[e])
				findMingpj(nums, mid + 1, e);
			else
				findMingpj(nums,s, mid-1);	
		}
		
	}
	int findMin(vector<int>& nums) {
		if (nums.size() < 1)
			return -1;
		if (nums.size() == 1)
			return nums[0];
		findMingpj(nums, 0, nums.size() - 1);
		return res;
	}
};