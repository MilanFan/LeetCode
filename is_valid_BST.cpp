/*
 * is_valid_BST.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: MilanFan
 */

#include <binary_tree.h>
#include <climits>

using namespace std;

class LeetCode {
public:
	bool isValidBST(TreeNode* root) {
		return isBST(root, INT_MIN, INT_MAX);
	}

private:
	bool isBST(TreeNode* p, int lower, int upper) {
		if (!p) return true;

		return isBST(p->left, lower, p->val) &&
				isBST(p->right, p->val, upper) &&
				lower < p->val &&
				p->val < upper;
	}
};
