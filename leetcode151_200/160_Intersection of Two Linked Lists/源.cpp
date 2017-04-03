#include<stdio.h>
#include<math.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int count1 = 0;
		int count2 = 0;
		ListNode *p1 = headA;
		ListNode *p2 = headB;
		while (p1)
		{
			count1++;
			p1 = p1->next;
		}
		while (p2)
		{
			count2++;
			p2 = p2->next;
		}

		int longlist = (count1 > count2 ? count1 : count2);
		int shortlist = (count1 < count2 ? count1 : count2);
		if (longlist == count1)
		{
			p1 = headA;
			p2 = headB;
		}
		else
		{
			p1 = headB;
			p2 = headA;
		}
		for (int i = 1; i <= longlist; i++)
		{
			if (i <= longlist - shortlist)
			{
				p1 = p1->next;
			}

			else
			{
				if (p1->val == p2->val)
					return p1;
				else
				{
					p1 = p1->next;
					p2 = p2->next;
				}
			}
		}
		return NULL;
	}
};