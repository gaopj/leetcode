#include<stdio.h>
using namespace std;

 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *low = head;
		ListNode *fast = head;
		while (fast)
		{
			low=low->next;
			fast=fast->next;
			if (!fast)
				return false;
			fast = fast->next;
			if (fast == low)
				return true;
		}
	return	false;
	}
};