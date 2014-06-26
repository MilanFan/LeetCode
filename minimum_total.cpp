/*
 * minimum_total.cpp
 *
 *  Created on: Jun 25, 2014
 *      Author: Milan Fan
 */
#include <vector>

using namespace std;

class LeetCode {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		for (int i=triangle.size()-2; i>=0; i--) {
			for (int j=i; j>=0; j--) {
//			for (int j=0; j<=i; j++) {
				triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
	}
};
