#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board,int row,int col) {
		for (int j = 0; j < 9; j++)
		{
			if (j != col&&board[row][j] == board[row][col])
				return false;
			if (j != row&&board[j][col] == board[row][col])
				return false;
		}
			int lie = col / 3 * 3;
			int hang = row / 3 * 3;
		
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (!(hang + i == row&&lie + j == col) && board[hang + i][lie + j] == board[row][col])
						return false;
				}
			}
		return true;
	}
	bool solveSudoku_bool(vector<vector<char>>& board) {
		for (size_t i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					for (size_t k = 1; k <=9; k++)
					{
						board[i][j] = '0' + k;
						if (isValidSudoku(board, i, j) && solveSudoku_bool(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		solveSudoku_bool(board);
	}
};