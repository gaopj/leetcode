#include<stdio.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	ListNode* findmidleftnode(ListNode* head)
	{
		ListNode* findlast=head;
		ListNode* findmid=head;
		ListNode* premid=head;
		while (findlast)
		{
			findlast = findlast->next;
			if (!findlast)
				break;
			findlast = findlast->next;
			if (!findlast)
				break;
			premid = findmid;
			findmid = findmid->next;
		}
		return premid;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head)
			return NULL;
		if (!head->next)
			return new TreeNode(head->val);
		ListNode* premid = findmidleftnode(head);
		ListNode* mid = premid->next;
		TreeNode * root = new TreeNode(mid->val);
		ListNode* righthead = mid->next;
		premid->next = NULL;
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(righthead);
		return root;
	}
};