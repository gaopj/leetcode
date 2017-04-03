#include<vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int res = 1;
		int p = 0;
		bool flag = false;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[p])
			{
				flag = false;
				if (p + 1 != i)
				{
					int temp = nums[i];
					nums[i] = nums[p + 1];
					nums[p + 1] = temp;
				}
				p++;
				res++;
			}
			else if (nums[i] == nums[p])
			{
				if (flag == false)
				{
					flag = true;
					if (p + 1 != i)
					{
						int temp = nums[i];
						nums[i] = nums[p + 1];
						nums[p + 1] = temp;
					}
					p++;
					res++;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(1);
	s0.push_back(1);
	s0.push_back(1);
	s0.push_back(2);
	s0.push_back(2);
	s0.push_back(3);

	int res =s.removeDuplicates(s0);
	return 0;
}