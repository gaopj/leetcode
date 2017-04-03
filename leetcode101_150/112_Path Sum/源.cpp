#include<stdio.h>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool preorder(TreeNode* root, int sum, int now)
	{
		if (root != NULL)
		{
			now += root->val;
			if (root->left == NULL&&root->right == NULL)
			{
				if (now == sum)
					return true;
				else
					return false;
			}

			return preorder(root->left, sum, now) || preorder(root->right, sum, now);
		}
		return false;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		return	preorder(root, sum, 0);
	}
};