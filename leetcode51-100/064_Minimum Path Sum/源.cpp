#include<vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		vector<vector<int> > f(grid.size(), vector<int>(grid[0].size()));
		f[0][0] = grid[0][0];
		for (size_t i = 1; i < grid.size(); i++)
		{
			f[i][0] = grid[i][0]+f[i - 1][0];
		}
		for (size_t i = 1; i < grid[0].size(); i++)
		{
			f[0][i] = grid[0][i]+ f[0][i - 1];
		}
		for (size_t i = 1; i < grid.size(); i++)
		{
			for (size_t j = 1; j < grid[0].size(); j++)
			{
				f[i][j] = f[i - 1][j]<f[i][j - 1] ? f[i - 1][j]+grid[i][j] : f[i][j - 1]+grid[i][j];
			}
		}
		return f[grid.size() - 1][grid[0].size() - 1];
	}
};