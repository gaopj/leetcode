#include<vector>
using namespace std;
#define MIN(x,y)  ((x)<(y)?(x):(y))
class Solution {
public:

	int findMin(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int l = 0;
		int r = nums.size()-1;

		int min = nums[0];

		while (l<r-1)
		{
			int m = (l + r) / 2;
			if (nums[l] < nums[m])
			{
				min = MIN(nums[l], min);
				l = m + 1;
			}
			else if (nums[l]>nums[m])
			{
				min = MIN(nums[m], min);
				r = m - 1;
			}
			else
			{
				l++;
			}
		}
		min = MIN(nums[r], min);
		min = MIN(nums[l], min);
		return min;
	}
};

int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(1);
	s0.push_back(3);
	s0.push_back(3);
	int res= s.findMin(s0);
	return 0;
}