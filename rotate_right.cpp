/*
 * rotate_right.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: Milan Fan
 */

#include <linked_list.h>

using namespace std;

class LeetCode {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head) return NULL;

		ListNode *p = head;
		int len = 0;
		while (p->next) {
			p = p->next;
			len++;
		}
		len++;
		k %= len;
		p->next = head;
		for (int i=0; i<len-k; i++) {
			p = p->next;
		}
		ListNode *ret = p->next;
		p->next = NULL;

		return ret;
	}
};
