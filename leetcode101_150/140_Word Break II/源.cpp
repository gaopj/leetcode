#include<string>
#include<unordered_set>
#include<set>
using namespace std;

class Solution {
public:
	vector<string> res;

	bool wordBreakHelper(string s, unordered_set<string> &dict, set<string> &unmatch, int mn, int mx) {
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

	void wordBreakHelper(string s, unordered_set<string> &dict, int mn, int mx, string ress) {
		if (s.length() < 1)
		{
			res.push_back(ress);
			return ;
		}
		int max = mx < s.length() ? mx : s.length();
		for (int i = mn; i <= max; i++)
		{
			string prefixstr = s.substr(0, i);
			if (dict.find(prefixstr) != dict.end())
			{
				string suffixstr = s.substr(i);

				if (ress == "")
					ress += prefixstr;
				else
				{
					ress += " " + prefixstr;
				}
				wordBreakHelper(suffixstr, dict, mn, mx, ress);
				int len = ress.size() - prefixstr.size() - 1;
				if (len>=0)
					ress = ress.substr(0, ress.size() - prefixstr.size() - 1);
				else
				{
					ress = "";
				}
			}
		}
		return ;
	}
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		if (s.length() < 1) return res;
		if (wordDict.empty()) return res;
		unordered_set<string>::iterator it = wordDict.begin();
		int maxlen = (*it).length(), minlen = (*it).length();
		for (it++; it != wordDict.end(); it++)
		if ((*it).length() > maxlen)
			maxlen = (*it).length();
		else if ((*it).length() < minlen)
			minlen = (*it).length();
		string ress = "";
		set<string> unmatched;
		if (wordBreakHelper(s, wordDict, unmatched, minlen, maxlen))
		wordBreakHelper(s, wordDict, minlen, maxlen, ress);
		 return res;
	}
};

int main()
{
	string s0 = "catsanddog";
	unordered_set<string>dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	Solution s;
	vector<string> r = s.wordBreak(s0,dict);
	return 0;
}
