#include<string>

using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		int poss = 0;
		int posp = 0;
		int presp = -1;
		int press = -1;
		bool startFound = false;
		p += " ";
		while (poss<s.size())
		{
			if (p[posp] == '?'){ poss++; posp++; }
			else if (p[posp]=='*')
			{
				presp = ++posp;
				press = poss;
				startFound = true;
			}
			else
			{
				if (s[poss] == p[posp])
				{
					++posp; ++poss;
				}
				else if (startFound)
				{
					posp = presp;
					poss = (++press);
				}
				else
				{
					return false;
				}
			}
		}
		while (p[posp] == '*')++posp;
		return posp == p.size()-1;
	}
};
int main()
{
	Solution s;
	bool res = s.isMatch("aa", "*");
	return 0;
}