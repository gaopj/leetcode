#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums,int target,int end) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		if (nums.size()<3)
			return res;
		vector<int> &mset = nums;
		multiset<int> mmset;
		for (size_t i = 0; i < end; i++)
		{
			mmset.insert(nums[i]);
		}
		vector<int>::iterator pi = mset.begin();
		int last = -999999;
		for (size_t i = 0; i <end - 2; i++, pi++)
		{
			if (last == mset[i])
				continue;
			int l = mset[i];
			last = mset[i];
			vector<int>::iterator pj = nums.begin();
			for (size_t i = 0; i < end; i++)
			{
				pj++;
			}
			pj--;
			int lastr = -999999;
			for (size_t j = end - 1; j >i + 1; j--, pj--)
			{
				if (lastr == mset[j])
					continue;
				lastr = mset[j];
				if (target-(l + mset[j]) < l ||target -(l + mset[j]) > mset[j])
					continue;
				else
				{
					vector<int>::iterator m = find(pi + 1, pj,target -(l + mset[j]));
					if (m != pj)
					{
						vector<int> k;
						k.push_back(l);
						k.push_back(*m);
						k.push_back(*pj);
						res.push_back(k);
					}
				}
			}
		}
		return res;
	}
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());
		int pre = -99999;
		for (int i = nums.size()-1; i >=3; i--)
		{
			if (pre == nums[i])
				continue;
			vector<vector<int> > res3 = threeSum(nums, target - nums[i],i);
			if (res3.empty())
				continue;
			else
			{
				for (size_t j = 0; j < res3.size(); j++)
				{
					res3[j].push_back(nums[i]);
					res.push_back(res3[j]);
				}
			}
			pre = nums[i];
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(5);
	s0.push_back(5);
	s0.push_back(3);
	s0.push_back(1);
	s0.push_back(-5);
	s0.push_back(1);
	s0.push_back(-2);
	//s0.push_back(5);
	vector<vector<int>> res = s.fourSum(s0, 4);
	return 0;
}