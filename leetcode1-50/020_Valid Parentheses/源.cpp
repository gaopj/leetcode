#include<stdlib.h>
#include<stack>
#include<string>

using namespace std;
class Solution {
public:
	bool isMatch(char a, char b)
	{
		if (a == '('&&b == ')')
			return true;
		else if (a == '['&&b == ']')
			return true;
		else if (a == '{'&&b == '}')
			return true;
		else
		{
			return false;
		}
	}
	bool isValid(string s) {
		stack < char > csta;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				csta.push(s[i]);
			else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				if (csta.empty())
					return false;
				else
				{
					char a = csta.top();
					if (isMatch(a, s[i]))
					{
						csta.pop();
					}
					else
					{
						return false;
					}
				}
			}
		}
		if (csta.empty())
		return true;
		else
			return false;
	}
};

int main()
{

	return 0;
}