#include<stdio.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next&&fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* mid = slow->next;
		slow->next = NULL;
		ListNode* list1 = sortList(head);
		ListNode* list2 = sortList(mid);
		ListNode* sorted = merge(list1, list2);
		return sorted;
	}
	ListNode* merge(ListNode* list1, ListNode* list2)
	{
		if (!list1) return list2;
		if (!list2) return list1;
		ListNode* newhead = new ListNode(-1);
		ListNode*tail = newhead;
		while (list1&&list2)
		{
			if (list1->val < list2->val)
			{
				tail->next = list1;
				tail = list1;
				list1 = list1->next;
			}
			else
			{
				tail->next = list2;
				tail = list2;
				list2 = list2->next;
			}
		}
		if (list1) tail->next = list1;
		if (list2)tail->next = list2;
		return newhead->next;
	}
};