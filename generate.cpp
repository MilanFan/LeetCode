/*
 * generate.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: MilanFan
 */

#include <vector>

using namespace std;

class LeetCode {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > r;
		if (numRows<=0) return r;

		vector<int> row;
		const int one = 1;
		row.push_back(one);
		r.push_back(row);
		if (numRows == 1) return r;

		row.push_back(one);
		r.push_back(row);
		if (numRows == 2) return r;

		for (int i=3; i<=numRows; i++) {
			row.clear();
			row.push_back(one);
			for (int j=1; j<i-1; j++) {
				int val = r[i-2][j-1] + r[i-2][j];
				row.push_back(val);
			}
			row.push_back(one);
			r.push_back(row);
		}

		return r;
 	}
};
