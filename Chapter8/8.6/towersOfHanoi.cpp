#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

class Tower {
	stack<int> disks;
	int index;

	public:
		Tower(int i) {
			index = i;
		}
		
		int getIndex() {
			return index;
		}

		int numDisks() {
			return disks.size();
		}

		void add(int d) {
			if(!disks.empty() && disks.top() <= d) {
				cout << "Error while placing disk: " << d << endl;
			} else {
				disks.push(d);
			}
		}

		void moveTopTo(Tower &t) {
			int top = disks.top();
			disks.pop();
			t.add(top);
		}

		void moveDisks(int n, Tower &dest, Tower &buffer) {
			if(n > 0) {
				moveDisks(n-1, buffer, dest);
				moveTopTo(dest);
				buffer.moveDisks(n-1, dest, *this);
			}
		}
};

int main() {
	int n = 3;
	vector<Tower> towers;

	for(int i = 0; i < 3; i++) {
		towers.push_back(Tower(i));
	}

	for(int i = n - 1; i >= 0; i--) {
		towers[0].add(i);
	}

	cout << "Starting Configuration: " << towers[0].numDisks() << " - " << towers[1].numDisks() << " - " << towers[2].numDisks() << endl;

	towers[0].moveDisks(n, towers[2], towers[1]);

	cout << "Ending Configuration: " << towers[0].numDisks() << " - " << towers[1].numDisks() << " - " << towers[2].numDisks() << endl;
}
