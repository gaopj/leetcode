#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
	void find(vector<int>&nums, int target, vector<int>&res, int low, int high)
	{
		if (low > high)
			return;
		int mid = (low + high) / 2;
		if (nums[mid] == target)
		{
			if (res[0] == -1)
			{
				res[0] = mid; res[1] = mid;
			}
			else
			{
				if (mid < res[0])
					res[0] = mid;
				else if (mid>res[1])
					res[1] = mid;
			}
		}
		find(nums, target, res, low, mid - 1);
		find(nums, target, res, mid+1, high);
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		res.push_back(-1);
		res.push_back(-1);
		find(nums, target, res, 0, nums.size()-1);
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(5);
	s0.push_back(7);
	s0.push_back(7);
	s0.push_back(8);
	s0.push_back(8);
	s0.push_back(10);
	vector<int >res=s.searchRange(s0, 8);
	return 0;
}