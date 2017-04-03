#include<stdio.h>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* tail;
	void preorder(TreeNode* root)
	{
		if (root)
		{
			TreeNode* righttree = root->right;
			TreeNode* lefttree = root->left;
			root->left = NULL;
			root->right = NULL;
			tail->right = root;
			tail = root;
			preorder(lefttree);
			preorder(righttree);
		}
	}

	void flatten(TreeNode* root) {
		if (!root)
			return;
		if (root->left == NULL&&root->right == NULL)
			return;
		TreeNode* head = new TreeNode(-1);
        tail = head;
		preorder(root);
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	s.flatten(root);

	return 0;
}