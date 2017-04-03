#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> generate(int numRows) {
		if (numRows < 1)
			return res;
		vector<int> res0;
		res0.push_back(1);
		res.push_back(res0);
		if (numRows == 1)
			return res;
		res0.clear();
		res0.push_back(1);
		res0.push_back(1);
		res.push_back(res0);
		for (size_t i = 2; i < numRows; i++)
		{
			vector<int> res0(res[i - 1].size() + 1,1);
			for (size_t j = 1; j < res[i-1].size(); j++)
			{
				res0[j] = res[i - 1][j - 1] + res[i - 1][j];
			}
			res.push_back(res0);
		}
		return res;
	}
};