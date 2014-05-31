/*
 * two_sum.cpp
 *
 *  Created on: May 30, 2014
 *      Author: MilanFan
 */

#include <vector>
#include <unordered_map>

using namespace std;

class LeetCode {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> um;
		vector<int> r;

		for (size_t i=0; i<numbers.size(); i++) {
			um[numbers[i]] = i;
		}

		for (size_t i=0; i<numbers.size(); i++) {
			const int gap = target - numbers[i];
			if (um.find(gap) != um.end() && um[gap] != (int)i) {
				r.push_back(i+1);
				r.push_back(um[gap]+1);
				break;
			}
		}
	
		return r;	
	}
};

