/*
 * first_missing_positive.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: Milan Fan
 */

#include <algorithm>

using namespace std;

class LeetCode {
public:
	int firstMissingPositive (int A[], int n) {
		bucketSort(A, n);
		int i=0;
		while (i<n && A[i]==i+1) {
			i++;
		}

		return i+1;
	}

private:
	void bucketSort(int A[], int n) {
		for (int i=0; i<n; i++) {
			while (A[i]>0 && A[i]!=i+1 && A[i]<=n && A[i]!=A[A[i]-1]) {
				swap(A[i], A[A[i]-1]);
			}
		}
	}
};
