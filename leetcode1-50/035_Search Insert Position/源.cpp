#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
	int binary(vector<int> &nums, int target,int low,int high)
	{
		if (low > high)
			return low;
		else
		{
			int mid = (low + high);
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				return binary(nums, target, low, mid - 1);
			else
				return binary(nums, target, mid + 1, high);
		}
	}
	int searchInsert(vector<int>& nums, int target) {
		return binary(nums, target, 0, nums.size() - 1);
	}
};
int main()
{

	return 0;
}