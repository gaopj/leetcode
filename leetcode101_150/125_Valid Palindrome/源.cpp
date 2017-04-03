#include<string>
using namespace std;

class Solution {
public:
	bool ishuiwei(string &s, int b, int e)
	{
		if (b >= e)
			return true;
		if (isalphanumeric(s[b])&&isalphanumeric(s[e]))
		{
			if (s[b] == s[e])
				return ishuiwei(s, b + 1, e - 1);
			else
			{
				return false;
			}
		}
		else if (!isalphanumeric(s[b])&&isalphanumeric(s[e]))
			return ishuiwei(s, b + 1, e);
		else if (isalphanumeric(s[b]) && !isalphanumeric(s[e]))
			return ishuiwei(s, b, e-1);
		else
		{
			return ishuiwei(s, b + 1, e - 1);
		}
	}
	bool isalphanumeric(char c)
	{
		if (c >= 'a'&&c <= 'z'&&c >= 'a'&&c <= 'z')
			return true;
		else if (c >= '0'&&c <= '9')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isPalindrome(string s) {
		for (size_t i = 0; i < s.size(); i++)
		{
			s[i] = tolower(s[i]);
		}
		return ishuiwei(s, 0, s.size());
	}
};