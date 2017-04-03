#include<stdlib.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		multimap<int, int> imap;
		vector<int> res;
		int id = 0;
		for (vector<int>::iterator i = nums.begin(); i != nums.end();i++,id++)
		{
			imap.insert(make_pair(*i, id));
		}
		multimap<int, int>::iterator low = imap.begin();
		multimap<int, int>::iterator high = imap.end();
		high--;
		while (low->first<=high->first)
		{
			if (high->first + low->first < target)
				low++;
			else if (high->first + low->first > target)
				high--;
			else
			{
				if (low->second < high->second)
				{
					res.push_back(low->second);
					res.push_back(high->second);
					return res;
				}
				else
				{
					res.push_back(high->second);
					res.push_back(low->second);
					return res;
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<int> ivec;
	ivec.push_back(0);
	ivec.push_back(4);
	ivec.push_back(3); 
	ivec.push_back(0);
	Solution s;
	s.twoSum(ivec, 0);
	return 0;
}