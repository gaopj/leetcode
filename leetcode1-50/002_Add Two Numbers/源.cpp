#include<stdlib.h>
#include<iostream>

using namespace std;

 struct ListNode {
   int val;
  ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *head = new ListNode(0);
		ListNode *tail = head;
		int jinwei = 0;
		while (p1!=NULL&&p2!=NULL)
		{
			
		ListNode*	p = new ListNode(p1->val+p2->val+jinwei);
		if (p->val >= 10)
		{
			jinwei = 1;
			p->val -= 10;
		}
		else
		{
			jinwei = 0;
		}
		tail->next = p;
		tail = p;
		p1 = p1->next;
		p2 = p2->next;
		}
		if (p2 != NULL)
			p1 = p2;
		while (p1 != NULL)
		{
			ListNode*	p = new ListNode(p1->val + jinwei);
			if (p->val >= 10)
			{
				jinwei = 1;
				p->val -= 10;
			}
			else
			{
				jinwei = 0;
			}
			tail->next = p;
			tail = p;
			p1 = p1->next;
		}

		if (jinwei)
		{
			ListNode*	p = new ListNode(1);
			tail->next = p;
		}
		return head->next;
	}
};

int main()
{
	ListNode a1(2);
	ListNode b1(4);
	ListNode c1(3);
	a1.next = &b1;
	b1.next = &c1;
	ListNode a2(5);
	ListNode b2(6);
	ListNode c2(4);
	a2.next = &b2;
	b2.next = &c2;

	ListNode *p;
	ListNode *p1 = &a1;
		ListNode *p2 = &a2;
		Solution s;
	p= s.addTwoNumbers(p1,p2);

	return 0;
}