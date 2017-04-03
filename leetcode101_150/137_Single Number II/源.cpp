#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() < 2)
			return nums[0];
		sort(nums.begin(), nums.end());
		int pre = nums[0];
		//int res = nums[0];
		for (int i = 0; i < nums.size(); i+=3)
		{
			if (i + 1 >nums.size())
				return nums[i];
			if (nums[i] != nums[i + 1])
				return nums[i];
		}
		return 0;
	}
};