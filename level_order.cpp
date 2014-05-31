/*
 * level_order.cpp
 *
 *  Created on: May 31, 2014
 *      Author: MilanFan
 */

#include <vector>
#include <queue>
#include <binary_tree.h>

using namespace std;

class LeetCode {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > r;
		if (!root) return r;

		queue<TreeNode *> cur, nxt;

		cur.push(root);
		while(!cur.empty()) {
			vector<int> level;
			while(!cur.empty()){
				TreeNode *p = cur.front();
				cur.pop();
				level.push_back(p->val);
				if (p->left) nxt.push(p->left);
				if (p->right) nxt.push(p->right);
			}
			r.push_back(level);
			swap(cur, nxt);
		}

		return r;
	}
};
