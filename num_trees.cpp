/*
 * num_trees.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: Milan Fan
 */

#include <vector>

using namespace std;

class LeetCode {
	int numTrees(int n) {
		vector<int> count(n+1, 0);
		count[0] = count[1] = 1;

		for (int i=2; i<=n; i++) {
			for (int j=1; j<=i; j++) {
				count[i] += count[j-1] * count[i-j];
			}
		}

		return count[n];
	}
};
