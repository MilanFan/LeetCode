/*
 * max_depth.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>

using namespace std;

class LeetCode {
public:
	int maxDepth(TreeNode *root) {
		return depth(root);
	}

private:
	int depth(TreeNode *p) {
		if (!p) return 0;
		return max(depth(p->left), depth(p->right)) + 1;
	}
};
