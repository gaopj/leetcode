#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for ( vector<int>::iterator i=nums.begin();i!=nums.end(); )
		{
			if (*i == val)
				i = nums.erase(i);
			else
				i++;
		}
		return nums.size();
	}
};
int main()
{

	return 0;
}