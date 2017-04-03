#include<vector>

using namespace std;
class Solution {
public:

	int numTrees(int n) {
		if (n < 0)
			return 0;
		vector<int> temp(n + 1, 0);
		temp[0] = 1;
		temp[1] = 1;
		for (size_t i = 2; i <=n; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
					temp[i] += temp[j] * temp[i - j - 1];
			}
		}
		return temp[n];
	}
};