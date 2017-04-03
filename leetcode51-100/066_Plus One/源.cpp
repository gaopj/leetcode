#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res;
		int jinwei = 0;
		int i = digits.size() - 1;
		int num = digits[i] + jinwei+1;
		jinwei = num / 10;
		num = num % 10;
		res.push_back(num);
		for ( i--; i >=0; i--)
		{
			int num = digits[i] + jinwei;
			jinwei = num / 10;
			num = num % 10;
			res.push_back(num);
		}
		if (jinwei)
			res.push_back(jinwei);
		for (int low=0,high=res.size()-1; low<high; low++,high--)
		{
			int temp = res[high];
			res[high] = res[low];
			res[low] = temp;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(1);
	s0.push_back(0);
	vector<int>res = s.plusOne(s0);
	return 0;
}