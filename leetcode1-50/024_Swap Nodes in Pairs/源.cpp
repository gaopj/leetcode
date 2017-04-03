#include<stdlib.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p1 = head;
		if (!p1)
			return head;
		ListNode * p2 = p1->next;
		while (p1!=NULL&&p2!=NULL)
		{
			int temp = p1->val;
			p1->val = p2->val;
			p2->val = temp;
			p1 = p2->next;
			if (NULL != p1)
				p2 = p1->next;
		}
		return head;
	}
};
int main()
{

	return 0
		;
}