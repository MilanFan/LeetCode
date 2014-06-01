/*
 * reorder_list.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: MilanFan
 */

#include <linked_list.h>

using namespace std;

class LeetCode {
public:
	void reorderList(ListNode *head) {
		if (!head) return;

		ListNode *p1 = findMedian(head);
		ListNode *p2 = reverse(p1->next);
		p1->next = NULL;
		merge(head, p2);
	}

private:
	ListNode* findMedian(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast) {
			fast = fast->next;
			if (fast) {
				fast = fast->next;
				slow = slow->next;
			}
		}
		return slow;
	}

	ListNode* reverse(ListNode *p) {
		if (!p) return p;
		ListNode *cur = p;
		ListNode *nxt = p->next;
		p->next = NULL;
		while (nxt) {
			ListNode *tmp = nxt->next;
			nxt->next = cur;
			cur = nxt;
			nxt = tmp;
		}
		return cur;
	}

	void merge(ListNode *p1, ListNode *p2) {
		while (p1 && p2) {
			ListNode *tmp = p1->next;
			p1->next = p2;
			p1 = tmp;
			tmp = p2->next;
			p2->next = p1;
			p2 = tmp;
		}
	}
};
