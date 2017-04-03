#include<string>
#include<queue>
#include <hash_set>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		queue<string> Q;
		Q.push(beginWord); Q.push("");
		int res = 1;
		while (Q.empty() == false)
		{
			string str = Q.front();
			Q.pop();
			if (str != "")
			{
				int strLen = str.length();
				for (int i = 0; i < strLen; i++)
				{
					char tmp = str[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (c == tmp)continue;
						str[i] = c;
						if (str == endWord)return res + 1;
						if (wordList.find(str) != wordList.end())
						{
							Q.push(str);
							wordList.erase(str);
						}
					}
					str[i] = tmp;
				}
			}
			else if (Q.empty() == false)
			{//到达当前层的结尾，并且不是最后一层的结尾
				res++;
				Q.push("");
			}
		}
		return 0;

	}
};