/*
 * min_depth.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>

using namespace std;

class LeetCode {
public:
	int minDepth(TreeNode *root) {
		return depth(root);
	}

private:
	int depth(TreeNode *p) {
		if (!p) return 0;

		int l = depth(p->left);
		int r = depth(p->right);
		if (!(l || r)) return 1;
		else if (l+r && !(l*r)) return l+r+1;

		return min(l, r) + 1;
	}
};
