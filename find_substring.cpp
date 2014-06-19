/*
 * find_substring.cpp
 *
 *  Created on: Jun 18, 2014
 *      Author: Milan Fan
 */

#include <map>
#include <vector>
#include <string>

using namespace std;

class LeetCode {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> ret;
		size_t sLen = S.size();
		size_t wLen = L.front().size();
		size_t wNum = L.size();
		if(sLen<=0 || wNum<=0 || sLen<wLen*wNum) return ret;

		map<string, int> wCount;
		for (size_t i=0; i<wNum; i++) {
			wCount[L[i]]++;
		}

		for (size_t i=0; i<=sLen-wLen*wNum; i++) {
			map<string, int> cur;
			size_t j = 0;
			while (j < wNum) {
				string word = S.substr(i+j*wLen, wLen);
				if (wCount.find(word) == wCount.end()) break;
				cur[word]++;
				if (cur[word] > wCount[word]) break;
				j++;
			}
			if (j==wNum) ret.push_back(i);
		}

		return ret;
	}
};
