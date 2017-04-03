#include<string>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		bool poitflag = false, eflag = false, preflag = false,nextflag=false,ppreflag=false,pnextflag=false,kongflag=false,numflag=false,fuhaoflag=false;
		int i = 0;
		for (; i < s.size(); i++)
		{
			if (s[i] != ' ')
				break;
		}
		int start = i;
		for (; i < s.size(); i++)
		{
			if (s[i] == '-'||s[i]=='+')
			{
				fuhaoflag = true;
				if (i == start)
					continue;
				else if (s[i - 1] == 'e')
					continue;
				else
					return false;
			}
			else if (s[i] == ' ')
			{
				break;
			}
			else if (s[i] == '.')
			{
				if (poitflag||eflag)
					return false;
				else
					poitflag = true;
			}
			else if (s[i] == 'e')
			{
				if (eflag)
					return false;
				else if (!preflag)
					return false;
				else
					eflag = true;
			}
			else if (s[i] >= '0'&&s[i] <= '9')
			{
				if (!numflag)
					numflag = true;
				if (!preflag)
					preflag = true;
				if (poitflag)
					pnextflag = true;
				if (eflag)
					nextflag = true;
			}
			else
				return false;
		}

		for (i++; i < s.size(); i++)
		{
			if (s[i] != ' ')
				return false;
		}
		if (eflag&&!nextflag)
			return false;
		if (!numflag)
			return false;
		return true;
	}
};

int main()
{
	Solution s;
	bool res = s.isNumber(" -54.53061");
	return 0;
}