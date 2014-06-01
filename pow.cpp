/*
 * pow.cpp
 *
 *  Created on: May 31, 2014
 *      Author: MilanFan
 */

using namespace std;

class LeetCode {
public:
	double pow(double x, int n) {
		if (n < 0) return 1.0 / power(x, (unsigned int)(-n));
		return power(x, (unsigned int)n);
	}

private:
	double power(double x, unsigned int n) {
		if (n == 0) return 1.0;

		double r = power(x, n/2);
		if (n%2 != 0) {
			return r*r*x;
		} else {
			return r*r;
		}
	}
};
