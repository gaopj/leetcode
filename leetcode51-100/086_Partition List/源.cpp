#include<stdio.h>
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head)
			return head;
		ListNode* bigger = new ListNode(-1);
		ListNode *smaller = new ListNode(-1);
		ListNode *stail = smaller;
		ListNode *btail = bigger;
		ListNode* newhead = new ListNode(-1);
		ListNode* p = head;
		while (p)
		{
			head = p->next;
			if (p->val < x)
			{
				stail->next = p;
				stail = p;
			}
			else
			{
				btail->next = p;
				btail = p;
			}
			p = head;
		}
		stail->next = bigger->next;
		btail->next = NULL;
		newhead->next = smaller->next;

		return newhead->next;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(2);
	head->next = new ListNode(1);
	ListNode* res=  s.partition(head, 2);

	return 0;
}