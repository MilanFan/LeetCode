/*
 * remove_dup.cpp
 *
 *  Created on: May 31, 2014
 *      Author: MilanFan
 */

using namespace std;

class LeetCode {
public:
	int removeDuplicates(int A[], int n) {
		int idx = 0;

		if (n<=0) return 0;

		for (int i=1; i<n; i++) {
			while (A[idx] != A[i]) {
				A[++idx] = A[i];
			}
		}

		return idx+1;
	}
};
