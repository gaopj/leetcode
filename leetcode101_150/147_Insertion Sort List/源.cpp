#include<cstdio>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

	ListNode* insertionSortList(ListNode* head) {
		ListNode* newhead = new ListNode(-1);
		ListNode* pre = newhead;
		if (head == NULL)
			return head;
		ListNode* p = head->next;
		head->next = NULL;
		newhead->next = head;
		while (p)
		{
			ListNode* temp = p->next;
			ListNode* pre = newhead;
			ListNode*q = newhead->next;
			while (q!=NULL&&p->val>q->val)
			{
				pre = pre->next;
				q = q->next;
			}
			p->next = pre->next;
			pre->next = p;
			p = temp;
		}
		return newhead->next;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(4);
	ListNode* res = s.insertionSortList(head);
	return 0;
}