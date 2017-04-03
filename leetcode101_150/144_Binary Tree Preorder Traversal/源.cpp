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
	vector<int> preorderTraversal(TreeNode* root) {
		while (root!=NULL||!stk.empty())
		{
			if (root != NULL)
			{
				while (root!=NULL)
				{
					res.push_back(root->val);
					stk.push(root);
					root = root->left;
				}
			}
			else
			{
				root = stk.top()->right;
				stk.pop();
			}
		}
		return res;
	}
};