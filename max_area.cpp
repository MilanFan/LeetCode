/*
 * max_area.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: Milan Fan
 */

#include <vector>

using namespace std;

class LeetCode {
public:
	int maxArea(vector<int> &height) {
		int ret = 0;
		int start = 0;
		int end = height.size()-1;
		while (start < end) {
			int area = min(height[start], height[end]) * (end-start);
			ret = max (area, ret);
			if (height[start] < height[end]) {
				start++;
			} else {
				end--;
			}
		}

		return ret;
	}
};
