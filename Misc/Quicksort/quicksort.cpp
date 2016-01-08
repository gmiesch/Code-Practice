#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int partition(vector<int> &vec, int left, int right) {
	int pivot = vec[(left + right)/2];
	while(left <= right) {
		while(vec[left] < pivot) ++left;
		while(vec[right] > pivot) --right;
		if(left <= right) {
			int temp = vec[left]; 
			vec[left] = vec[right];
			vec[right] = temp;
			left++;
			right++;
		}
	}
	return left;
}

void quicksort(vector<int> &vec, int left, int right) {
	int index = partition(vec, left, right);
	if(left < index - 1) {
		quicksort(vec, left, index - 1);
	}
	if(index < right) {
		quicksort(vec, index, right);
	}
}

int main() {

	vector<int> vec = { 15, 21, 7, 41, 32, 3, 1, 18, 25 };

	for(auto x : vec) {
		cout << x << " ";
	}
	cout << endl;

	quicksort(vec, 0, vec.size());

	for(auto x : vec) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
