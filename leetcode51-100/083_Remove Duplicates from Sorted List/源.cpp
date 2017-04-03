#include<stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* tail, *newhead,*p;
		newhead = head;
		tail = newhead;
		p = head->next;
		while (p)
		{
			head = p->next;
			if (p->val != tail->val)
			{
				tail->next = p;
				tail = p;
			}
			else
			{
				delete p;
			}
			p = head;
		}
		tail->next = NULL;
		return newhead;
	}
};