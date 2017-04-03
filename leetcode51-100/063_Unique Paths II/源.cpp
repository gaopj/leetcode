#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int> > f(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()) );
		f[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (size_t i = 1; i < obstacleGrid.size(); i++)
		{
			f[i][0] = obstacleGrid[i][0] == 1 ? 0 : f[i-1][0];
		}
		for (size_t i = 1; i < obstacleGrid[0].size(); i++)
		{
			f[0][i] = obstacleGrid[0][i] == 1 ? 0 : f[0][i-1];
		}
		for (size_t i = 1; i < obstacleGrid.size(); i++)
		{
			for (size_t j = 1; j < obstacleGrid[0].size(); j++)
			{
				f[i][j] = obstacleGrid[i][j] == 1 ? 0 : f[i - 1][j] + f[i][j - 1];
			}

		}
		return f[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};