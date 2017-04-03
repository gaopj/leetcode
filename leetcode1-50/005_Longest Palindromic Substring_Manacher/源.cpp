#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	string preProcess(string s)
	{
		int n = s.size();
		if (n == 0)
			return "^$";
		string res = "^";
		for (size_t i = 0; i < n; i++)
		{
			res =res+ "#" + s[i];
		}
		res =res+"#"+"$";
		return res;
	}
	string longestPalindrome(string s) {

		string t = preProcess(s);
		int size = t.size();
		int *p = new int[size];
		int c = 0, r = 0;
		for (size_t i = 1; i < size-1; i++)
		{
			int i_mirror = c - (i - c);
			int diff = r - i;
			if (diff >= 0)
			{
				if (p[i_mirror] < diff)
					p[i] = p[i_mirror];
				else
				{
					p[i] = diff;
					while (t[i + p[i] + 1] == t[i - p[i] - 1])
						p[i]++;
					c = i;
					r = c + p[c];
				}
			}
			else
			{
				p[i] = 0;
				while (t[i + p[i] + 1] == t[i - p[i] - 1])
					p[i]++;
				c = i;
				r = c + p[c];
			}
		}
		int maxlen = 0;
		int centerIndex =0;
		for (size_t i = 1; i < size-1; i++)
		{
			if (p[i] > maxlen) {
				maxlen = p[i];
				centerIndex = i;
			}
		}
		return s.substr((centerIndex - 1 - maxlen) / 2, maxlen);
	}
};

int main()
{
	string s0 = "babcbabcbaccba";
	Solution s;
	string res = s.longestPalindrome(s0);
	return 0;
}