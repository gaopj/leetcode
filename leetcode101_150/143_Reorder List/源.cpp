#include<stdio.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head)
			return ;
		ListNode* mid = head;
		ListNode* p = head;
		if (!head->next)
			return;
		while (p)
		{
			p = p->next;
			if (!p)
				break;
			p = p->next;
			if (!p)
				break;
			mid = mid->next;
		}
		ListNode* lasthead = new ListNode(-1);
		//lasthead->next = mid->next;
		p = mid->next;
		mid->next = NULL;
		while (p)
		{
			ListNode* temp = p->next;
			p->next = lasthead->next;
			lasthead->next = p;
			p = temp;
		}
		ListNode *pl = lasthead->next;
		p = head;
		while (pl)
		{
			ListNode*temp1 = p->next;
			ListNode*temp2 = pl->next;
			pl->next = p->next;
			p->next = pl;
			p = temp1;
			pl = temp2;
		}
		return;

	}
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	Solution s;
	s.reorderList(head);
	return 0;
}