#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
	void levelOrderTraversal(TreeLinkNode *root)
	{
		queue<TreeLinkNode*> Q;
		queue<int> level;
		TreeLinkNode *T;
		TreeLinkNode * head = new TreeLinkNode(-1);
		TreeLinkNode *preT=head ;
		int prel = 1;
		int tlevel;
		if (!root) return;
		Q.push(root);
		level.push(1);
		while (!Q.empty())
		{
			T = Q.front();
			tlevel = level.front();
			Q.pop();
			level.pop();
			if (prel == tlevel)
			{
				preT->next = T;
				preT = T;
			}
			else
			{
				preT->next = NULL;
				preT = T;
				prel = tlevel;
			}
			if (T->left)
			{
				Q.push(T->left);
				level.push(tlevel + 1);
			}
			if (T->right)
			{
				Q.push(T->right);
				level.push(tlevel + 1);
			}
		}
		preT->next = NULL;
	}
	void connect(TreeLinkNode *root) {
		levelOrderTraversal(root);
	}
};

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	Solution s;
	s.connect(root);
	return 0;
}