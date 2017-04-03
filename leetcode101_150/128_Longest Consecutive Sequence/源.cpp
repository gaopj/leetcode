#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int> snums;
		int res = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			snums.insert(nums[i]);
		}
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (!snums.count(nums[i]))
				continue;
			else
			{
				int jian = 0;
				int jiannum = nums[i]-1;
				while (snums.count(jiannum))
				{
					snums.erase(jiannum);
					jian++;
					jiannum--;
				}
				int jia = 0;
				int jianum = nums[i]+1;
				while (snums.count(jianum))
				{
					snums.erase(jianum);
					jia++;
					jianum++;
				}
				if (jia + jian + 1 > res)
					res = jia + jian + 1;
			}
		}
		return res;
	}
};