#include<stdio.h>
#include<cmath>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int treeheight(TreeNode* root)
	{
		if (!root)
			return 0;
		else
		{
			int left = treeheight(root->left);
			int right = treeheight(root->right);
			return 1 + (left > right ? left : right);
		}

	}

	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		int leftheight = treeheight(root->left);
		int rightheight = treeheight(root->right);
		int chaju = abs(leftheight - rightheight);
		return chaju <= 1 && isBalanced(root->left) && isBalanced(root->right);
		
	}
};