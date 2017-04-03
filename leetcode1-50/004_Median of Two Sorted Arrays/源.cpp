#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

double findKth(int a[], int m, int b[], int n, int k)
{
	if (m > n)
		return findKth(b, n, a, m, k);
	if (m == 0)
		return b[k - 1];
	if (k == 1)
		return (b[0]<a[0]?b[0]:a[0]);
	int pa =( k/2<m?k/2:m);
	int pb = k - pa;
	if (a[pa - 1] < b[pb - 1])
		return findKth(a+pa, m - pa, b, n, k - pa);
	if (a[pa - 1]>b[pb - 1])
		return findKth(a, m, b + pb, n - pb, k - pb);
	else
		return a[pa - 1];
}

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int a[1000], b[1000];
		for (size_t i = 0; i < nums1.size(); i++)
			a[i] = nums1[i];
		for (size_t i = 0; i < nums2.size(); i++)
			b[i] = nums2[i];
		int m = nums1.size();
		int n = nums2.size();
		int tot = nums1.size() + nums2.size();
		return tot % 2 ? findKth(a, m, b, n, tot / 2 + 1) :( findKth(a, m, b, n, tot / 2) + findKth(a, m, b, n, tot / 2 + 1))/2;
	}
};
int main()
{
	Solution s;
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	double i= s.findMedianSortedArrays(nums1, nums2);

	return 0;
}