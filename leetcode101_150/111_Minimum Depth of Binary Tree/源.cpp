#include<stdio.h>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int min = 9999;
	void inorder(TreeNode* root,int level)
	{
		if (level > min)
			return;
		if (root)
		{
			if (root->left == NULL&&root->right == NULL)
			{
				if (level < min)
					min = level;
			}
			inorder(root->left, level + 1);
			inorder(root->right, level + 1);
		}

	}
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		else
		{
			inorder(root, 1);
		}
		return min;
	}
};