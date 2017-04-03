#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str == "")
			return 0;
		int res = 0;
		stringstream ss;
		ss << str;
		ss >> res;
		ss.clear();
		return res;
	}
};
int main()
{
	Solution s;
	int re=s.myAtoi("-1234");
	return 0;
}