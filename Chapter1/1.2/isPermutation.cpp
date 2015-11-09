#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

//Done with sorting - no extra space needed O(n log n)
bool isPermutation(string x, string y) {
	if(x.length() != y.length()) return false;
	else {
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if(x == y) return true;
	}
	return false;
}

//Using a separate vector - extra space needed but O(n)
bool isPermutationVector(string x, string y) {
	if(x.length() != y.length()) return false;
	else {
		vector<int> letters(128,0);
		for(auto c : x) {
			letters[int(c)]++;
		}
		for(auto c : y) {
			int index = int(c);
			letters[index]--;
			if(letters[index] < 0) return false;
		}
		return true;
	}
	return false;
}

bool simpleTestTrue() {
	string x = "ABC";
	string y = "CAB";
	if(isPermutationVector(x, y) == true) {
		cout << "PASSED - simpleTestTrue" << endl;
		return true;
	}
	else {
		cout << "FAILED - simpleTestTrue" << endl;
		return false;
	}
}

bool simpleTestFalse() {	
	string x = "ABC";
	string y = "CAA";
	if(isPermutationVector(x, y) == false) {
		cout << "PASSED - simpleTestFalse" << endl;
		return true;
	}
	else {
		cout << "FAILED - simpleTestFalse" << endl;
		return false;
	}
}

//Testing for errors with mutliple of the same character in string
bool complexTestTrue() {
	string x = "ABAACAB";
	string y = "BACAAAB";
	if(isPermutationVector(x, y) == true) {
		cout << "PASSED - complexTestTrue" << endl;
		return true;
	}
	else {
		cout << "FAILED - complexTestTrue" << endl;
		return false;
	}
}

int main() {
	simpleTestTrue();
	simpleTestFalse();
	complexTestTrue();
	return 0;
}
