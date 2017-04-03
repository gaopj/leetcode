#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void prem(vector<int> &num, int i,vector<vector<int> > &res)
	{
		if (i == num.size())
			res.push_back(num);
		else
		{
			for (size_t j = i; j < num.size(); j++)
			{
				swap(num[i], num[j]);
				prem(num, i + 1, res);
				swap(num[j], num[i]);
			}
		}

	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		prem(nums,0,res);
		return res;

	}
};
int main()
{

	return 0;
}