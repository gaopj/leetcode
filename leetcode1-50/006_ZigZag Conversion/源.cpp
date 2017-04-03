#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string res;
		if (numRows == 1)
			return s;
		else
		{
			for (size_t i = 0; i < s.size(); i+=(numRows-1)*2)
			{
				res += s[i];
			}
			for (size_t i = 1; i < numRows-1; i++)
			{
				for (size_t j = i; j < s.size();j+=(numRows-1)*2)
				{
					res += s[j];
					int k = 2 * (numRows - 1 - i) + j;
					if (k < s.size())
						res += s[k];
				}
			}
			for (size_t i = numRows-1; i < s.size(); i += (numRows - 1) * 2)
			{
				res += s[i];
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	string re;
	re=s.convert("PAYPALISHIRING", 3);
	return 0;
}