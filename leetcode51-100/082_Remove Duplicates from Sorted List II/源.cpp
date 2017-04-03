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
		ListNode* tail, *newhead, *p;
		bool flag = false;
		ListNode *res = new ListNode(-1);
		ListNode * pre = res;
		newhead = head;
		res->next = newhead;
		tail = newhead;
		p = head->next;
		while (p)
		{
			head = p->next;
			if (p->val != tail->val)
			{
				if (flag)
				{
					flag = false;
					pre->next = p;
					delete tail;
					tail = p;
				}
				else
				{
					tail->next = p;
					pre = tail;
					tail = p;
				}

			}
			else 
			{
				if (flag == false)
					flag = true;
				delete p;
			}
			p = head;
		}
		if (flag)
		{
			flag = false;
			pre->next = NULL;
			delete tail;
		}
		tail->next = NULL;
		newhead = res->next;
		return newhead;
	}
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	//head->next->next = new ListNode(2);
	ListNode * res = s.deleteDuplicates(head);
	return 0;

}