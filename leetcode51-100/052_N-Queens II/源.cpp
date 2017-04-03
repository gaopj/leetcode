#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
private:		int res;
public:
	int totalNQueens(int n) {
		vector<int> state(n, -1);
		bianli(state, 0, n);
		return res;
	}
	void bianli(vector<int> &stack, int row, int n)
	{
		if (row == n)
		{

			res++;
			return;
		}
		else
		{
			for (int col = 0; col < n; col++)
			{
				if (isOK(stack, col, row))
				{
					stack[row] = col;
					bianli(stack, row + 1, n);
					stack[row] = -1;
				}
			}
		}
	}

	bool isOK(vector<int> &stack, int col, int row)
	{
		for (int i = 0; i < row; i++)
		{
			if (stack[i] == col || abs(stack[i] - col) == abs(i - row))
				return false;
		}
		return true;
	}
};