#include<vector>
#include<stdio.h>
#include<queue>
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
	 vector<int> res0;
	 queue<TreeNode*> q;
	 queue<int> l;
	 vector<vector<int>> levelOrder(TreeNode* root) {
		 if (!root)
			 return res;
		 TreeNode* T;
		 int level = 0;
		 int nowlevel = 0;
		 q.push(root);
		 l.push(0);
		 while (!q.empty())
		 {
			 T = q.front();
			 level = l.front();
			 q.pop();
			 l.pop();
			 if (level == nowlevel)
				 res0.push_back(T->val);
			 else
			 {
				 nowlevel = level;
				 res.push_back(res0);
				 res0.clear();
				 res0.push_back(T->val);
			 }
			 if (T->left)
			 {
				 q.push(T->left);
				 l.push(level + 1);
			 }
			 if (T->right)
			 {
				 q.push(T->right);
				 l.push(level + 1);
			 }
		 }
		 if (res0.size() > 0)
			 res.push_back(res0);
		 return res;
	 }
 };

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;

	vector<vector<int>> res = s.levelOrder(root);
}