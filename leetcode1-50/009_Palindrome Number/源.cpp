#include<stdlib.h>
#include<iostream>

using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
		return false;
		int num = x;
		int len = 1;
		while (num/len>=10)
		{
			len = len * 10;
		}
		while (num!=0)
		{
			int left = num / len;
			int right = num % 10;
			if (left != right)
				return false;
			num = (num%len) / 10;
			len /= 100;
		}
		return true;
	}
};

int main()
{
	Solution s;
	bool res=s.isPalindrome(1);
	return 0;
}