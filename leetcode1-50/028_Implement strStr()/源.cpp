#include<stdlib.h>
#include<string>

using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int nsize = needle.size();
		if (nsize > haystack.size())
			return -1;
		for (size_t i = 0; i <= haystack.size()-needle.size(); i++)
		{
			if (haystack.compare(i, nsize, needle) == 0)
				return i;
		}
		return -1;
	}
};
int main()
{

	return 0;
}