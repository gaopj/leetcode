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
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> null;
		if (n == 0)
			return null;
		return create(1, n);
	}
	vector<TreeNode*> create(int s, int e)
	{
		vector<TreeNode*> res;
		if (s > e)
		{
			res.push_back(NULL);
			return res;
		}
		else
		{
			for (size_t i = s; i <=e; i++)
			{
				vector<TreeNode*> left = create(s, i - 1);
				vector<TreeNode*> right = create(i+1, e);
				for (size_t j = 0; j < left.size(); j++)
				{
					for (size_t k = 0; k < right.size(); k++)
					{
						TreeNode* root = new TreeNode(i);
						root->left = left[j];
						root->right = right[k];
						res.push_back(root);
					}
				}

			}
			return res;
		}
	}
};