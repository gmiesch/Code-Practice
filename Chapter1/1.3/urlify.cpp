#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string urlify(string s) {
	string ret = "";
	int startIndex = s.length()-1;
	while(s[startIndex] == ' ') {
		if(startIndex <= 0) return ret; // Handles issues of empty string and string of only spaces
		else startIndex--;
	}

	bool notSeenCharacter = true;
	for(int i = startIndex; i >= 0; i--) {
		if(s[i] == ' ' && s[i-1] != ' ') {
			ret.insert(ret.begin(), '0');
			ret.insert(ret.begin(), '2');
			ret.insert(ret.begin(), '%');
		} else if (s[i] != ' ') {
			ret.insert(ret.begin(), s[i]);
		} 
	}
	return ret;
}


int main() {
	cout << urlify("app les   ") << endl;;
	cout << urlify("a p p l e s ") << endl;
	cout << urlify("app   les") << endl;
	cout << urlify("") << endl;
	cout << urlify("   ") << endl;
	return 0;
}
