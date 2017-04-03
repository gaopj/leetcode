#include<vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool flaghang = false;
		bool flaglie = false;
		for (size_t i = 0; i < matrix[0].size(); i++)
		{
			if (matrix[0][i] == 0)
			{
				flaghang = true;
				break;
			}
		}
		for (size_t i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][0] == 0)
			{
				flaglie = true;
				break;
			}
		}
		for (size_t i = 1; i < matrix.size(); i++)
		{
			for (size_t j = 1; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (size_t i = 1; i < matrix.size(); i++)
		{
			if (matrix[i][0]==0)
			{
				for (size_t j = 1; j < matrix[0].size(); j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (size_t i = 1; i < matrix[0].size(); i++)
		{
			if (matrix[0][i] == 0)
			{
				for (size_t j = 1; j < matrix.size(); j++)
				{
					matrix[j][i] = 0;
				}
			}
		}

			if (flaghang)
			{
				for (size_t i = 0; i < matrix[0].size(); i++)
				{
					matrix[0][i] = 0;
				}
			}
			if (flaglie){
				for (size_t i = 0; i < matrix.size(); i++)
				{
					matrix[i][0] = 0;
				}
			}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> s0;
	vector<int> s00;
	s00.push_back(1);
	s00.push_back(0);
	s0.push_back(s00);
	s.setZeroes(s0);
	return 0;
}