#include<stdio.h>
#include<vector>
#include<stack>
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
	stack<TreeNode*>stk;
	stack<bool>isvisit;
	vector<int> postorderTraversal(TreeNode* root) {
		if (root != NULL)
		{
			stk.push(root);
			isvisit.push(false);
		}
		TreeNode* cur = NULL;
		bool nowisvisit;
		while (!stk.empty())
		{
			cur = stk.top();
			nowisvisit = isvisit.top();
			if (nowisvisit)
			{
				res.push_back(cur->val);
				stk.pop();
				isvisit.pop();
			}
			else
			{
				isvisit.pop();
				isvisit.push(true);
				if (cur->right)
				{
					isvisit.push(false);
					stk.push(cur->right);
				}
				if (cur->left)
				{
					isvisit.push(false);
					stk.push(cur->left);
				}
			}
		}
		return res;
	}
};