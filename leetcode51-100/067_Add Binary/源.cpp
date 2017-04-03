#include<string>
using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {
		string res="";
		int ap = a.size()-1;
		int bp = b.size()-1;
		int jinwei = 0;
		while (ap>=0&&bp>=0)
		{
			int num = a[ap]-'0' + b[bp]-'0' + jinwei;
			jinwei = num / 2;
			num = num % 2;
			res = (char)(num + '0') + res;
			ap--; bp--;
		}
		if (ap >= 0)
		{
			int num = a[ap]-'0' + jinwei;
			jinwei = num / 2;
			num = num % 2;
			res = (char)(num + '0') + res;
			ap--; 
			while (ap>=0)
			{
				int num = a[ap]-'0' + jinwei;
				jinwei = num / 2;
				num = num % 2;
				res = (char)(num + '0') + res;
				ap--;
			}
		}
		else if (bp >= 0)
		{
			int num = b[bp]-'0' + jinwei;
			jinwei = num / 2;
			num = num % 2;
			res = (char)(num + '0') + res;
			bp--;
			while (bp >= 0)
			{
				int num = b[bp]-'0' + jinwei;
				jinwei = num / 2;
				num = num % 2;
				res = (char)(num + '0') + res;
				bp--;
			}
		}

			if (jinwei)
				res = '1' + res;
		return res;

	}
};

int main()
{
	Solution s;
	string a = "1";
	string b = "1";
	string res=	s.addBinary(a, b);
	return 0;
}