class Solution {
public:
	int uniquePaths(int m, int n) {
		int big = m + n - 2;
		int small = m > n ? n - 1 : m - 1;
		int res = 0;
		long long  fenzi = 1;
		long long fenmu = 1;
		for (int i = 0,shu=big; i <small; i++,shu--)
		{
			fenzi *= shu;
		}
		for (int i = 1; i <=small; i++)
		{
			fenmu *= i;
		}
		res = fenzi / fenmu;
		return res;
	}
};

int main()
{
	Solution s;
	int res =s.uniquePaths(10, 10);
	return 0;
}