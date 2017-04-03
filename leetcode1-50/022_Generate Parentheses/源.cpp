#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	void generate(int leftNum, int rightNum, string s, vector<string> &res)
	{
		if (leftNum == 0 && rightNum == 0)
			res.push_back(s);
		if (leftNum>0)
		{
			generate(leftNum - 1, rightNum, s + "(", res);
		}
		if (rightNum>0&&leftNum<rightNum)
			generate(leftNum , rightNum-1, s + ")", res);
	}
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		 generate(n, n, "", res);
		 return res;
	}
};
int main()
{

	return 0;
}