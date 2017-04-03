#include<string>
#include<unordered_set>
#include<set>
using namespace std;

class Solution {
public:
	bool wordBreakHelper(string s, unordered_set<string> &dict, set<string> &unmatch,int mn,int mx) {
		if (s.length() < 1) return true;
		int max = mn < s.length() ? mx : s.length();
		for (int i = mn; i <= max; i++)
		{
			string prefixstr = s.substr(0, i);
			 if (dict.find(prefixstr) != dict.end())
			{
				string suffixstr = s.substr(i);
				if (unmatch.find(suffixstr) != unmatch.end())continue;
				else{
					if (wordBreakHelper(suffixstr, dict, unmatch, mn, mx)) return true;
					else unmatch.insert(suffixstr);
				}
			}
		}
		return false;
	}
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		if (s.length() < 1) return true;
		if (wordDict.empty()) return false;
		unordered_set<string>::iterator it = wordDict.begin();
		int maxlen = (*it).length(), minlen = (*it).length();
		for (it++; it != wordDict.end(); it++)
		if ((*it).length() > maxlen)
			maxlen = (*it).length();
		else if ((*it).length() < minlen)
			minlen = (*it).length();
		set<string> unmatched;
		return wordBreakHelper(s, wordDict, unmatched, minlen, maxlen);
	}
};