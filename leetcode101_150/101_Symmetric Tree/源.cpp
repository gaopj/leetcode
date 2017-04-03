#include<stdio.h>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool res = true;
	void bianli(TreeNode* left, TreeNode* right)
	{
		if (res == false)
			return;
		if ((left == NULL&&right != NULL) || (left != NULL&&right == NULL))
		{
			res = false;
			return;
		}
		else if (left == NULL&&right == NULL)
		{
			return;
		}
		else
		{
			if (left->val != right->val)
			{
				res = false;
				return;
			}
			else
			{
				bianli(left->left, right->right);
				bianli(left->right, right->left);
			}
		}
		
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		else
		{
			bianli(root->left, root->right);
		}
		return res;
	}
};