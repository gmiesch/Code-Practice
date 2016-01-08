#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

using std::to_string;

// Compresses a string using the counts of repeated characters.
// Only returns the compressed string if the compressed string
// is smaller is size than the original string, otherwise it 
// returns back the original string.

string stringCompress(string s) {
	string ret = "";

	for(int index = 0; index < s.size(); index++) {
		int letterCount = 1;
		while(s[index] == s[index + 1]) {
			letterCount++;
			index++;
		}
		ret += s[index];
		ret += to_string(letterCount);
		
	if(ret.size() > s.size()) return s;
	}
	return ret;
}


// First implementation that revolved too heavily around characters
// and working backwards through the input string instead of forwards.

string stringCompressOld(string s) {
	string ret = "";

	for(int index = s.length()-1; index >= 0; index--) {
		int letterCount = 1;
		while(s[index] == s[index - 1]) {
			letterCount++;
			index--;
		}
		// Works through inserting each digit of letterCount incase the
		// value of it is higher than 9
		while(letterCount != 0) {
			int digit = letterCount % 10;
			ret.insert(ret.begin(),digit+48);
			letterCount-=digit;
			letterCount/=10;
		}
		ret.insert(ret.begin(), s[index]);

		if(ret.size() > s.size()) return s; // If at any point the return is larger than or equal to the original string, return the original string
	}
	return ret;
}

int main() {
	cout << stringCompress("blue") << endl;
	cout << stringCompress("apple") << endl;
	cout << stringCompress("aabcccccaaa") << endl;
	cout << stringCompress("aabccccccccccccccccccccccccccccccccccccccccccccccccccccccaaa") << endl;;

	return 0;	
}
