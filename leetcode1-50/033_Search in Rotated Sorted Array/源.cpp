#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
	int	BinarySearch(vector<int>& nums, int target, int low, int high)
	{
		int mid = (low + high) / 2;
		if (target == nums[mid])
			return mid;
		if (low<=high&&nums[low] <= nums[high])
		{
			 if (nums[mid] < target)
			 return BinarySearch(nums, target, mid + 1, high);
			 else
			 return	BinarySearch(nums, target, low, mid - 1);
		}
		if (low <= high&&nums[low] > nums[high])
		{
			int res1 = BinarySearch(nums, target, low, mid - 1);
			int res2 = BinarySearch(nums, target, mid + 1, high);
			return res1 == -1 ? res2 : res1;
		}
		return -1;
	}
	int search(vector<int>& nums, int target) {
	return	BinarySearch(nums, target, 0, nums.size()-1);
	}
};
int main()
{
	Solution s;
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(3);
	int res = s.search(ivec, 3);
	return 0;
}