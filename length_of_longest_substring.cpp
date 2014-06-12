/*
 * length_of_longest_substring.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: Milan Fan
 */
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LeetCode {
public:
	int lengthOfLongestSubstringHash(string s) {
		unordered_map<char, int> um;
		int maxLen = 0;
		int start = 0;

		for (size_t i=0; i<s.length(); i++) {
			um[s[i]] = -1;
		}
		int idx = 0;
		while (idx < s.length()) {
			if (um[s[idx]] >= start) {
				maxLen = max(maxLen, idx-start);
				start = um[s[idx]]+1;
			}
			um[s[idx]] = idx;
			idx++;
		}

		return max(maxLen, (int)s.length()-start);
	}

	int lengthOfLongestSubstring(string s) {
		const int bufSize = 256;
		int last[bufSize];
		int maxLen = 0;
		int start = 0;

		for (size_t i=0; i<s.length(); i++) {
			last[(size_t)s[i]] = -1;
		}
		int idx = 0;
		while (idx < s.length()) {
			if (last[(size_t)s[idx]] >= start) {
				maxLen = max(maxLen, idx-start);
				start = last[(size_t)s[idx]]+1;
			}
			last[(size_t)s[idx]] = idx;
			idx++;
		}

		return max(maxLen, (int)s.length()-start);
	}
};
