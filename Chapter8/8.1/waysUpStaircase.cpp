#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// This function recursively computes the possible numbers of ways up 
// a staircase if you can hop either 1, 2, or 3 steps at a time
int waysUpStaircaseMemo(int stepsLeft, vector<int> memo) {
	if(stepsLeft < 0) {
		return 0;
	} else if (stepsLeft == 0) {
		return 1;
	} else if (memo[stepsLeft] != -1) {
		return memo[stepsLeft];
	} else {
		memo[stepsLeft] = waysUpStaircaseMemo(stepsLeft-1, memo) +
						  waysUpStaircaseMemo(stepsLeft-2, memo) +
						  waysUpStaircaseMemo(stepsLeft-3, memo);
		return memo[stepsLeft];
	}
}

int waysUpStaircase(int stepsLeft) {
	vector<int> memo (stepsLeft+1, -1);
	return waysUpStaircaseMemo(stepsLeft, memo);
}

int main() {
	cout << waysUpStaircase(8) << endl;
	return 0;
}
