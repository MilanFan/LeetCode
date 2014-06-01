/*
 * flatten.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: MilanFan
 */

#include <binary_tree.h>
#include <stack>

using namespace std;

class LeetCode {
public:
	void flatten(TreeNode *root) {
		if (!root) return;

		stack<TreeNode*> s;
		s.push(root);

		while(!s.empty()) {
			TreeNode *cur = s.top();
			s.pop();
			if (cur->right) {
				s.push(cur->right);
			}
			if (cur->left){
				s.push(cur->left);
			}
			cur->left = NULL;
			if (!s.empty())
				cur->right = s.top();
		}
	}
};
