#include<stdio.h>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int max = 0;
	void shendu(TreeNode* root,int level)
	{
		if (root->left == NULL&&root->right==NULL)
		{
			if (level > max)
				max = level;
			return;
		}
		else
		{
			if (root->left != NULL)
			{
				shendu(root->left, level + 1);
			}
			if (root->right != NULL)
			{
				shendu(root->right, level + 1);
			}
		}
	}
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		shendu(root, 1);
		return max;
	}
};