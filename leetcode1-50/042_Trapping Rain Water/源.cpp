#include<vector>

using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		int l =0;
		int r = height.size()-1;
		int res = 0;
		while (l<r)
		{
			int min = height[l] < height[r] ? height[l] : height[r];
			if (height[l] < height[r])
			{
				l++;
				while (l<r&&height[l]<min)
				{
					res += min - height[l];
					l++;
				}
			}
			else
			{
				r--;
				while (l<r&&height[r]<min)
				{
					res += min - height[r];
					r--;
				}
			}
		}
		return res;

	}
};
int main()
{

	return 0;
}