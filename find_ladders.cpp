/*
 * find_ladders.cpp
 *
 *  Created on: Jun 20, 2014
 *      Author: Milan Fan
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LeetCode {
private:
	vector<vector<string> > m_ret;
	unordered_map<string, vector<string> > m_from;

	void genPath(vector<string> &path, const string &word) {
		path.push_back(word);
		if (0 == m_from[word].size()) {
			m_ret.push_back(path);
			reverse(m_ret.back().begin(), m_ret.back().end());
		} else {
			for (auto iter=m_from[word].begin(); iter!=m_from[word].end(); iter++) {
				genPath(path, *iter);
			}
		}
		path.pop_back();
	}

public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		if (0==start.length() || 0==end.length() || 0==dict.size()) return m_ret;

		vector<unordered_set<string> > cache(2);
		size_t cur = 0;
		size_t pre = 1;
		cache[cur].insert(start);
		while(0 == cache[cur].count(end)) {
			cur = !cur;
			pre = !pre;
			for(auto iter=cache[pre].begin(); iter!=cache[pre].end(); iter++) {
				dict.erase(*iter);
			}
			cache[cur].clear();
			for(auto iter=cache[pre].begin(); iter!=cache[pre].end(); iter++) {
				for (size_t pos=0; pos<iter->size(); pos++) {
					string word = *iter;
					for (char c='a'; c<='z'; c++) {
						if (word[pos] == c) continue;
						word[pos] = c;
						if(dict.count(word) > 0) {
							cache[cur].insert(word);
							m_from[word].push_back(*iter);
						}
					}
				}
			}
			if (0 == cache[cur].size()) return m_ret;
		}

		vector<string> path;
		genPath(path, end);

		return m_ret;
	}
};
