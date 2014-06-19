/*
 * add_two_numbers.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: Milan Fan
 */

#include <linked_list.h>

using namespace std;

class LeetCode {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ret = NULL;
		if (!l1 && !l2) return ret;

		int carry = 0;
		ListNode *pre = ret;
		while (l1 && l2) {
			int tmp = l1->val + l2->val + carry;
			ListNode *p = new ListNode(tmp%10);
			if (pre)
				pre->next = p;
			else ret = p;
			pre = p;
			carry = tmp / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode *l3 = l1 ? l1 : l2;
		while (l3) {
			int tmp = l3->val + carry;
			ListNode *p = new ListNode(tmp%10);
			if (pre)
				pre->next = p;
			else
				ret = p;
			pre = p;
			carry = tmp / 10;
			l3 = l3->next;
		}
		if (carry) {
			ListNode *p = new ListNode(carry);
			pre->next = p;
		}

		return ret;
	}
};
