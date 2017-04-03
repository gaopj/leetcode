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
	int max = INT_MIN;

       int maxSum(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}

		int  value = root->val;
		int  lmax = 0;
		int  rmax = 0;
		if (root->left != NULL) {
			lmax = maxSum(root->left);
			if (lmax>0) {
				value += lmax;
			}
		}

		if (root->right != NULL) {
			rmax = maxSum(root->right);
			if (rmax>0) {
				value += rmax;
			}
		}
		//更新最大值
		//max is the max of {root.val,root.val+lmax,root.val+rmax, root.val + lmax + rmax}
		if (value>max) {
			max = value;
		}
		//返回值
		//return max of (root.val, root.val + lmax, root.val + rmax)
		int l = root->val + lmax;
		int r = root->val + rmax;
		int bigger = (l > r ? l : r);
		return  (root->val > bigger ? root->val : bigger);
	}

	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		maxSum(root);
		return max;
	}
};