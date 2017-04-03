#include<stdio.h>
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;
		ListNode* newhead = new ListNode(-1);
		newhead->next = head;
		ListNode* pre = newhead;
		ListNode *p = head;
		for (size_t i = 1; i < m; i++)
		{
			p = p->next; pre = pre->next;
		}
		ListNode* parttail = p;
		ListNode*parthead = p;
	//	ListNode* newpre = parttail;
		p = p->next;
		for (size_t i = m+1; i < n; i++)
		{
			ListNode* nextnode = p->next;
			p->next = parthead;
			parthead = p;
			p = nextnode;
		}
		ListNode* nextpart = p->next;
		if (p->next != NULL)
		{
			p->next = parthead;
			parthead = p;
			pre->next = parthead;
			parttail->next = nextpart;
		}
		else
		{
			pre->next = p;
			p->next = parthead;
			parttail->next = NULL;
		}
			return newhead->next;
	}
};


int main()
{
	Solution s;
	ListNode*s0 = new ListNode(1);
	s0->next = new ListNode(2);
	s0->next->next = new ListNode(3);
	ListNode* res = s.reverseBetween(s0,1,2);
	
	return 0;
}