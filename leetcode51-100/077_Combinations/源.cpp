#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	int n;
	int k;
	void huishuo(int from,int l, vector<int> &res0)
	{
		if (res0.size() == k)
		{
			vector<int> res00(res0);
			res.push_back(res00);
			return;
		}
		else
		{

			for (size_t i = from; i <= n; i++)
			{
				res0.push_back(i);
				huishuo(i + 1,l+1,res0);
				vector<int>::iterator p = res0.begin();
				res0.erase(p + l);
			}
		}
	}

	vector<vector<int>> combine(int n, int k) {
		this->n = n;
		this->k = k;
		vector<int>res0;
		huishuo(1,0,res0);
		return res;
	}
};

int main()
{
	Solution s;
	s.combine(4, 2);
	return 0;
}