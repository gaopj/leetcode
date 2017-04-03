#include<vector>
using namespace std;


class Solution {
public:

	void spiral(vector<vector<int>>& matrix, vector<vector<int>> &ispush, int row, int col,int & count)
	{
		if (ispush[row + 1][col + 1] == 0)
		{
			matrix[row][col]=count;
			ispush[row + 1][col + 1] = 1;
			count++;

			if (ispush[row][col + 1] == 0)
			{
				if (ispush[row + 1][col] == 1)
					spiral(matrix, ispush, row - 1, col,count);
				else
					spiral(matrix, ispush, row, col - 1,count);
			}
			else if (ispush[row + 1][col + 2] == 0)
			{
				if (ispush[row][col + 1] == 1)
					spiral(matrix, ispush, row, col + 1,count);
				else
					spiral(matrix, ispush, row - 1, col,count);
			}
			else if (ispush[row + 2][col + 1] == 0)
			{
				spiral(matrix, ispush, row + 1, col,count);
			}
			else if (ispush[row + 1][col] == 0)
				spiral(matrix, ispush, row, col - 1,count);

			else
				return;
		}
	}
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		int row = n;
		int col = n;
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
		vector<int> ress;
		for (size_t i = 0; i < n; i++)
		{
			ress.push_back(0);
		}
		for (size_t i = 0; i < n; i++)
		{
			res.push_back(ress);
		}
		int count = 1;
		spiral(res, ispush, 0, 0,count);
		return res;
	}
};

int main()
{
	Solution s;
	s.generateMatrix(1);
	return 0;
}