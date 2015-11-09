#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string urlify(string s) {
	string ret = "";
	bool notSeenCharacter = true;
	for(int i = s.length()-1; i >= 0; i--) {
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
	return 0;
}
