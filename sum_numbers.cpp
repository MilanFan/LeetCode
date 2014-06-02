/*
 * sum_numbers.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: MilanFan
 */

#include <stack>
#include <binary_tree.h>

using namespace std;

class LeetCode {
public:
	int sumNumbers(TreeNode *root){
		if (!root)  return 0;
		int r = 0;

		stack<StackNode*> s;
		s.push(new StackNode(root, root->val));

		while (!s.empty()) {
			StackNode *cur = s.top();
			s.pop();
			if (cur->p->right) {
				s.push(new StackNode(cur->p->right, cur->val*10+cur->p->right->val));
			}
			if (cur->p->left) {
				s.push(new StackNode(cur->p->left, cur->val*10+cur->p->left->val));
			}
			if (!cur->p->left && !cur->p->right) {
				r += cur->val;
			}
			delete cur;
		}

		return r;
	}

private:
	struct StackNode {
		TreeNode* p;
		int val;
		StackNode(TreeNode* n, int x) : p(n), val(x) {}
	};
};
