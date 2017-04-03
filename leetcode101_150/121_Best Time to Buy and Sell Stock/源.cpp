#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int min = prices[0];
		int res = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			int lirun = prices[i] - min;
			if (lirun>res)
				res = lirun;
			if (min > prices[i])
				min = prices[i];
		}
		return res;
	}
};