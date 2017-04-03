#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<int> dp0(s.size(), 0);
		vector<vector<int> > dp(s.size(), dp0);
		vector<vector<string>> res;
		vector<string> res0;
		for (size_t i = 0; i < s.size(); i++)
		{
			for (size_t j = i; j < s.size(); j++)
			{
				int k = 0;
				for (;k < (j-i+1)/2; k++)
				{
					if (s[i + k] != s[j - k])break;
				}
				if (k == (j - i + 1) / 2)
					dp[i][j] = 1;
			}
		}
		dfs(0, s, dp, res, res0);
		return res;
	}
	void dfs(int i, string &s, vector<vector<int> >&dp, vector<vector<string>>&res, vector<string> &res0)
	{
		if (i == s.size())
		{
			res.push_back(res0);
			return;
		}
		for (size_t j = i; j < s.size(); j++)
		{
			if (dp[i][j] == 1)
			{
				res0.push_back(s.substr(i, j - i + 1));
				dfs(j + 1, s, dp, res, res0);
				res0.pop_back();
			}
		}
	}
};