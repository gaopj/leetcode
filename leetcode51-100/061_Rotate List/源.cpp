#include<cstdlib>

using namespace std;
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;
		int count = 1;
		ListNode*tail = head;
		while (tail->next!=NULL)
		{
			count++;
			tail = tail->next;
		}
		k = k%count;
		if (k == 0)
			return head;
		ListNode* p = head;
		for (int i=0; i < count-k-1; i++)
		{
			p = p->next;
		}
		ListNode* newhead = p->next;;
		tail->next = head;
		p->next = NULL;
		return newhead;	

	}
};