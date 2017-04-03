#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> wall;
	bool letgo(vector<vector<char>> &board, string word, int hang, int lie,int count)
	{
		if (word.size() == count)
			return true;
		else
		{
			bool res=false;
			if (hang + 1 < board.size() && wall[hang + 1][lie] == 0 && board[hang + 1][lie] == word[count])
			{
				wall[hang + 1][lie] = 1;
				res= letgo(board, word, hang + 1, lie, count + 1);
				if (res)
					return res;
				else
					wall[hang + 1][lie] = 0;
			}
			 if (hang - 1 >= 0 && wall[hang - 1][lie] == 0 && board[hang - 1][lie] == word[count])
			{
				wall[hang -1][lie] = 1;
				res= letgo(board, word, hang -1, lie, count + 1);
				if (res)
					return res;
				else
					wall[hang - 1][lie] = 0;
			}
			if (lie - 1 >= 0 && wall[hang][lie-1] == 0 && board[hang][lie-1] == word[count])
			{
				wall[hang][lie-1] = 1;
				res= letgo(board, word, hang, lie-1, count + 1);
				if (res)
					return res;
				else
					wall[hang][lie-1] = 0;
			}
			if (lie+ 1 <board[0].size() && wall[hang][lie + 1] == 0 && board[hang][lie + 1] == word[count])
			{
				wall[hang][lie + 1] = 1;
				res= letgo(board, word, hang, lie+ 1, count + 1);
				if (res)
					return res;
				else
					wall[hang][lie + 1] = 0;
			}
			return res;
		}
	}

	void set0(vector<vector<int>> &wall)
	{
		for (size_t i = 0; i < wall.size(); i++)
		{
			for (size_t j = 0; j < wall[0].size(); j++)
			{
				wall[i][j] = 0;
			}
		}
	}
	void init(vector<vector<char>>& board)
	{
		vector<int> wall0;
		for (size_t i = 0; i < board[0].size(); i++)
		{
			wall0.push_back(0);
		}
		for (size_t i = 0; i < board.size(); i++)
		{
			wall.push_back(wall0);
		}
		return;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word == "")
			return true;
		else
		{
			init(board);
			bool res = false;
			char star = word[0];
			for (size_t i = 0; i < board.size(); i++)
			{
				for (size_t j = 0; j < board[0].size(); j++)
				{
					if (board[i][j] == star)
					{
						wall[i][j] = 1;
						res = letgo(board,word,i,j,1);
						if (res)
							return res;
						else
							set0(wall);
					}
				}
			}
			return false;
		}
	}
};

int main()
{

	Solution s;
	vector<vector<char>> b;
	vector<char> b0;
	b0.push_back('C');
	b0.push_back('A');
	b0.push_back('A');
	b.push_back(b0);
	b0.clear();
	b0.push_back('A');
	b0.push_back('A');
	b0.push_back('A');
	b.push_back(b0);
	b0.clear();
	b0.push_back('B');
	b0.push_back('C');
	b0.push_back('D');
	b.push_back(b0);
	b0.clear();


	string word = "AAB";

	bool res=s.exist(b, word);

	return 0;
}