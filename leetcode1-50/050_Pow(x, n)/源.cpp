#include<cfloat>
#include<limits>
#define DBL_MIN         2.2250738585072014e-308
class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1)
			return 1;
		else if (x==-1)
		{
			if (n % 2)
				return -1;
			else
				return 1;
		}
		int i = 0;
		double res = 1;
		double jie = x;
		if (n == 0)
			return 1;
		else if (n>0)
		{
			while (i<n)
			{
				int count = 2;
				for (; i + count < n; count=count << 1)
				{
					jie *= jie;
					if (jie < DBL_MIN*2)
						return 0;
				}
				count /= 2;
				i += count;
				res *= jie;
				jie = x;
			}
		}
		else
		{
			if (n == INT_MIN)
				return 0;
			double res1 = myPow(x, -n);
			if (res1 != 0)
				res = 1.0 / res1;
			else
			{
				return DBL_MAX;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	double res = s.myPow(34.00515, -3);
	return 0;
}