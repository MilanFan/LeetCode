/*
 * remove_dup_2.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: Milan Fan
 */

using namespace std;

class LeetCode {
public:
	int removeDuplicates2(int A[], int n) {
		if (n<2) return n;

		int idx = 2;
		int count = 0;
		for (int i=2; i<n; i++) {
			if (A[i] != A[i-2-count]) {
				A[idx++] = A[i];
			} else {
				count++;
			}
		}

		return idx;
	}

    int removeDuplicates2_I(int A[], int n) {
        if (n<=2) return n;

        int idx = 0;
        for (int i=2; i<n; i++) {
            if (A[idx] != A[i]) {
                A[idx+2] = A[i];
                idx++;
            }
        }

        return idx+2;
    }
};
