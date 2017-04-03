#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
	int find(vector<int> &ivec, int begin, int end,int x,bool & isfind)
	{
		int index = begin;
		for (; index<=end ;)
		{
			if (x>ivec[index])
				index++;
			else if (x == ivec[index])
			{
				isfind = true;
				return index;
			}
			else
			{
				isfind = false;
				return (ivec[index] - x > x - ivec[index - 1]) ? (index - 1) : index;
			}
		}
		return index-1;
	}
	int threeSumClosest(vector<int>& nums, int target) {
		int res = -999999;
		sort(nums.begin(), nums.end());
		bool isfind = false;
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = nums.size()-1; j >=i+2; j--)
			{
				int index = find(nums, i+1, j-1, target - nums[i] - nums[j], isfind);
				if (index == i)
					index++;
				if (isfind) return target;
				if (abs(res - target)>abs(nums[i] + nums[j] + nums[index] - target))
					res = nums[i] + nums[j] + nums[index];
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(-3);
	s0.push_back(-2);
	s0.push_back(-5);
	s0.push_back(3);
	s0.push_back(-4);
	int res = s.threeSumClosest(s0, -1);
	return 0;
}