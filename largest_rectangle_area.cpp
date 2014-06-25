/*
 * largest_rectangle_area.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: Milan Fan
 */

#include <vector>
#include <stack>

using namespace std;

class LeetCode {
	int largestRectangleArea(vector<int> &height) {
		stack<int> s;
		height.push_back(0);
		int ret = 0;

		for (int i=0; i<(int)height.size(); ) {
			if (s.empty() || height[i] > height[s.top()]) {
				s.push(i++);
			} else {
				int tmp = s.top();
				s.pop();
				ret = max(ret,
						height[tmp] * (s.empty()?i:i-s.top()-1));
			}
		}

		return ret;
	}
};
