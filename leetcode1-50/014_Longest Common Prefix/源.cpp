#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res;
		if (strs.empty())
			return res;
		else
			res = strs[0];
		vector<string>::iterator i = strs.begin();
		for (i++; i !=strs.end(); i++)
		{
			int j = 0;
			for (; res[j] == (*i)[j]; j++);
			res = res.substr(0, j);
		}
		return res;
	}
};
int main()
{

	return 0;
}