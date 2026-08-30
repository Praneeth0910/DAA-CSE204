/*
Program Name: Queue Implementation Using Linked List
Program Description: Implements enqueue, dequeue, front, and display operations
                     on a queue using a singly linked list.
*/

#include <iostream>
using namespace std;

class Queue {
	struct Node {
		int data;
		Node* next;

		Node(int value) {
			data = value;
			next = nullptr;
		}
	};

	Node* frontNode;
	Node* rearNode;

public:
	Queue();
	~Queue();

	void enqueue(int value);
	void dequeue();
	void front();
	void display();
};

Queue::Queue() {
	frontNode = nullptr;
	rearNode = nullptr;
}

Queue::~Queue() {
	while (frontNode != nullptr) {
		Node* temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
	}

	rearNode = nullptr;
}

void Queue::enqueue(int value) {
	Node* newNode = new Node(value);

	if (rearNode == nullptr) {
		frontNode = newNode;
		rearNode = newNode;
	} else {
		rearNode->next = newNode;
		rearNode = newNode;
	}

	cout << value << " enqueued into the queue." << endl;
}

void Queue::dequeue() {
	if (frontNode == nullptr) {
		cout << "Queue Underflow!!" << endl;
		return;
	}

	Node* temp = frontNode;
	cout << temp->data << " dequeued from the queue." << endl;
	frontNode = frontNode->next;

	if (frontNode == nullptr)
		rearNode = nullptr;

	delete temp;
}

void Queue::front() {
	if (frontNode == nullptr) {
		cout << "Queue is empty!!" << endl;
		return;
	}

	cout << "Front element: " << frontNode->data << endl;
}

void Queue::display() {
	if (frontNode == nullptr) {
		cout << "Queue is empty!!" << endl;
		return;
	}

	cout << "Queue elements: ";
	for (Node* current = frontNode; current != nullptr; current = current->next)
		cout << current->data << " ";
	cout << endl;
}

int main() {
	Queue queue;
	int choice;

	cout << "======================================" << endl;
	cout << "     QUEUE USING LINKED LIST" << endl;
	cout << "======================================" << endl;

	do {
		cout << "\n1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Front" << endl;
		cout << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int value;
			cout << "Enter value to enqueue: ";
			cin >> value;
			queue.enqueue(value);
			break;
		}
		case 2:
			queue.dequeue();
			break;
		case 3:
			queue.front();
			break;
		case 4:
			queue.display();
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
