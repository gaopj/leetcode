#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
	int qian(string &s, int &pos)
	{
		int count = 0;
		for (; s[pos] == 'M'; pos++)
		{
			count++;
		}
		return count * 1000;
	}
	int bai(string &s, int &pos)
	{
		int count = 0;
		if (pos >= s.size() || (s[pos] != 'C'&&s[pos] != 'D'))
			return 0;
		else if (s[pos] == 'C')
		{
			count = 100;
			pos++;
			while (pos<s.size() && (s[pos] == 'C' || s[pos] == 'D' || s[pos] == 'M'))
			{
				if (s[pos] == 'C')
				{
					count += 100; pos++;
				}
				else if (s[pos] == 'D')
				{
					count = 400;
					pos++; break;
				}
				else
				{
					count = 900; pos++; break;
				}
			}
		}
		else if (s[pos] == 'D')
		{
			count = 500;
			pos++;
			while (pos<s.size() && s[pos] == 'C')
			{
				count += 100;
				pos++;
			}
		}
		return count;
	}

	int shi(string &s, int &pos)
	{
		int count = 0;
		if (pos >= s.size() || (s[pos] != 'X'&&s[pos] != 'L'))
			return 0;
		else if (s[pos] == 'X')
		{
			count = 10;
			pos++;
			while (pos<s.size() && (s[pos] == 'X' || s[pos] == 'L' || s[pos] == 'C'))
			{
				if (s[pos] == 'X')
				{
					count += 10; pos++;
				}
				else if (s[pos] == 'L')
				{
					count = 40;
					pos++; break;
				}
				else
				{
					count = 90; pos++; break;
				}
			}
		}
		else if (s[pos] == 'L')
		{
			count = 50;
			pos++;
			while (pos<s.size() && s[pos] == 'X')
			{
				count += 10;
				pos++;
			}
		}
		return count;
	}
	int ge(string &s, int &pos)
	{
		int count = 0;
		if (pos >= s.size() || (s[pos] != 'I'&&s[pos] != 'V'))
			return 0;
		else if (s[pos] == 'I')
		{
			count = 1;
			pos++;
			while (pos<s.size() && (s[pos] == 'I' || s[pos] == 'V' || s[pos] == 'X'))
			{
				if (s[pos] == 'I')
				{
					count += 1; pos++;
				}
				else if (s[pos] == 'V')
				{
					count = 4;
					pos++; break;
				}
				else
				{
					count = 9; pos++; break;
				}
			}
		}
		else if (s[pos] == 'V')
		{
			count = 5;
			pos++;
			while (pos<s.size() && s[pos] == 'I')
			{
				count += 1;
				pos++;
			}
		}
		return count;
	}
	int romanToInt(string s) {
		int res = 0;
		int pos = 0;
		res += qian(s, pos);
		res += bai(s, pos);
		res += shi(s, pos);
		res += ge(s, pos);
		return res;
	}
};

int main()
{
	string s0="MCMXCVI";
	Solution s;
	int re = s.romanToInt(s0);
	return 0;
}