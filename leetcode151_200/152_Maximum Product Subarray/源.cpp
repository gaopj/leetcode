#include<vector>
using namespace std;

#define MAX(x,y)  ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)<(y)?(x):(y))
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int max_local = nums[0];
		int min_local = nums[0];

		int max = nums[0];
		for (size_t i = 1; i < nums.size(); i++)
		{
			int temp = max_local;
			max_local = MAX(MAX(nums[i] * max_local, nums[i]), nums[i] * min_local);
			min_local = MIN(MIN(temp*nums[i], nums[i]), nums[i] * min_local);
			max = MAX(max, max_local);
		}
		return max;
	}
};