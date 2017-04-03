#include<vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); )
		{
			if (nums[i]>nums.size() || nums[i] < 1)
			{
				i++;
			}
			else if (nums[i]!=i+1)
			{
				int num = nums[i] - 1;
				if (nums[i] == nums[num])
				{
					i++; continue;
				}
				int temp = nums[i];
				nums[i] = nums[num];
				nums[num] = temp;

			}	
			else
			{
				i++;
			}
		}
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		return nums.size()+1;
	}
};

int main()
{

	Solution s;
	vector<int> s0;
	s0.push_back(3);
	s0.push_back(4);
	s0.push_back(-1);
	s0.push_back(1);
	int res=s.firstMissingPositive(s0);
	return 0;
}