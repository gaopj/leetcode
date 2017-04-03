#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int numDistinct(string s, string t) {
		if (s.empty() || t.empty())
			return 0;
		if (s.size() < t.size())
			return 0;
		vector<int> res0(t.size() + 1, 0);
		vector<vector<int> >res(s.size() + 1, res0);
		res[0][0] = 1;
		for (int i = 0; i <= s.size(); i++)
		{
			res[i][0] = 1;
		}
		for (size_t i = 1; i <=s.size(); i++)
		{
			for (size_t j = 1; j <= t.size(); j++)
			{
				res[i][j] = res[i - 1][j];
				if (s[i - 1] == t[j - 1])
					res[i][j] += res[i - 1][j - 1];
			}
		}
		return res[s.size()][t.size()];
	}
};