#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// This algorithm determines if two string are within one edit
// of one another either by replacement, insertion, or deletion.
// For example:
// pale | bale -> True
// pale | ple -> True
// pale | pales -> True
// pale | bakes -> False

bool oneEditReplace(string s1, string s2) {
	bool foundDifference = false;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] != s2[i]) {
			if(foundDifference) return false;
			foundDifference = true;
		}
	}
	return true;
}

bool oneEditInsert(string s1, string s2) {
	int index1 = 0;
	int index2 = 0;
	while(index2 < s2.length() && index1 < s1.length()) {
		if(s1[index1] != s2[index2]) {
			if(index1 != index2) {
				return false;
			}
			index2++;
		} else {
			++index1;
			++index2;
		}
	}
	return true;
}

bool oneEditAway(string s1, string s2) {
	if(s1.length() == s2.length()) return oneEditReplace(s1, s2);
	else if(s1.length() + 1 == s2.length()) return oneEditInsert(s1, s2);
	else if(s1.length() - 1 == s2.length()) return oneEditInsert(s2, s1);
	else return false;
}

int main() {
	string s1 = "apples";
	string s2 = "apples";	
	string s3 = "bananas";
	string s4 = "strawberry";
	string s5 = "books";
	string s6 = "boks";
	string s7 = "boooks";
	string s8 = "baaks";

	cout << oneEditAway(s1, s2) << endl; // True
	cout << oneEditAway(s1, s3) << endl; // False
	cout << oneEditAway(s1, s4) << endl; // False
	cout << oneEditAway(s5, s6) << endl; // True
	cout << oneEditAway(s5, s7) << endl; // True
	cout << oneEditAway(s5, s8) << endl; // False

	return 0;
}
