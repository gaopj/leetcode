#include<stdlib.h>
#include<iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		string maxs;
		for (size_t i = 0; i < 2*s.size()-1; i++)
		{
			if (i % 2)
			{
				string nows;
				int low = i / 2;
				int high = i / 2 + 1;
				while (low>=0&&high<s.size()&&s[low]==s[high])
				{
					nows = s[low] + nows + s[high];
					low--;
					high++;
				}
				if (maxs.size() < nows.size())
					maxs = nows;
			}
			else
			{
				string nows;
				nows = s[i / 2];
				int low = i / 2 - 1;
				int high = i / 2 + 1;
				while (low >= 0 && high<s.size() && s[low] == s[high])
				{
					nows = s[low] + nows + s[high];
					low--;
					high++;
				}
				if (maxs.size() < nows.size())
					maxs = nows;
			}
		}
		return maxs;
	}
};

int main()
{
	string s = "bb";
	Solution a;
	a.longestPalindrome(s);
	return 0;
}