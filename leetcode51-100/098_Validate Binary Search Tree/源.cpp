#include<stdio.h>
#include<limits.h>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	long long pre = -99999999999;
	bool res = true;
	void inorder(TreeNode* root)
	{
		if (res == false)
			return;
		if (root)
		{
			inorder(root->left);
			if (pre >= root->val)
			{
				res = false;
				return;
			}
			else
			{
				pre = root->val;
			}
			inorder(root->right);
		}
	}
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		if (root->left == NULL&&root->right == NULL)
			return true;
		inorder(root);
		return res;
	}
};