#include<stdlib.h>
#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
	string qian(char a)
	{
		switch (a)
		{
		case '1':return "M";
			break;
		case '2':return "MM";
			break;
		case '3':return "MMM";
			break;
		default:
			return "";
			break;
		}
	}
		string bai(char a)
		{
			switch (a)
			{
			case '1':return "C";
				break;
			case '2':return "CC";
				break;
			case '3':return "CCC";
				break;
			case '4':return "CD";
				break;
			case '5':return "D";
				break;
			case '6':return "DC";
				break;
			case '7':return "DCC";
				break;
			case '8':return "DCCC";
				break;
			case '9':return "CM";
				break;
			default:
				return "";
				break;
			}
		}
		string shi(char a)
		{
			switch (a)
			{
			case '1':return "X";
				break;
			case '2':return "XX";
				break;
			case '3':return "XXX";
				break;
			case '4':return "XL";
				break;
			case '5':return "L";
				break;
			case '6':return "LX";
				break;
			case '7':return "LXX";
				break;
			case '8':return "LXXX";
				break;
			case '9':return "XC";
				break;
			default:
				return "";
				break;
			}
		}

		string ge(char a)
		{
			switch (a)
			{
			case '1':return "I";
				break;
			case '2':return "II";
				break;
			case '3':return "III";
				break;
			case '4':return "IV";
				break;
			case '5':return "V";
				break;
			case '6':return "VI";
				break;
			case '7':return "VII";
				break;
			case '8':return "VIII";
				break;
			case '9':return "IX";
				break;
			default:
				return "";
				break;
			}
		}
	string intToRoman(int num) {
		stringstream ss;
		ss << num;
		string s,res;
		ss >> s;
		ss.clear();
		if (num >= 1000)
		{
			res += qian(s[0]);
			res += bai(s[1]);
			res += shi(s[2]);
			res += ge(s[3]);
		}
		else if (num<1000&&num>=100)
		{
			res += bai(s[0]);
			res += shi(s[1]);
			res += ge(s[2]);
		}
		else if (num<100 && num >= 10)
		{
			res += shi(s[0]);
			res += ge(s[1]);
		}
		else if (num<10)
		{
			res += ge(s[0]);
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.intToRoman(4);
	return 0;
}