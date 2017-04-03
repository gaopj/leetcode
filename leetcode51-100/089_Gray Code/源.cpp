#include<vector>

using namespace std;

class Solution {
public:
	vector<int> res;
	vector<int> grayCode(int n) {
		if (n == 0)
		{
			res.push_back(0);
		}
		else
		{
			vector<int> temp = grayCode(n - 1);
			int addnum = 1 << (n - 1);
			for (int i = temp.size()-1; i >= 0; i--)
			{
				res.push_back(addnum + temp[i]);
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> res = s.grayCode(1);

	return 0;
}