#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		int i = 0, j = 1,next=2;
//		if (p == ""&&s != "")
//			return false;
//		int pre = 0;
//		if (p[0] == '.')
//			i++;
//		else
//		{
//			if (p.size() > 1 && p[1] == '*')
//				i++;
//			else if (p[0] == s[0])
//				i++;
//			else
//				return false;
//		}
//		while (i<s.size()&&j<p.size())
//		{
//			if (p[j] == '.')
//			{
//				j=next; i++; pre = j; 
//					next = j + 1;
//			}
//			else if (p[j] == '*')
//			{
//				if (next<p.size()&&p[pre]==p[next])
//				{
//					next ++;
//				}
//				if (s[i] ==p[pre])
//					i++;
//				else if (p[pre] == '.')
//				{
//					if (next < p.size() && s[i] == p[next])
//					{
//						i++; pre = j+1;
//						next++;
//						j = next; next = j + 1;
//					}
//					else
//					{
//						i++;
//					}
//				}
//				else
//				{
//					pre = j; j=next; next =j + 1;
//				}
//			}
//			else if (p[j] == s[i])
//			{
//				pre =j; j=next, i++; next = j + 1;
//			}
//			else
//			{
//				if (next < p.size() && p[next] == '*')
//				{
//					next++;
//
//					j = next;
//					pre = j - 1;
//					next = j + 1;
//				}
//				else
//				{
//					return false;
//				}
//			}
//		}
//		if (i == s.size() && j == p.size())
//			return true;
//		else if (i != s.size())
//		{
//			return false;
//		}
//		else
//		{
//			if (p[j] == '*')
//			{
//				for (int k =next; k < p.size(); k += 2, j += 2)
//				{
//					if (k== p.size() - 1)
//						return false;
//					if (p[j] != '*')
//						return false;
//				}
//				return true;
//			}
//			else if (p[next] == '*')
//			{
//				for (int k= j;k< p.size(); k+=2,next+=2)
//				{
//					if (k == p.size() - 1)
//						return false;
//					if (p[next] != '*')
//						return false;
//				}
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//};


//class Solution
//{
//public:
//	bool isMatch(string s, string p)
//	{
//		if (s.empty())
//			return p.empty();
//		if (1 < p.size() && p[1] == '*')
//		{
//			size_t pos = 0;
//			string sc, pc;
//			pos < s.size() ? sc = s.substr(pos) : sc = "";
//			2 < p.size() ? pc = p.substr(2) : pc = "";
//			while ((pos < s.size() && p[0] == s[pos]) || (p[0] == '.'&&sc != ""))
//			{
//				pos < s.size() ? sc = s.substr(pos) : sc = "";
//				2 < p.size() ? pc = p.substr(2) : pc = "";
//				if (isMatch(sc, pc))
//					return true;
//				pos++;
//			}
//		return isMatch(s, p.substr(2));
//	  }
//		else
//		{
//			string sc, pc;
//			if (p[0] == s[0] || (p[0] == '.'&&!s.empty()))
//			{
//				1 < s.size() ? sc = s.substr(1) : sc = "";
//				1 < p.size() ? pc = p.substr(1) : pc = "";
//				return isMatch(sc, pc);
//			}
//			return false;
//		}
//	}
//};


#include <stdio.h>


class Solution {
public:
	//bool isMatch(const char *s, const char *p) {
	bool isMatch(string ss,string ps) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		const char *s = ss.c_str(), *p = ps.c_str();
		if (0 == *p) return 0 == *s;

		if (*(p + 1) != '*')
		{
			if (*p == *s || (*p) == '.' && (*s) != 0)
			{
				return isMatch(s + 1, p + 1);
			}
			return false;
		}
		else
		{
			while (*p == *s || ((*p) == '.' && (*s) != 0))
			{
				if (isMatch(s, p + 2))
				{
					return true;
				}
				s++;
			}
			return isMatch(s, p + 2);

		}

	}
};



int main()
{
	Solution s0;
	const char* p = "aab", *s = ".*";
	bool res = s0.isMatch(p, s);
	return 0;
}

//"abbcbaabcccaaaaab"
//"c*ab*a*a*a*b*b*"