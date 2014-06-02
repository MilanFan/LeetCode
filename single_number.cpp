/*
 * single_number.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: MilanFan
 */

using namespace std;

class LeetCode {
public:
	int singleNumber(int A[], int n) {
		int r = 0;
		for (int i=0; i<n; i++) {
			r ^= A[i];
		}
		return r;
	}
};
