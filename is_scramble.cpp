/*
 * is_scramble.cpp
 *
 *  Created on: Jun 12, 2014
 *      Author: Milan Fan
 */

#include <string>

using namespace std;

class LeetCode {
public:
	bool isScramble_Recursive(string s1, string s2) {
		if (s1.length() != s2.length()) return false;

		const int len = s1.length();

		if (1==len) {
			return s1[0]==s2[0];
		}

		const int bufSize = 26;
		int count[bufSize] = {0};

		for (int i=0; i<len; i++) {
			count[s1[i]-'a']++;
			count[s2[i]-'a']--;
		}

		for (int i=0; i<bufSize; i++) {
			if(count[i] != 0) return false;
		}

		for (int i=1; i<len; i++) {
			bool ret = (isScramble_Recursive(s1.substr(0,i), s2.substr(0,i)) &&
					isScramble_Recursive(s1.substr(i,len-i), s2.substr(i,len-i))) ||
					(isScramble_Recursive(s1.substr(0,i), s2.substr(len-i,i)) &&
					isScramble_Recursive(s1.substr(i,len-i), s2.substr(0,len-i)));
			if (ret) return true;
		}

		return false;
	}

	bool isScramble_DP(string s1, string s2) {
		const int N = s1.size();
		if (N != (int)s2.size()) return false;

		bool f[N+1][N][N];
		fill(&f[0][0][0], &f[N][N-1][N-1], false);
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				f[1][i][j] = s1[i]==s2[j];
			}
		}

		for (int n=1; n<=N; n++) {
			for (int i=0; i+n<=N; i++) {
				for (int j=0; j+n<=N; j++) {
					for (int k=1; k<n; k++) {
						if ((f[k][i][j] && f[n-k][i+k][j+k]) ||
								(f[k][i][j+n-k] && f[n-k][i+k][j])) {
							f[n][i][j] = true;
							break;
						}
					}
				}
			}
		}

		return f[N][0][0];
	}
};
