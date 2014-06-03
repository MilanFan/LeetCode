/*
 * longest_valid_parentheses.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: MilanFan
 */

#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class LeetCode {
public:
	/* stack */
	int longestValidParentheses_Stack(string s) {
		int len = 0;
		int last = -1;	// the last unmatched parentheses -
						// an unmatched parentheses is actually
						// a barrier between two matched groups
		stack<int> left;

		for (int i=0; i<(int)s.size(); i++) {
			if (s[i] == '(') {
				left.push(i);
			} else if (s[i] == ')') {
				if (left.empty()) {
					last = i;
				} else {
					left.pop();
					if (left.empty()) {
						len = max(len, i-last);
					} else {
						len = max(len, i-left.top());
					}
				}
			} else {
				return -1;
			}
		}

		return len;
	}

	/* dynamic programming */
	int longestValidParentheses_DP(string s) {
		int len = 0;
		int n = s.size();
		vector<int> dp(n, 0);

		for (int i=n-2; i>=0; i--) {
			int matchIdx = i+dp[i+1]+1;
			if (s[i]=='(' && s[matchIdx]==')' && matchIdx<n) {
				dp[i] = dp[i+1] + 2;
				if (matchIdx+1<n)
					dp[i] += dp[matchIdx+1];
			}
			len = max(len, dp[i]);
		}

		return len;
	}

};
