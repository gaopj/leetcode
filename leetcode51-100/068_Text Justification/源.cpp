#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		vector<string> temp;
	//	temp.reserve(maxWidth);
		int count = 0;
		int strnum = 0;
		for (size_t i = 0; i < words.size(); i++)
		{
			if (strnum == 0)
			{
				temp.clear();
				temp.push_back(words[i]);
				count = words[i].size();
				strnum = 1;
				continue;
			}
			else
			{
				if (words[i].size() + strnum + count <= maxWidth)
				{
					strnum++;
					count += words[i].size();
					temp.push_back(words[i]);
				}
				else
				{
					string res0;
					res0.reserve(maxWidth);
						
					if (strnum == 1)
					{
						res0 = temp[0];
						for (size_t i = res0.size(); i < maxWidth; i++)
						{
							res0 += " ";
						}
						res.push_back(res0);
						temp.clear();
						temp.push_back(words[i]);
						count = words[i].size();
						strnum = 1;
						continue;
					}
					else
					{
						int shang = (maxWidth - count) / (strnum - 1);
						int yushu = (maxWidth - count) % (strnum - 1);
						string left, right;
						for (size_t i = 0; i < shang; i++)
						{
							right += " ";
						}
						left = right + " ";
						res0 = temp[0];
						int j = 0;
						for (j++; j <=yushu; j++)
						{
							res0 += left + temp[j];
						}
						for (; j < temp.size(); j++)
						{
							res0 += right + temp[j];
						}
					}
					res.push_back(res0);
					temp.clear();
					temp.push_back(words[i]);
					count = words[i].size();
					strnum = 1;
					continue;
				}
			}
		}
		if (!temp.empty())
		{
			string last;
			last.reserve(maxWidth);
			last = temp[0];
			for (size_t i = 1; i < temp.size(); i++)
			{
				last += (" " + temp[i]);
			}
			size_t i = last.size();
			for (size_t i = last.size(); i < maxWidth; i++)
			{
				last += " ";
			}
			res.push_back(last);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> s0;
	s0.push_back("a");
	s0.push_back("b");
	s0.push_back("c");
	s0.push_back("d");
	s0.push_back("e");
	vector<string> res = s.fullJustify(s0,1);
	return 0;
}