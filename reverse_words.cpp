/*
 * reverse_words.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: MilanFan
 *
 *  1) reverse each word, remove whitespace;
 *  2) reverse the whole words;
 *  Notes:  string passed as value not address,
 *          to pass as address, use "&".
 */

#include <string>

using namespace std;

class LeetCode {
public:
	void reverseWords(string &s) {
		size_t len = 0;
		size_t pos = 0;
		while (pos < s.length()) {
			while (s[pos]==' ' && pos<s.length()) {
				pos++;
			}
			if (len>0 && pos<s.length()) s[len++]=' ';
			size_t start = len;
			while (s[pos]!=' ' && pos<s.length()) {
				s[len++] = s[pos++];
			}
			reverse(s, start, len-1);
		}
		s.resize(len);
		reverse(s, 0, len-1);
	}

private:
	void reverse(string &s, int start, int end) {
		while (start < end) {
			char tmp = s[start];
			s[start++] = s[end];
			s[end--] = tmp;
		}
	}
};
