#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		heights.push_back(0);
		int resmax = 0;
		for (size_t i = 0; i < heights.size(); i++)
		{
			if (s.empty() || heights[i]>heights[s.top()])
				s.push(i);
			else
			{
				int temp = s.top();
				s.pop();
				int newsize = heights[temp] * (s.empty() ? i : i - s.top() - 1);
				resmax = newsize > resmax ? newsize : resmax;
				i--;
			}
		}
		return resmax;
	}
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		vector<vector<int>>  newr;
		vector<int> new1;
		for (size_t i = 0; i < matrix[0].size(); i++)
		{
			new1.push_back(matrix[0][i]-'0');
		}
		newr.push_back(new1);
		for (size_t i = 1; i < matrix.size(); i++)
		{
			vector<int> new1;
			for (size_t j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j]!='0')
				new1.push_back(newr[i - 1][j] + matrix[i][j] - '0');
				else
				new1.push_back(0);
			}
			newr.push_back(new1);
		}

		int max = largestRectangleArea(newr[0]);
		for (size_t i = 1; i < newr.size(); i++)
		{
			int newmax = largestRectangleArea(newr[i]);
			if (max < newmax)
				max = newmax;
		}
		return max;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> s0;
	vector<char>s00;
	s00.push_back('0');
	s00.push_back('1');
	s0.push_back(s00);
	s00.clear();
	s00.push_back('1');
	s00.push_back('0');
	s0.push_back(s00);
	s00.clear();
	int res = s.maximalRectangle(s0);

	return 0;
}