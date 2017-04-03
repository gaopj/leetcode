#include<vector>
#include<cmath>
using namespace std;
#define MAX(x,y)  ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)<(y)?(x):(y))

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		if (nums.size() == 2)
			return abs(nums[1] - nums[0]);
		int minnum = nums[0];
		int maxnum = nums[0];
		for (size_t i = 0; i < nums.size(); i++)
		{
			maxnum = MAX(maxnum, nums[i]);
			minnum = MIN(minnum, nums[i]);
		}

		int len = (maxnum - minnum) / nums.size() + 1;
		vector<vector<int> > bukets((maxnum - minnum) / len + 1);
		for (size_t x = 0; x < nums.size(); x++)
		{
			int i = (nums[x] - minnum) / len;
			if (bukets[i].empty())
			{
				bukets[i].push_back(nums[x]);
				bukets[i].push_back(nums[x]);
			}
			else
			{
				bukets[i][0] = MIN(bukets[i][0], nums[x]);
				bukets[i][1] = MAX(bukets[i][1], nums[x]);
			}
		}
		int res = 0;
		int prev = 0;
		for (size_t i = 1; i < bukets.size(); i++)
		{
			if (bukets[i].empty())continue;
			res = MAX(res, (bukets[i][0] - bukets[prev][1]));
			prev = i;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	s.maximumGap(nums);
	return 0;
}