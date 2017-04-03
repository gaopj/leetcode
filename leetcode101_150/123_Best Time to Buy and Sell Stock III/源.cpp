#include<vector>
#include<cmath>
using namespace std;

//class Solution {
//public:
//	int maxProfit(vector<int>& prices, int star, int end) {
//		if (star>=end)
//			return 0;
//		int min = prices[star];
//		int res = 0;
//		for (size_t i = star + 1; i <= end; i++)
//		{
//			int lirun = prices[i] - min;
//			if (lirun > res)
//				res = lirun;
//			if (min > prices[i])
//				min = prices[i];
//		}
//		return res;
//	}
//
//	int maxProfit(vector<int>& prices) {
//		if (prices.size() < 2)
//			return 0;
//		vector<int> premax(prices.size(), 0);
//		vector<int> postmax(prices.size(), 0);
//		for (size_t i = 0; i < prices.size(); i++)
//		{
//			premax[i] = maxProfit(prices, 0, i);
//			postmax[i] = maxProfit(prices, i+1, prices.size()-1);
//		}
//		int res = 0;
//		for (size_t i = 0; i < prices.size(); i++)
//		{
//			if (res < premax[i] + postmax[i])
//				res = premax[i] + postmax[i];
//		}
//		return res;
//	}
//};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		vector<int> local(3, 0);
		vector<int> global(3, 0);
		for (size_t i = 0; i < prices.size()-1; i++)
		{
			int diff = prices[i + 1] - prices[i];
			for (int j = 2; j >=1; j--)
			{
				int l1 = global[j - 1] + (diff>0 ? diff : 0);
				int l2 = local[j] + diff;
				local[j] = (l1 > l2 ? l1 : l2);
				int g1 = local[j];
				int g2 = global[j];
				global[j] = (g1 > g2 ? g1 : g2);
			}
		}
		return global[2];
	}
};
int main()
{
	vector<int> s0;
	s0.push_back(1);
	s0.push_back(2);
	s0.push_back(4);
	s0.push_back(2);
	s0.push_back(5);
	s0.push_back(7);
	s0.push_back(2);
	s0.push_back(4);
	s0.push_back(9);
	s0.push_back(0);
	Solution s;
	int res = s.maxProfit(s0);
	return 0;
}