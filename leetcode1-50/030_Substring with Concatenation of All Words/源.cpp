#include<stdlib.h>
#include<string>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		map<string, int> simap;
		map<string, int> cur;
		int word_len = words[0].length();
		int word_nums = words.size();
		vector<int> res;
		for (size_t i = 0; i < words.size(); i++)
		{
			if (simap.count(words[i]) == 0)
				simap[words[i]] = 1;
			else
				simap[words[i]]++;
		}
		int size = s.size() - word_len*word_nums;
		for (int i = 0; i <=size; i++)
		{
			cur.clear();
			int j = 0;
			for (; j < word_nums; j++)
			{
				string s0 = s.substr(i + j*word_len, word_len);
				if (simap.count(s0) == 0)
					break;
				else
				{
					if (cur.count(s0) == 0)
						cur[s0] = 1;
					else
					{
						cur[s0]++;
						if (cur[s0]>simap[s0])
							break;
					}
				}
			}
			if (j == word_nums)
				res.push_back(i);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> s0;
	s0.push_back("a");
	s0.push_back("a");
	vector<int> res = s.findSubstring("a", s0);
	return 0;
}