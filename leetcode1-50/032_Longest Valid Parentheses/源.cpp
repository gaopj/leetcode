#include<stdlib.h>
#include<string>

using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2)
			return 0;
		int *dp=new int[s.size()];
	//	int dp[100];
		int max = 0;
		for (size_t i = 0; i < s.size()-1; i++)
		{
			dp[i] = 0;
		}
		dp[s.size() - 1] = 0;
		for (int i = s.size()-2; i >=0; i--)
		{
			if (s[i] == '(')
			{
				int j = dp[i + 1] + i + 1;
				if (j < s.size()  && s[j] == ')')
				{
					dp[i] = dp[i + 1] + 2;
					if (j + 1 < s.size() )
					dp[i] += dp[j + 1];
					if (dp[i] > max)
						max = dp[i];
				}
			}
		}
		return max;
	}
};
int main()
{
	Solution s;
	s.longestValidParentheses("()");
	return 0;
}