/*
 * subsets.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: MilanFan
 */

#include <vector>
#include <algorithm>

using namespace std;

class LeetCode {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		size_t len = S.size();
		vector<vector<int> > r;
		if (len<=0) return r;

		sort(S.begin(), S.end());
		size_t size = 1<<len;
		for (size_t i=0; i<size; i++) {
			vector<int> v;
			for (size_t j=0; j<len; j++) {
				if (i & (1<<j)) {
					v.push_back(S[j]);
				}
			}
			r.push_back(v);
		}

		return r;
	}
};
