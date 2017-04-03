#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
	vector<string> Digit_Char(char a)
	{
		vector<string> s;
		switch (a)
		{
		case '2':s.push_back("a"); s.push_back("b"); s.push_back("c"); break;
		case '3':s.push_back("d"); s.push_back("e"); s.push_back("f"); break;
		case '4':s.push_back("g"); s.push_back("h"); s.push_back("i"); break;
		case '5':s.push_back("j"); s.push_back("k"); s.push_back("l"); break;
		case '6':s.push_back("m"); s.push_back("n"); s.push_back("o"); break;
		case '7':s.push_back("p"); s.push_back("q"); s.push_back("r"); s.push_back("s"); break;
		case '8':s.push_back("t"); s.push_back("u"); s.push_back("v"); break;
		case '9':s.push_back("w"); s.push_back("x"); s.push_back("y"); s.push_back("z"); break;
		default:
			break;
		}
		return s;
	}
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		vector< vector<string> > dvvs;
		vector<int> number;
		for (size_t i = 0; i < digits.size(); i++)
		{
			number.push_back(0);
		}
		for (size_t i = 0; i <digits.size(); i++)
		{
			dvvs.push_back(Digit_Char(digits[i]));
		}
		for (int i = digits.size()-1; i >=0; )
		{
			string res0;
			for (size_t j = 0; j < digits.size(); j++)
			{
				res0 += dvvs[j][number[j]];
			}
			res.push_back(res0);
			for ( i = digits.size()-1; i >=0; )
			{
				if (number[i] < dvvs[i].size() - 1)
				{
					number[i]++;
					break;
				}
				else
				{
					number[i] = 0;
					i--;
				}

			}
		}
		return res;
	}
};
int main()
{
	Solution s;

	vector<string> s0 = s.letterCombinations("22");
	return 0;
}