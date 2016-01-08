#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Implemented this version to follow along with the book, however
// could revisit and implement without the use of a helper vector.

void merge(vector<int> &vec, vector<int> helper, int low, int middle, int high) {
	for(int i = low; i <= high; i++) {
		helper[i] = vec[i];
	}

	int helperLeft = low;
	int helperRight = middle + 1; 
	int current = low;

	while(helperLeft <= middle && helperRight <= high) {
		if(helper[helperLeft] <= helper[helperRight]) {
			vec[current] = helper[helperLeft];
			++helperLeft;
		} else {
			vec[current] = helper[helperRight];
			++helperRight;
		}
		++current;
	}

	int remaining = middle - helperLeft;
	for(int i = 0; i <= remaining; i++) {
		vec[current + i] = helper[helperLeft + i];
	}
}

void mergesort(vector<int> &vec, vector<int> helper, int low, int high) {
	if(low < high) {
		int middle = (low + high)/2;
		mergesort(vec, helper, low, middle); // Sort left half 
		mergesort(vec, helper, middle + 1, high); // Sort right half
		merge(vec, helper, low, middle, high); // Merge them
	}
}

void mergesort(vector<int> &vec) {
	vector<int> helper (vec.size());
	mergesort(vec, helper, 0, vec.size() - 1);
}

int main() {
	vector<int> vec = { 53, 21, 8, 19, 2, 11, 5, 32, 87, 12, 1 };

	for(auto x : vec) cout << x << " ";
	cout << endl;

	mergesort(vec);
	
	for(auto x : vec) cout << x << " ";
	cout << endl;

	return 0;
}
