#include<stdlib.h>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long diend = dividend;
		long long dieor = divisor;
		int flag1 = 1, flag2 = 1, flag = 1;
		if (dividend < 0)
		{
			diend = -diend;
			flag1 = -1;
		}
		if (divisor < 0)
		{
			dieor = -dieor;
			flag2 = -1;
		}
		else if (divisor == 0)
			return 0;
		flag = flag1*flag2;
		long long res = 0;
		while (diend>=dieor)
		{
			long long count = 1;
			long long sum = dieor;
			while (sum+sum<=diend)
			{
				count += count;
				sum += sum;
			}
			diend -= sum;
			res += count;
		}
		if (res*flag > 2147483647)
			return 2147483647;
		else return res*flag;
	}
};
int main()
{
	Solution s;
	int res = s.divide(-2147483648, -1);
	return 0;
}