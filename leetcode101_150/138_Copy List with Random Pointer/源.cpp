#include<stdio.h>

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)
			return head;
		RandomListNode * p = head;
		while (p)
		{
			RandomListNode *nextnode = p->next;
			RandomListNode *temp = new RandomListNode(p->label);
			temp->next = p->next;
			temp->random = p->random;
			p->next = temp;
			p = nextnode;
		}
		p = head;
		RandomListNode *newp = head->next;
		while (p)
		{
			RandomListNode *nextnode = p->next->next;
			RandomListNode *nextnewnode=NULL;
			if (nextnode)
			nextnewnode = newp->next->next;
			if (newp->random)
			newp->random = newp->random->next;
			p = nextnode;
			newp = nextnewnode;
		}

		p = head;
		RandomListNode *newhead = new RandomListNode(-1);
		RandomListNode *newtail = newhead;
       newp = head->next;
		while (p)
		{
			RandomListNode *nextnode = p->next->next;
			RandomListNode *nextnewnode = NULL;
			if (nextnode)
				nextnewnode = newp->next->next;
			p->next = newp->next;
			newtail->next = newp;
			newtail = newp;
			p = nextnode;
			newp = nextnewnode;
		}
		newtail->next = NULL;
		return newhead->next;
	}
};

int main()
{
	RandomListNode *s0 = new RandomListNode(-1);
	RandomListNode *s1 = new RandomListNode(1);
	s0->next = s1;
	s1->random = s0;

	Solution s;
	RandomListNode *res = s.copyRandomList(s0);
	return 0;
}