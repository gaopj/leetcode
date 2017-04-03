#include<stdlib.h>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * p1=l1, *p2=l2;
		if (l1 == NULL)
		return l2;
		else if (l2 == NULL)
			return l1;
		else
		{
			ListNode *head;
			ListNode *tail;
			if (l1->val > l2->val)
			{
				head = l2;
				p2=l2->next;
			}
			else
			{
				head = l1;
				p1=l1->next;
			}
			tail = head;
			tail->next = NULL;
			while (p1 != NULL&&p2 != NULL)
			{
				if (p1->val >p2->val)
				{
					tail->next = p2;
					tail =p2;
					p2=p2->next;
				}
				else
				{
					tail->next = p1;
					tail = p1;
					p1=p1->next;
				}
			}
			if (p1)
			{
				tail->next = p1;
			}
			else
			{
				tail->next = p2;
			}
			return head;
		}
	}
};
int main()
{

	return 0;
}