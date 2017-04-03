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

		//������Ϊ����
		if ((numerator < 0) ^ (denominator < 0)) {
			ans += "-";
		}

		//����Ҫ����������תΪ������Ϊ���������intתΪlong
		long num = numerator, den = denominator;
		num = abs(num);
		den = abs(den);
		stringstream ss;
		//�������������

		
		long res = num / den;
		ss << res;
		string buf;
		ss >> buf;
		ss.clear();
		ans += buf;

		//����ܹ����������ؽ��
		long rem = (num % den) * 10;
		if (rem == 0) return ans;

		//�����С������
		map<long, int> map1;
		ans += ".";
		while (rem != 0) {
			//���ǰ���Ѿ����ֹ�����������ô���Ὺʼѭ��
			if (map1.count(rem)) {
				int beg = map1[rem]; //ѭ���忪ʼ��λ��
				string part1 = ans.substr(0, beg);
				string part2 = ans.substr(beg, ans.length() - beg);
				ans = part1 + "(" + part2 + ")";
				return ans;
			}

			//�������³�
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