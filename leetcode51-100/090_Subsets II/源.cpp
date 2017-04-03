#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	int n;
	int k;

	void huishuo(int from, int l, vector<int> &res0, vector<int>& nums)
	{
		if (res0.size() == k)
		{
			vector<int> res00(res0);
			res.push_back(res00);
			return;
		}
		else
		{

			int pre = -99999;
			for (size_t i = from; i < n; i++)
			{
				if (pre == nums[i])
					continue;
				pre = nums[i];
				res0.push_back(nums[i]);
				huishuo(i + 1, l + 1, res0, nums);
				vector<int>::iterator p = res0.begin();
				res0.erase(p + l);
			}
		}
	}

	vector<vector<int>> combine(vector<int>& nums, int k) {
		vector<int>res0;
		this->k = k;
		huishuo(0, 0, res0, nums);
		return res;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		this->n = nums.size();
		sort(nums.begin(), nums.end());
		
		for (size_t i = 0; i <= nums.size(); i++)
		{
			combine(nums, i);
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);

	vector<vector<int>> res=s.subsetsWithDup(nums);
	return 0;
}