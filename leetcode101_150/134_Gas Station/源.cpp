#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.size() != cost.size())return -1;
		if (gas.size() == 0) return -1;
		int max = gas[0] - cost[0];
		int min = gas[0] - cost[0];
		int nowmax = gas[0] - cost[0];
		int nowmin = gas[0] - cost[0];
		int stnowmax = 0;
		int stmax = 0;
		int endMIN = 0;
		int total = 0;
		int diff = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			diff = gas[i] - cost[i];
			total += diff;

			if (nowmax < 0){
				nowmax = diff;
				stnowmax = i;
			}
			else nowmax += diff;
			if (nowmax>max){
				max = nowmax;
				stmax = stnowmax;
			}

			if (nowmin > 0) nowmin = diff;
			else nowmin += diff;
			if (nowmin < min)
			{
				min = nowmin;
				endMIN = i;
			}
		}
		return total < 0 ? -1 : (max >= (total - min) ? stmax : (endMIN + 1) % gas.size());
	}
};