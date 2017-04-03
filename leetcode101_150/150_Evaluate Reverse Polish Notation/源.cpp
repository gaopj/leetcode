#include<vector>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> sta;
		stringstream ss;
		for (size_t i = 0; i < tokens.size(); i++)
		{
			char c = tokens[i][0];
			int a = 0;
			int b = 0;
			switch (c)
			{
			case '+':
				 a = sta.top();
				 sta.pop();
				 b = sta.top();
				sta.pop();
				sta.push(a + b);
				break;
			case '-':
				if (tokens[i].size() == 1)
				{
					a = sta.top();
					sta.pop();
					b = sta.top();
					sta.pop();
					sta.push(b - a);
				}
				else
				{
					ss << tokens[i];
					int num = 0;
					ss >> num;
					ss.clear();
					sta.push(num);
				}
				break;
			case '*':
				 a = sta.top();
				 sta.pop();
				 b = sta.top();
				sta.pop();
				sta.push(a * b);
				break;
			case '/':
				 a = sta.top();
				 sta.pop();
				 b = sta.top();
				sta.pop();
				sta.push(b / a);
				break;
			default:
				ss<<tokens[i];
				int num = 0;
				ss >> num;
				ss.clear();
				sta.push(num);
				break;
			}
		}
		return sta.top();
	}
};

int main()
{
	vector<string> tokens;
	tokens.push_back("3");
	tokens.push_back("-4");
	tokens.push_back("+");
	Solution s;
	int res= s.evalRPN(tokens);
	return 0;
}