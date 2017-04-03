#include<vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		else if (n==2)
		{
			return 2;
		}
		else
		{
			vector<int> res;
			res.push_back(1);
			res.push_back(2);
			for (int i = 2; i < n; i++)
			{
				int temp= res[i - 1] + res[i - 2];
				res.push_back(temp);
			}
			return res[n - 1];
		}
	}
};

int main()
{
	Solution s;
int res=s.climbStairs(3);
	return 0;
}