#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		stringstream ss;
		ss << s;
		s = "";
		string temp = "";
		ss >> s;
		while (ss>>temp)
		{
			s = temp + " " + s;
		}
	}
};