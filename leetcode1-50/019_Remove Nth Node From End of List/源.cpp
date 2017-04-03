#include<stdlib.h>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int count = 0;
		ListNode *p = head;
		while (p)
		{
			count++;
			p = p->next;
		}
		int pos = count - n;
		if (pos == 0)
		{
			p = head;
			head = head->next;
			free(p);
			return head;
		}
		else
		{
			ListNode *pre = head;
			for (size_t i = 1; i < pos; i++)
			{
				pre = pre->next;
			}
			p = pre->next;
			pre->next = p->next;
			free(p);
			return head;
		}
	}
};
int main()
{
	ListNode *head = new ListNode(1);
	Solution s;
	ListNode *res = s.removeNthFromEnd(head, 1);
	return 0;
}