#include<stdlib.h>
#include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k < 2)
			return head;
		ListNode * tail = head;
		vector<ListNode*> pvec;
		for (size_t i = 0;tail!=NULL&& i < k; i++)
		{
			pvec.push_back(tail);
			tail = tail->next;
		}
		if (pvec.size() < k)
			return head;
		else
		{
			ListNode* lasthead = tail;
			head = pvec[k-1];
			for (int i = k-1; i >0; i--)
			{
				pvec[i]->next = pvec[i - 1];
			}
			pvec[0]->next = lasthead;
			tail = pvec[0];
			while (lasthead!=NULL)
			{
				ListNode *t = lasthead;
				vector<ListNode*>lvec;
				for (size_t i = 0; t!=NULL&& i < k; i++)
				{
					lvec.push_back(t);
					t = t->next;
				}
				if (lvec.size() < k)
				{
					break;
				}
				else
				{
					lasthead = t;
					t = lvec[k - 1];
					tail->next = t;
					for (int i = k-1; i >0; i--)
					{
						lvec[i]->next = lvec[i - 1];
					}
					lvec[0]->next = lasthead;
					tail = lvec[0];
				}
			}
			return head;
		}
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = new ListNode(2);
	head->next = p;
	for (int i = 3; i < 6; i++)
	{
		ListNode * node = new ListNode(i);
		p->next = node;
		p = p->next;
	}
	Solution s;
	ListNode *res= s.reverseKGroup(head,2);
	return 0;
}