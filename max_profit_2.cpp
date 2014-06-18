/*
 * max_profit_2.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: Milan Fan
 */

#include <vector>

using namespace std;

class LeetCode {
public:
	int maxProfit2(vector<int> &prices) {
		int sum = 0;
		/* NOTE:
		 * 'prices.size()' is 'unsigned int'
		 * so condition cannot be 'i<prices.size()-1'
		 */
		for (int i=1; i<prices.size(); i++) {
			int diff = prices[i] - prices[i-1];
			if (diff > 0) {
				sum += diff;
			}
		}

		return sum;
	}
};
