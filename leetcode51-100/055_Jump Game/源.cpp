#include<vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
				int res = 0;
				int nextMaxCanArrive = 0;
				int nowMaxCanArrive = 0;
				for (size_t i = 0; i < nums.size(); i++)
				{
					if (i>nowMaxCanArrive)
					{
						nowMaxCanArrive = nextMaxCanArrive;
						nextMaxCanArrive = 0;
						if (i > nowMaxCanArrive)
							return false;
					}
					if (nums[i] + i > nextMaxCanArrive)
						nextMaxCanArrive = nums[i] + i;
				}
				return true;
	}
};