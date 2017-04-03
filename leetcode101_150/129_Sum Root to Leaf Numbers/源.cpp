#include<stdio.h>

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	int res=0;
	void preorderT(TreeNode* root, int value)
	{
		if (root)
		{
			int nextvalue = value * 10 + root->val;
			if (root->left == NULL&&root->right == NULL)
			{
				res += nextvalue;
				return;
			}
			else
			{
				preorderT(root->left, nextvalue);
				preorderT(root->right, nextvalue);
			}
		}
	}
	int sumNumbers(TreeNode* root) {
		preorderT(root, 0);
		return res;
	}
};