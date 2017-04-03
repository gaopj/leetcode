#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		int ps = 0;
		int res = 0;
		int p = 1;
		while (p<prices.size()&&prices[p]<prices[p-1])
		{
			p++;
		}
		ps = p - 1;
		for (; p<prices.size(); p++)
		{
			if (prices[p]>prices[p - 1])
				continue;
			else
			{
				res += prices[p - 1] - prices[ps];
				ps = p;
			}
		}
		if (p - 1 > ps)
			res += prices[p - 1] - prices[ps];
		return res;	
	}
};