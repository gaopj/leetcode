#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1 == "")
			return word2.size();
		if (word2 == "")
			return word1.size();
		vector<vector<int> > C;
		vector<int> C1;
		for (size_t i = 0; i <= word2.size(); i++)
		{
			C1.push_back(-1);
		}
		for (size_t i = 0; i <= word1.size(); i++)
		{
			C.push_back(C1);
		}
		for (size_t i = 0; i <= word2.size(); i++)
		{
			C[0][i] = i;
		}
		for (size_t i = 0; i <= word1.size(); i++)
		{
			C[i][0] = i;
		}
		for (size_t i = 1; i <= word1.size(); i++)
		{
			for (size_t j = 1; j <= word2.size(); j++)
			{
				int shanchu = -1, charu = -1, tihuanorbudong=-1;
				shanchu = C[i - 1][j] + 1;
				charu = C[i][j - 1] + 1;
				if (word1[i - 1] == word2[j-1])
					tihuanorbudong = C[i - 1][j - 1];
				else
					tihuanorbudong = C[i - 1][j - 1]+1;
				int min = shanchu;
				if (min>charu)
					min = charu;
				if (min>tihuanorbudong)
					min = tihuanorbudong;
				C[i][j] = min;
			}
		}
		return C[word1.size()][word2.size()];
	}
};