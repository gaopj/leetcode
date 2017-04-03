#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	void n_countAndSay(string &s, int n)
	{
		if (n <= 0)
			return;
		string res;
		stringstream ss;
		int size = s.size();
		for (int i = 0; i < size;)
		{
			int count = 1;
			char c = s[i];
			i++;
			while (i<size&&c==s[i])
			{
				count++;
				i++;
			}
			string cot;
			ss << count;
			ss >> cot;
			ss.clear();
			res += cot+c;
		}
		s = res;
		n_countAndSay(s, n - 1);
		return;
	}
	string countAndSay(int n) {
		string res = "1";
		n_countAndSay(res, n - 1);
		return res;
	}
};
int main()
{
	Solution s;
	string res = s.countAndSay(13);
	return 0;
}