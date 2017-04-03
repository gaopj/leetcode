#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	void prem(vector<int> &num, int i,string &res,int &count,int k)
//	{
//		if (count > k)
//			return;
//		if (i == num.size())
//		{
//			count++;
//			if (count == k)
//			{
//				for (size_t i = 0; i < num.size(); i++)
//				{
//					res += (num[i]+'0');
//				}
//				return;
//			}
//		}
//		else
//		{
//			if (count>k)
//				return;
//			vector<int>::iterator it = num.begin() + i;
//			sort(it, num.end());
//			for (size_t j = i; j < num.size(); j++)
//			{
//				swap(num[i], num[j]);
//				prem(num, i + 1, res,count,k);
//				vector<int>::iterator it = num.begin() + i;
//				sort(it, num.end());
//				//swap(num[j], num[i]);
//			}
//		}
//
//	}
//
//	string getPermutation(int n, int k) {
//		vector<int> nums;
//		int count = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			nums.push_back(i + 1);
//		}
//		string res;
//		prem(nums, 0, res, count, k);
//		return res;
//	}
//};

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums(n);
		int pcount = 1;
		for (size_t i = 0; i < n; i++)
		{
			nums[i] = i + 1;
			pcount *= (i + 1);
		}
		k--;
		string res = "";
		for (size_t i = 0; i < n; i++)
		{
			pcount = pcount / (n - i);
			int num = k / pcount;
			res += (nums[num] + '0');
			vector<int>::iterator p = nums.begin() + num;
			nums.erase(p);
			k = k%pcount;
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.getPermutation(2, 1);
	return 0;
}