#include<stdio.h>
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* ArrayToBST(vector<int>& nums, int s, int e)
	{
		if (s == e)
		{
			return new TreeNode(nums[s]);
		}
		else if (s<e)
		{
			int mid = (s + e) / 2;
			TreeNode* midnode = new TreeNode(nums[mid]);
			midnode->left = ArrayToBST(nums, s, mid - 1);
			midnode->right = ArrayToBST(nums, mid+1, e);
			return midnode;
		}
		else
		{
			return NULL;
		}
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return NULL;
		return ArrayToBST(nums, 0, nums.size() - 1);
	}
};