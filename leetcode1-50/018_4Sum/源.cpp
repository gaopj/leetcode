#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > res;
		if (nums.size() < 4)
			return res;
		sort(nums.begin(), nums.end());
		int pre1 = -99999;
		for (size_t i1 = 0; i1 < nums.size()-3; i1++)
		{
			//if (nums[i1]>target)
			//	break;
			if (pre1 == nums[i1])
				continue;
			int pre2 = -99999;
			for (size_t i2 = i1+1; i2 < nums.size()-2; i2++)
			{
				//if (nums[i1] + nums[i2] > target)
				//	break;
				if (pre2 == nums[i2])
					continue;
				int 	pre3 = -99999;
				for (size_t i3 = i2+1; i3 < nums.size()-1; i3++)
				{
					//if (nums[i1] + nums[i2] + nums[i3] > target)
					//	break;
					if (pre3 == nums[i3])
						continue;
					int pre4 = -99999;
					for (size_t i4 = i3+1; i4 < nums.size(); i4++)
					{
						//if (nums[i1] + nums[i2] + nums[i3] + nums[i4] > target)
						//	break;
						if (pre4 == nums[i4])
							continue;
						 if(nums[i1] + nums[i2] + nums[i3] + nums[i4] == target)
						{
							vector<int> ivec;
							ivec.push_back(nums[i1]);
							ivec.push_back(nums[i2]);
							ivec.push_back(nums[i3]);
							ivec.push_back(nums[i4]);
							res.push_back(ivec);
						}
						pre4 = nums[i4];
					}
					pre3 = nums[i3];
				}
				pre2 = nums[i2];
			}
			pre1 = nums[i1];
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(1);
	s0.push_back(-2);
	s0.push_back(-5);
	s0.push_back(-4);
	s0.push_back(-3);
	s0.push_back(3);
	s0.push_back(3);
	s0.push_back(5);
	vector<vector<int>> res=	s.fourSum(s0, -11);
	return 0;
}