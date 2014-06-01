/*
 * swap_pairs.c
 *
 *  Created on: May 31, 2014
 *      Author: MilanFan
 */

#include <linked_list.h>

using namespace std;

class LeetCode {
public:
	ListNode* swapPairs(ListNode *head) {
		if (!head) return head;

		ListNode dummy = ListNode(-1);
		ListNode *pre = &dummy;
		pre->next = head;
		ListNode *cur = head;
		ListNode *nxt = cur->next;

		while (nxt) {
			cur->next = nxt->next;
			nxt->next = cur;
			pre->next = nxt;
			pre = cur;
			cur = cur->next;
			if (!cur) break;
			nxt = cur->next;
		}

		return dummy.next;
	}
};
