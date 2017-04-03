#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
	void reverse(vector<int> &nums, int pos, int high)
	{
		while (pos<high)
		{
			int temp = nums[pos];
			nums[pos] = nums[high];
			nums[high] = temp;
			pos++; high--;
		}
	}
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		bool isfind = false;
		int pos = nums.size()-1;
		for (; pos>=1; pos--)
		{
			if (nums[pos - 1] < nums[pos])
			{
				pos--;
				isfind = true;
				break;
			}
		}
		if (isfind)
		{
			int pos1 = nums.size() - 1;
			for (; pos1>=pos; pos1--)
			{
				if (nums[pos1]>nums[pos])
					break;
			}
			int temp = nums[pos1];
			nums[pos1] = nums[pos];
			nums[pos] = temp;
			reverse(nums, pos + 1, nums.size()-1);
		}
		else
		{
			reverse(nums, 0, nums.size()-1);
			return;
		}
	}
};
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(5);
	s.nextPermutation(nums);
	return 0;
}