#include<string>
#include<vector>
using namespace std;

class Solution {
public: int minCut(string s) {
		vector<int> dp0(s.size(), 0);
		vector<vector<int> > dp(s.size(), dp0);
		vector<int> count(s.size() + 1,9999);
		count[s.size()] = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = i; j<s.size(); j++)
			{
				if (s[i] == s[j] && (j - i<2 || dp[i + 1][j - 1] == 1))
				{
					dp[i][j] = 1;
					//count[i] = Math.min(1 + count[j + 1], count[i]);
					count[i] = (1 + count[j + 1]>count[i] ? count[i] : 1 + count[j + 1]);
				}
			}
		}

		return count[0] - 1;
	}
};