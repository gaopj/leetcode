#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>;
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		if (nums.size()<3)
			return res;
		vector<int> &mset = nums;
		multiset<int> mmset;
		for (size_t i = 0; i < nums.size(); i++)
		{
			mmset.insert(nums[i]);
		}
		vector<int>::iterator pi = mset.begin();
		int last = -999999;
		for (size_t i = 0; i < mset.size()-2; i++,pi++)
		{
			if (last == mset[i])
				continue;
			int l = mset[i];
			last = mset[i];
			vector<int>::iterator pj = mset.end();
			pj--;
			int lastr = -999999;
			for (size_t j = mset.size()-1; j >i+1; j--,pj--)
			{
				if (lastr == mset[j])
					continue;
				lastr = mset[j];
				if (-(l + mset[j]) < l || -(l + mset[j]) > mset[j])
					continue;
				else
				{
					vector<int>::iterator m = find(pi+1, pj, -(l + mset[j]));
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
};

int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(3);
	s0.push_back(0);
	s0.push_back(-2);
	s0.push_back(-1);
	s0.push_back(1);
	s0.push_back(2);
	s.threeSum(s0);
	return 0;
}