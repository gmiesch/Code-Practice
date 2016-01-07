#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Binary Search algorithm that must be run on a
// sorted vector of Intgers.
int binarySearch(vector<int> vec, int target) {
	int low = 0;
	int high = vec.size() - 1;

	while(low <= high) {
		int mid = low + (high - low)/2;
		if(vec[mid] == target) return mid;
		else if(vec[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int main() {
	vector<int> vec = { 1, 2, 4, 7, 13, 25, 31, 33, 47, 50 };

	cout << binarySearch(vec, 1) << endl; // Return -> 0
	cout << binarySearch(vec, 4) << endl; // Return -> 2 	
	cout << binarySearch(vec, 13) << endl; // Return -> 4 
	cout << binarySearch(vec, 47) << endl; // Return -> 8 
	cout << binarySearch(vec, 50) << endl; // Return -> 9

	cout << binarySearch(vec, 3) << endl; // Return -> -1 

	return 0;
}
