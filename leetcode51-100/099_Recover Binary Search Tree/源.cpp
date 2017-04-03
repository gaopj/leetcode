#include<stdio.h>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* mist1=NULL, *mist2=NULL, *pre=NULL;
	void find(TreeNode* root)
	{
		if (root == NULL){
			return;
		}
		if (root->left != NULL)
			find(root->left);
		if (pre != NULL&&root->val < pre->val)
		{
			if (mist1 == NULL){
				mist1 = pre;
				mist2 = root;
			}
			else
			{
				mist2 = root;
			}
		}
		pre = root;
		if (root->right!=NULL)
			find(root->right);
	}
	void recoverTree(TreeNode* root) {
		find(root);
		if (mist1 != NULL&&mist2 != NULL)
		{
			int temp = mist1->val;
			mist1->val = mist2->val;
			mist2->val = temp;
		}
	}
};