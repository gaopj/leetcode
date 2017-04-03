#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isnotsame(vector<int> v1, vector<int> v2)
	{
		if (v1.size() != v2.size())
			return true;
		else
		{
			for (size_t i = 0; i < v1.size(); i++)
			{
				if (v1[i] != v2[i])
					return true;
			}
		}
		return false;
	}
	void backTracking(vector<vector<int> > &res, vector<int>& candidates, vector<int> & nowres, int target, int from)
	{
		if (target == 0)
		{
			res.push_back(nowres);
		}
		else
		{
			for (int i = from; i < candidates.size() ; i++)
			{
				if (candidates[i]>target)
					break;
				if (i != from && candidates[i] == candidates[i - 1])
					continue;
				nowres.push_back(candidates[i]);
				backTracking(res, candidates, nowres, target - candidates[i], i+1);
				vector<int>::iterator pi = find(nowres.begin(), nowres.end(), candidates[i]);
				nowres.erase(pi);
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		vector<vector<int>> res;
		vector<int> nowres;
		sort(candidates.begin(), candidates.end());
		backTracking(res, candidates, nowres, target, 0);
		return res;
	}
};

int main()
{
	vector<int> cond;
	cond.push_back(2);
	cond.push_back(3);
	cond.push_back(6);
	cond.push_back(7);
	Solution s;
	vector<vector<int>> res;
	res = s.combinationSum2(cond, 7);
	return 0;
}