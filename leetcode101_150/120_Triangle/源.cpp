#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int> > res;
		if (triangle.size() == 0)
			return 0;
		if (triangle.size() == 1)
			return triangle[0][0];
		vector<int> res0;
		res0.push_back(triangle[0][0]);
		res.push_back(res0);
		//res0.clear();
		for (size_t i = 1; i < triangle.size(); i++)
		{
			res0.clear();
			for (size_t j = 0; j < triangle[i].size(); j++)
			{
				if (j == 0)
					res0.push_back(res[i - 1][j] + triangle[i][j]);
				else if (j == triangle[i].size()-1)
				{
					res0.push_back(res[i - 1][j - 1] + triangle[i][j]);
				}
				else
				{
					int temp = (res[i - 1][j - 1]>res[i - 1][j] ? res[i - 1][j] : res[i - 1][j - 1]);
					res0.push_back(temp + triangle[i][j]);
				}
			}
			res.push_back(res0);
		}
		return findmin(res[res.size() - 1]);
	}
	int findmin(vector<int> ivec)
	{
		int min = ivec[0];
		for (size_t i =1; i < ivec.size(); i++)
		{
			if (min>ivec[i])
				min = ivec[i];
		}
		return min;
	}
};