#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {

		if (s.empty())
			return 0;
		if (s[0] == '0')
			return 0;
		 if (s.size()==1)
		{
			return 1;
		}
		vector<int> temp(s.size() + 1,0);
		temp[0] = 1;
		temp[1] = 1;
		for (size_t i = 2; i <= s.size(); i++)
		{
			if (s[i - 1] == '0')
			{
				if (s[i - 2] != '1'&&s[i - 2] != '2')
					return 0;
				else
					temp[i] = temp[i - 2];
			}
			else
			{
				if (s[i - 2] == '1')
					temp[i] = temp[i - 1] + temp[i - 2];
				else if (s[i - 2] == '2')
				{
					if (s[i - 1] >= '1'&&s[i - 1] <= '6')
						temp[i] = temp[i - 1] + temp[i - 2];
					else
						temp[i] = temp[i - 1];
				}
				else
				{
					temp[i] = temp[i - 1];
				}
			}
		}
		return temp[s.size()];
	}
};

int main()
{
	Solution s;
	int res = s.numDecodings("00");
	return 0;
}