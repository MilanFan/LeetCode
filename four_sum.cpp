/*
 * four_sum.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: Milan Fan
 */

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LeetCode {

public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > ret;
		if (num.size() < 4) return ret;
//		sort(num.begin(), num.end());

		unordered_map<int, vector<pair<size_t, size_t> > > um;
		size_t len = num.size();
		for (size_t i=0; i<len; i++) {
			for (size_t j=i+1; j<len; j++) {
				um[num[i]+num[j]].push_back(pair<size_t, size_t>(i, j));
			}
		}
		for (size_t i=0; i<len; i++) {
			for (size_t j=i+1; j<len; j++) {
				const int key = target - num[i] - num[j];
				if (um.find(key) == um.end()) continue;
				const auto& found = um[key];
				for (size_t k=0; k<found.size(); k++) {
//				    if (j >= found[k].first) continue;
//				    ret.push_back( {num[i], num[j], num[found[k].first], num[found[k].second]} );
//					or
//				    if (i <= found[k].second) continue;
//				    ret.push_back( {num[found[k].first], num[found[k].second], num[i], num[j]} );
					if (i==found[k].first || i==found[k].second ||
							j==found[k].first || j==found[k].second)
						continue;
					vector<int> v = {num[i], num[j], num[found[k].first], num[found[k].second]};
					sort(v.begin(), v.end());
					ret.push_back(v);
				}
			}
		}

		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());

		return ret;
	}
};
