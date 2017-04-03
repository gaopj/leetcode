#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string,vector<string> > mstr;
		vector<vector<string>> res;
		for (size_t i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			mstr[s].push_back(strs[i]);
		}
		for (map<string, vector<string> >::iterator i = mstr.begin(); i!= mstr.end(); i++)
		{
			res.push_back(i->second);
		}
		return res;
	}
};

int main()
{
	return 0;
}