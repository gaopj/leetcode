class Solution {
public:
	int mySqrt(int x) {

		unsigned long long res = 0;
		unsigned long long now = res*res;
		unsigned long long low = 0;
		unsigned long long high = (x+1)/2;
		unsigned long long mid;
		unsigned long long temp;
		while (low<=high)
		{
			mid = (low + high) / 2;
				temp = mid*mid;

				if (temp == x)
					return mid;
				else if (temp < x)
					low = mid + 1;
				else
					high = mid - 1;
		}
		return high;
	}
};

int main()
{
	Solution s;
	double s0 = 289398 * 289398;
	int res=s.mySqrt(1);

	return 0;
}