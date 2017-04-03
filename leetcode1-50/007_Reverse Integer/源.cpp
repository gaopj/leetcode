#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		stringstream ss;
		string s, res;
		if (x<0)
		{
			res += '-';
			x = -x;
		}
		ss << x;
		ss >> s;
		ss.clear();
		int pos = s.size() - 1;
		for (; s[pos] == 0; pos--);

		for (; pos >= 0; pos--)
		{
			res += s[pos];
		}
		ss << res;
		double result = 0;
		ss >> result;
		ss.clear();
		if (result > 2147483647)
			return 0;
		if (result < -2147483648)
			return 0;
		return (int)result;
	}
};
int main()
{
	Solution s;
	int a = -2147483648;
	int re = s.reverse(12345);
	return 0;
}