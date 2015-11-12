#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void reverse(string &s) {
	auto end = --s.end();
	for(auto iter = s.begin(); iter < s.end()-s.length()/2; iter++) {
		char temp = *iter;
		*iter = *end;
		*end = temp;	
		--end;
	}
}

int main() {
	string s = "abcdef";
	cout << "Original String: " << s << endl;
	reverse(s);
	cout << "Reversed String: " << s << endl;	
	return 0;
}
