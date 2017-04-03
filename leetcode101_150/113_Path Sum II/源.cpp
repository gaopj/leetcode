#include<stdio.h>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<vector<int>> res;
	void preorder(TreeNode* root, int sum, int now, vector<int>& res0)
	{
		if (root != NULL)
		{
			now += root->val;
			res0.push_back(root->val);
			if (root->left == NULL&&root->right == NULL)
			{
				if (now == sum)
				{
					res.push_back(res0);
				}
			}
			preorder(root->left, sum, now,res0);
			preorder(root->right, sum, now,res0);
			res0.pop_back();
		}	
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return res;
		vector<int> res0;
		preorder(root, sum, 0, res0);
		return res;
	}
};