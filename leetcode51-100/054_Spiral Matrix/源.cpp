#include<vector>
using namespace std;

class Solution {
public:
	vector<int> res;
	void spiral(vector<vector<int>>& matrix, vector<vector<int>> &ispush,int row,int col)
	{
		if (ispush[row + 1][col + 1] == 0)
		{
			res.push_back(matrix[row][col]);
			ispush[row + 1][col + 1] = 1;

			if (ispush[row][col + 1] == 0)
			{
				if (ispush[row + 1][col] == 1)
				spiral(matrix, ispush, row - 1, col);
				else
				spiral(matrix, ispush, row, col - 1);
			}
			else if (ispush[row + 1][col + 2] == 0)
			{
				if (ispush[row][col + 1] == 1)
				spiral(matrix, ispush, row, col + 1);
				else
				spiral(matrix, ispush, row - 1, col);
			}
			else if (ispush[row + 2][col + 1] == 0)
			{
				spiral(matrix, ispush, row + 1, col);
			}
			else if (ispush[row + 1][col] == 0)
				spiral(matrix, ispush, row , col-1);

			else
				return;
		}
	}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return res;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> inirow1, inirow2;
		vector<vector<int>> ispush;
		for (size_t i = 0; i <= col + 1; i++)
		{
			inirow1.push_back(1);
		}
		ispush.push_back(inirow1);
		inirow2.push_back(1);
		for (size_t i = 1; i <= col; i++)
		{
			inirow2.push_back(0);
		}
		inirow2.push_back(1);
		for (size_t i = 1; i <= row; i++)
		{
			ispush.push_back(inirow2);
		}
		ispush.push_back(inirow1);
		spiral(matrix, ispush, 0, 0);
		return res;	
	}
};

int main()
{
	Solution s;
	vector<int> a0;
	vector<vector<int>> a;
	a0.push_back(2);
	a0.push_back(3);
	a.push_back(a0);
	vector<int> res = s.spiralOrder(a);
	return 0;
}