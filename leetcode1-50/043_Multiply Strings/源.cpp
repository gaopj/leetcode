#include<string>
using namespace std;
class Solution {
public:
	string oneMul(string s, char a)
	{
		if (a == '0')
			return "0";
		string res;
		int value = 0;
		int jinwei = 0;
		int zhi = 0;
		
		for ( int i = s.size()-1; i >=0; i--)
		{
			 value = (a - '0')*(s[i] - '0');
			 zhi = value % 10;
			 char zhic = (zhi + jinwei) % 10 + '0';
			 res += zhic;
			jinwei = value / 10+(zhi+jinwei)/10;
		}
		if (jinwei != 0)
		{
			char c = jinwei + '0';
			res += c;
		}
		return res;
	}
	void add_two_num(string & res,int pos, string newnum)
	{
		if (newnum == "0")
			return ;
		int jinwei = 0;
		int zhi = 0;
		while (pos>res.size())
		{
			res += "0";
		}

		for (int i = 0; i < newnum.size(); i++)
		{
			if (i + pos < res.size())
			{
				zhi = (res[i + pos] - '0') + newnum[i]-'0' + jinwei;
				char zhic = zhi % 10+'0';
				res[i + pos] = zhic;
				jinwei = zhi / 10;
			}
			else  
			{
				zhi = newnum[i]-'0' + jinwei;
				char zhic = zhi % 10 + '0';
				res+= zhic;
				jinwei = zhi / 10;
			}
		}
		if (jinwei != 0)
		{
			res += '1';
		}
	}
	void reverse(string &s)
	{
		int low = 0;
		int high = s.size() - 1;
		while (low<high)
		{
			int temp = s[low];
			s[low] = s[high];
			s[high] = temp;
			low++;
			high--;
		}
	}
	string multiply(string num1, string num2) {
		string res;
		if (num1 == "0" || num2 == "0")
			return "0";
		for (int i = num2.size()-1; i >=0; i--)
		{
			string newnum = oneMul(num1, num2[i]);
			add_two_num(res, num2.size()-1-i, newnum);
		}
		reverse(res);
		return res;
	}
};
int main()
{
	Solution s; 
	string num1 = "6";
	string num2 = "501";
	string res = s.multiply(num1, num2);
	return 0;
}