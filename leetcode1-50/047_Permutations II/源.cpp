#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void prem(vector<int> &num, int i, vector<vector<int> > &res)
	{
		if (i == num.size())
			res.push_back(num);
		else
		{
			vector<int>::iterator it = num.begin() + i;
			sort(it, num.end());
			int pre = num[i];
			int mon = num[i];
			for (int j = i; j < num.size(); j++)
			{
				if ((i != j) && mon == num[j])
					continue;
				if ((i != j)&&pre==num[j])
					continue;
				pre = num[j];
				swap(num[i], num[j]);
				prem(num, i + 1, res);
				vector<int>::iterator it = num.begin() + i;
				sort(it, num.end());
				//swap(num[j], num[i]);
			}
		}

	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		prem(nums,0, res);
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> ivec;
	ivec.push_back(0);
	ivec.push_back(3);
	ivec.push_back(2);
	ivec.push_back(1);
	ivec.push_back(1);
	ivec.push_back(1);

	s.permuteUnique(ivec);
	return 0;
}