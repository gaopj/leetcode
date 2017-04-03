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
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie) {
		if (ps > pe || is>ie || pe >= preorder.size() || ie >= inorder.size())
			return NULL;
		else if (ps == pe)
		{
			TreeNode* temp = new TreeNode(preorder[ps]);
			return temp;
		}

		else
		{
			TreeNode* temp = new TreeNode(preorder[ps]);

			vector<int>::iterator p = find(inorder.begin(), inorder.end(), preorder[ps]);
			int size = p - inorder.begin()-is;
			temp->left = buildTree1(preorder, inorder, ps + 1, ps + size, is, is + size - 1);
			temp->right = buildTree1(preorder, inorder, ps + size + 1, pe, is + size +1, ie);
			return temp;
		}

	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree1(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};

int main()
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(3);
	//preorder.push_back(4);
	//preorder.push_back(-1);
	//preorder.push_back(2);
	//preorder.push_back(-8);
	//preorder.push_back(11);

	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	//inorder.push_back(4);
	//inorder.push_back(7);
	//inorder.push_back(11);
	//inorder.push_back(-8);
	//inorder.push_back(2);

	Solution s;
	TreeNode*  res = s.buildTree(preorder, inorder);
	return 0;
}