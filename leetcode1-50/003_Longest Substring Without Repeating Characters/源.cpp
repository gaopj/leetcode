#include<stdlib.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxcout = 0, pos = 0,count=0;
		map<char, int> cmap;
		for (size_t i = 0; i < s.size(); i++)
		{
				if (cmap.count(s[i]) == 0||cmap.find(s[i])->second<pos)
				{
					cmap[s[i]] = i;
					count = i - pos+1;
					if (count > maxcout)
						maxcout = count;
				}
				else
				{

					pos = cmap[s[i]]+1;
					count = i - pos+1;
					cmap[s[i]] = i;
				}
		}
		return maxcout;
	}
};
int main()
{
	Solution s;
string	s1 = "abcabcbb";
	//string	s1 = "c";
	s.lengthOfLongestSubstring(s1);
	return 0;
}