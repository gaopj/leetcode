#include<vector>

using namespace std;
//class Solution {
//public:
//	int jump(vector<int>& nums) {
//		vector<int> step;
//		if (nums.size() < 2)
//			return 0;
//		step.push_back(0);
//		int size = nums.size() - 1;
//		for (size_t i = 1; i <=size; i++)
//		{
//			for (int j =i-1; j>=0; j--)
//			{
//				if (nums[j] + j < i)
//				{
//					step.push_back(step[j+1] + 1); break;
//				}
//				if (j == 0)
//				{
//					step.push_back(1); break;
//				}
//			}
//		}
//		return step[size];
//	}
//};

class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0;
		int nextMaxCanArrive = 0;
		int nowMaxCanArrive = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (i>nowMaxCanArrive)
			{
				res++;
				nowMaxCanArrive = nextMaxCanArrive;
				nextMaxCanArrive = 0;
			}
			if (nums[i] + i > nextMaxCanArrive)
				nextMaxCanArrive = nums[i] + i;
		}
		return res;
	}
};

int main()
{

	return 0;
}