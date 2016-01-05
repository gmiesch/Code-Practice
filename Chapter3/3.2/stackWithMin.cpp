#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

//Each Node will keep track of the minimum at
//that given level in the stack, then looking
//for the minimum is as easy as looking at what
//the top Node thinks the minumum is
struct StackNodeWithMin {
	int data;
	int minInStack;
	StackNodeWithMin *next;

	StackNodeWithMin(int d): data{d}, next{nullptr} { }
};

class StackWithMin {
	StackNodeWithMin *top;	

	public:
		StackWithMin(int d) {
			top = new StackNodeWithMin(d);
			top->minInStack = top->data;
		}

		~StackWithMin() {
			while(top != nullptr) {
				StackNodeWithMin *temp = top->next;
				delete top;
				top = temp; 
			}
		}

		void push(int item) {
			StackNodeWithMin * newElem = new StackNodeWithMin(item);
			if(top->data < item) newElem->minInStack = top->data;
			else newElem->minInStack = item; 
			newElem->next = top;
			top = newElem;
		}

		int pop() {	
			if (top == nullptr) throw out_of_range("Tried to pop when the stack is empty");
			int ret = top->data;
			top = top->next;
			return ret;
		}

		int peek() {
			if (top == nullptr) throw out_of_range("Tried to peek when the stack is empty");
			else return top->data;
		}

		int minimumElement() {
			if(top == nullptr) throw out_of_range("Tried to find minimum element when the stack is empty");
			else return top->minInStack;
		}

		bool isEmpty() {
			return top == nullptr;
		}
};

int main() {

	StackWithMin *stack = new StackWithMin(5);
	if(stack->peek() != 5) cout << "Failed Test 1" << endl;
	if(stack->minimumElement() != 5) cout << "Failed Test 2" << endl;
	
	stack->push(8);
	if(stack->peek() != 8) cout << "Failed Test 3" << endl;
	if(stack->minimumElement() != 5) cout << "Failed Test 4" << endl;
	
	stack->push(3);
	if(stack->peek() != 3) cout << "Failed Test 5" << endl;
	if(stack->minimumElement() != 3) cout << "Failed Test 6" << endl;

	stack->pop();
	if(stack->peek() != 8) cout << "Failed Test 7" << endl;
	if(stack->minimumElement() != 5) cout << "Failed Test 8" << endl;

	cout << "Tests Finished" << endl;
	return 0;
}



