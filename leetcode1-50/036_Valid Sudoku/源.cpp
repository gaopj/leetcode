#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (size_t i = 0; i < 9; i++)
		{
			set<char> c1;
			set<char> c2;
			set <char> c3;
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] == '.');
				else if (c1.count(board[i][j]) != 0)
					return false;
				else
					c1.insert(board[i][j]);
				if (board[j][i] == '.');
				else if (c2.count(board[j][i]) != 0)
					return false;
				else
					c2.insert(board[j][i]);

				int hang = i / 3 * 3 + j / 3;
				int lie = i % 3 * 3 + j % 3;
				if (board[hang][lie] == '.');
				else if (c3.count(board[hang][lie]) != 0)
					return false;
				else
					c3.insert(board[hang][lie]);
			}
		}
		return true;
	}
};
int main()
{

	return 0;
}