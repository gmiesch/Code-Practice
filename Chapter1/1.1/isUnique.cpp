#include <iostream>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

unordered_set<int> set;

bool isUnique(string s) {
	if(s.size() > 128) return false; //Too many characters for them all to be unique
	for(int i = 0; i <= s.size(); i++) {
		if(set.count(s[i]) >= 1) return false;
		else set.insert(s[i]);
	}
	return true;
}

//Alternatively I could have sorted the string and then run through and checked if any character appeared more than once
bool isUniqueWithoutDataStructure(string s) {
	if(s.size() > 128) return false; //Too many characters for them all to be unique
	for(int i = 0; i <= s.size(); i++) {
		for(int j = i + 1; j <= s.size(); j++) {
			if(s[i] == s[j]) {
				return false;
			}
		}
	}
	return true;
}

void isUniqueTest() {
	bool ret = isUnique("abcdefgzw123456789z"); //Is not unique
	set.clear();
	bool ret2 = isUnique("fjuwiqaz61AeB"); //Is unique
	if(ret != false) {
		cout << "FAILED - isUnique on a non-unique string" << endl;
		return;
	}
	if(ret2 != true) {
		cout << "FAILED - isUnique on a unique string" << endl;	
		return;
	}
	cout << "PASSED - isUnique" << endl; 
}

void isUniqueWithoutDataStructureTest() {
	bool ret = isUniqueWithoutDataStructure("howdyapples"); //Is not unique
	bool ret2 = isUniqueWithoutDataStructure("AaBbCcDd12345"); //Is unqiue
	if(ret != false) {
		cout << "FAILED - isUniqueWithoutDataStructure on a non-unique string" << endl;
		return;
	}
	if(ret2 != true) {
		cout << "FAILED - isUniqueWithoutDataStructure on a unique string" << endl;
		return;
	}
	cout << "PASSED - isUniqueWithoutDataStructure" << endl;
}


int main() {
	cout << endl;
	isUniqueTest();
	isUniqueWithoutDataStructureTest();
	cout << endl;
	return 0;
}
