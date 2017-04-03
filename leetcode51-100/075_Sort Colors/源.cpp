#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 1)
			return;
		int now0 = 0, now2 = nums.size()-1, p0 = 0, p2 = nums.size()-1;
		while (p0<=now2||p2>=now0)
		{
			p0 = now0;
			while (p0<=now2&&nums[p0]!=0)
			{
				p0++;
			}
			if (p0 <=now2)
			{
				if (now0 != p0)
				{
					int temp = nums[p0];
					nums[p0] = nums[now0];
					nums[now0] = temp;
					now0++;
				}
				else
				{
					now0++;
				}
			}
			p2 = now2;
			while (p2>=now0&&nums[p2] != 2)
			{
				p2--;
			}
			if (p2 >= now0)
			{
				if (now2 != p2)
				{
					int temp = nums[p2];
					nums[p2] = nums[now2];
					nums[now2] = temp;
					now2--;
				}
				else
				{
					now2--;
				}
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> s0;

	int a[] = { 2, 2, 1, 2, 1, 1, 1, 0, 0, 2, 1, 0, 2, 1, 2, 2, 1, 1, 1, 1, 1, 0, 2, 0, 2, 0, 2, 2, 1, 0, 2, 1, 0, 2, 1, 2, 0, 0, 0, 0, 2, 1, 1, 2, 0, 1, 2, 2, 0, 0, 2, 2, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 2, 2, 2, 1, 0, 0, 2, 1, 0, 1, 0, 2, 2, 1, 2, 1, 1, 2, 1, 1, 0, 0, 2, 1, 0, 0 };
	int len = (sizeof(a) / sizeof(a[0]));
	for (size_t i = 0; i < len; i++)
	{
		s0.push_back(a[i]);
	}

	s.sortColors(s0);
	return 0;
}

