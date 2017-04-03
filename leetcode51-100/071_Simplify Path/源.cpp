#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> temp;
		string::size_type pos1, pos2;
		string news = path;
		pos1 = news.find_first_of('/');
		pos2 = news.find_first_of('/',1);
		string s = news.substr(pos1, pos2 - pos1);
		//news = path.substr(pos2);
		while (pos1!=string::npos)
		{
			if (s == "/");
			else if (s == "/.");
			else if (s == "/..")
			{
				if (!temp.empty())
				temp.pop_back();
			}
			else
			{
				temp.push_back(s);
			}
			pos1 = pos2;
			if (pos2 == string::npos)
				continue;
			pos2 = news.find_first_of('/', pos2+1);
			s = "";
			s = news.substr(pos1, pos2 - pos1);
		}
		string res="";
		for (size_t i = 0; i < temp.size(); i++)
		{
			res += temp[i];
		}
		if (res == "")
			return "/";
		return res;
	}
};

int main()
{
	Solution s;
	string res = s.simplifyPath("/.../");
	return 0;
}