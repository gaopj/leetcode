#include<vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int hang = 0,lie=0;
		for (; hang < matrix.size(); hang++)
		{
			if (matrix[hang][0] == target)
				return true;
			else if (matrix[hang][0] > target)
				break;
		}
		hang--;
		if (hang < 0)
			return false;
		for (lie++; lie < matrix[0].size(); lie++)
		{
			if (matrix[hang][lie] == target)
				return true;
			else if (matrix[hang][0] > target)
				return false;
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> s0;
	vector<int> s00;
	s00.push_back(1);
	s00.push_back(3);
	//s00.push_back(5);
	s0.push_back(s00);
	bool res =s.searchMatrix(s0, 3);
	return 0;
}