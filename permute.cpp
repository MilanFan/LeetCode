/*
 * permute.cpp
 *
 *  Created on: Jun 4, 2014
 *      Author: MilanFan
 */

#include <vector>

using namespace std;

class LeetCode {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > r;

		perm(r, num, 0, num.size());

		return r;
	}

private:
	void perm(vector<vector<int> > &r, vector<int> &num, int start, int end) {
		if (start < end-1) {
			perm(r, num, start+1, end);
			for (int i=start+1; i<end; i++) {
				swap(num[start], num[i]);
				perm(r, num, start+1, end);
				swap(num[start], num[i]);
			}
		} else {
			r.push_back(num);
		}
	}
};
