#include<string>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;


class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		if (denominator == 0) return "";

		string ans = "";

		//如果结果为负数
		if ((numerator < 0) ^ (denominator < 0)) {
			ans += "-";
		}

		//下面要把两个数都转为正数，为避免溢出，int转为long
		long num = numerator, den = denominator;
		num = abs(num);
		den = abs(den);
		stringstream ss;
		//结果的整数部分

		
		long res = num / den;
		ss << res;
		string buf;
		ss >> buf;
		ss.clear();
		ans += buf;

		//如果能够整除，返回结果
		long rem = (num % den) * 10;
		if (rem == 0) return ans;

		//结果的小数部分
		map<long, int> map1;
		ans += ".";
		while (rem != 0) {
			//如果前面已经出现过该余数，那么将会开始循环
			if (map1.count(rem)) {
				int beg = map1[rem]; //循环体开始的位置
				string part1 = ans.substr(0, beg);
				string part2 = ans.substr(beg, ans.length() - beg);
				ans = part1 + "(" + part2 + ")";
				return ans;
			}

			//继续往下除
			map1[rem] = ans.length();
			res = rem / den;
			ss << res;
			ss >> buf;
			ss.clear();
			ans += buf;
			rem = (rem % den) * 10;
		}

		return ans;
	}
};

int main()
{
	Solution s;
	string res=s.fractionToDecimal(1, 5);
	return 0;
}