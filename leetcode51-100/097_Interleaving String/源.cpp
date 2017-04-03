#include<string>
#include<vector>
using namespace std;

//class Solution {
//
//public:
//	string s1; string s2; string s3;
//	bool huishuo(int &pos1,int &pos2,int &pos3)
//	{
//		if (pos3 == s3.size())
//		{
//			if (s1.size() == pos1&&s2.size() == pos2)
//				return true;
//			else
//			{
//				return false;
//			}
//		}
//		if (pos1<s1.size()&&s1[pos1]==s3[pos3])
//		{
//			pos1++;
//			pos3++;
//			bool res=huishuo(pos1, pos2, pos3);
//			if (res)
//				return true;
//			else
//			{
//				pos1--;
//				pos3--;
//			}
//		}
//		 if (pos2<s2.size() && s2[pos2] == s3[pos3])
//		{
//				pos2++;
//				pos3++;
//				bool res = huishuo(pos1, pos2, pos3);
//				if (res)
//					return true;
//				else
//				{
//					pos2--;
//					pos3--;
//				}
//		}
//		return false;
//	}
//
//	bool isInterleave(string s1, string s2, string s3) {
//		this->s1 = s1;
//		this->s2 = s2;
//		this->s3 = s3;
//		int pos1 = 0;
//		int pos2 = 0;
//		int pos3 = 0;
//
//		return huishuo(pos1, pos2, pos3);
//	}
//};

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		vector<bool> res0(s1.size()+1, false);
		vector<vector<bool> >res(s2.size()+1, res0);
		res[0][0] = true;
		for (size_t i = 1; i <= s1.size(); i++)
		{
			res[0][i] = res[0][i - 1] && (s1[i - 1] == s3[i - 1]);
		}
		for (size_t j = 1; j <= s2.size(); j++)
		{
			res[j][0] = res[j-1][0] && (s2[j - 1] == s3[j - 1]);
		}
		for (size_t i = 1; i <= s1.size(); i++)
		{
			for (size_t j = 1; j <= s2.size(); j++)
			{
				res[j][i] = (res[j - 1][i] && s2[j - 1] == s3[i + j - 1]) || (res[j][i - 1] && s1[i - 1] == s3[i + j - 1]);
			}
		}
		return res[s2.size()][s1.size()];
	}
};
int main()
{
	Solution s;
	bool res = s.isInterleave("a", "b", "ab");
	return 0;
}