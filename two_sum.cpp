#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> um;
		vector<int> r;

		for (int i=0; i<numbers.size(); i++) {
			um[numbers[i]] = i;
		}

		for (int i=0; i<numbers.size(); i++) {
			const int gap = target - numbers[i];
			if (um.find(gap) != um.end() && um[gap] != i) {
				r.push_back(i+1);
				r.push_back(um[gap]+1);
				break;
			}
		}
	
		return r;	
	}
};

int main()
{
	cout << "Two Sum" << endl;

	return 0;
}
