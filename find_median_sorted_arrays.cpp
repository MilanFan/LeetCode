/*
 * find_median_sorted_arrays.cpp
 *
 *  Created on: Jun 23, 2014
 *      Author: Milan Fan
 */

#include <algorithm>

using namespace std;

class LeetCode {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if ((m+n)%2) {
			return (double)findkth(A, m, B, n, (m+n)/2+1);
		} else {
			return (double)(findkth(A, m, B, n, (m+n)/2) + findkth(A, m, B, n, (m+n)/2+1)) / 2;
		}
	}

private:
	int findkth(int A[], int m, int B[], int n, int k) {
		if (m < n) return findkth(B, n, A, m, k);
		if (0 == n) return A[k-1];
		if (1 == k) return min(A[0], B[0]);

		int pb = min(k/2, n);
		int pa = k - pb;
		if (A[pa-1]>B[pb-1]) return findkth(A, pa, B+pb, n-pb, k-pb);
		return findkth(A+pa, m-pa, B, pb, k-pa);
	}
};
