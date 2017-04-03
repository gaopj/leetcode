#include<vector>
#include<stdio.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> res;
	void inorder(TreeNode* root)
	{
		if (root)
		{
			inorder(root->left);
			res.push_back(root->val);
			inorder(root->right);
		}
	}
	vector<int> inorderTraversal(TreeNode* root) {
		inorder(root);
		return res;
	}
};