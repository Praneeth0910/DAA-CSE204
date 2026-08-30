/*
Program Name: Stack Implementation Using Linked List
Program Description: Implements push, pop, peek, and display operations
                     on a stack using a singly linked list.
*/

#include <iostream>
using namespace std;

class Stack {
	struct Node {
		int data;
		Node* next;

		Node(int value, Node* nextNode = nullptr) {
			data = value;
			next = nextNode;
		}
	};

	Node* topNode;

public:
	Stack();
	~Stack();

	void push(int value);
	void pop();
	void peek();
	void display();
};

Stack::Stack() {
	topNode = nullptr;
}

Stack::~Stack() {
	while (topNode != nullptr) {
		Node* temp = topNode;
		topNode = topNode->next;
		delete temp;
	}
}

void Stack::push(int value) {
	topNode = new Node(value, topNode);
	cout << value << " pushed into the stack." << endl;
}

void Stack::pop() {
	if (topNode == nullptr) {
		cout << "Stack Underflow!!" << endl;
		return;
	}

	Node* temp = topNode;
	cout << temp->data << " popped from the stack." << endl;
	topNode = topNode->next;
	delete temp;
}

void Stack::peek() {
	if (topNode == nullptr) {
		cout << "Stack is empty!!" << endl;
		return;
	}

	cout << "Top element: " << topNode->data << endl;
}

void Stack::display() {
	if (topNode == nullptr) {
		cout << "Stack is empty!!" << endl;
		return;
	}

	cout << "Stack elements: ";
	for (Node* current = topNode; current != nullptr; current = current->next)
		cout << current->data << " ";
	cout << endl;
}

int main() {
	Stack stack;
	int choice;

	cout << "======================================" << endl;
	cout << "     STACK USING LINKED LIST" << endl;
	cout << "======================================" << endl;

	do {
		cout << "\n1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int value;
			cout << "Enter value to push: ";
			cin >> value;
			stack.push(value);
			break;
		}
		case 2:
			stack.pop();
			break;
		case 3:
			stack.peek();
			break;
		case 4:
			stack.display();
			break;
		case 5:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice!!" << endl;
		}
	} while (choice != 5);

	return 0;
}
