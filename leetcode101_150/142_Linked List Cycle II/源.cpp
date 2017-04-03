#include<stdio.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

	ListNode *detectCycle(ListNode *head) {
		ListNode *low = head;
		ListNode *fast = head;
		while (fast)
		{
			low = low->next;
			fast = fast->next;
			if (!fast)
				return NULL;
			fast = fast->next;
			if (fast == low)
			{
				low = head;
				while (low!=fast)
				{
					low = low->next;
					fast = fast->next;
				}
				return low;
			}
		}
		return	NULL;
		
	}
};