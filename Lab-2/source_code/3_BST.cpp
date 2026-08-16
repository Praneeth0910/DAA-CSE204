/*
Program Name: Binary Search Tree Implementation
Program Description: Takes the inputs {number of elements, elements} and
                     creates a Binary Search Tree. Performs insertion and
                     deletion operations on the Binary Search Tree

*/

#include<iostream>
using namespace std;

class BST {
	struct Node {
		int val;
		Node* left;
		Node* right;

		Node(int value) {
			val = value;
			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;

	Node* insert(Node* root, int val);
	Node* deleteNode(Node* root, int val);
	Node* minValueNode(Node* root);
	void inorder(Node* root);

public:
	BST();

	void insert(int val);
	void deleteElement(int val);
	void display();
};

BST::BST() {
	root = nullptr;
}

BST::Node* BST::insert(Node* root, int val) {
	if (root == nullptr)
		return new Node(val);

	if (val < root->val)
		root->left = insert(root->left, val);
	else if (val > root->val)
		root->right = insert(root->right, val);
	else
		cout << "Duplicate element not allowed!!" << endl;

	return root;
}

void BST::insert(int val) {
	root = insert(root, val);
}

BST::Node* BST::minValueNode(Node* root) {
	Node* temp = root;

	while (temp->left != nullptr)
		temp = temp->left;

	return temp;
}

BST::Node* BST::deleteNode(Node* root, int val) {
	if (root == nullptr)
		return root;

	if (val < root->val)
		root->left = deleteNode(root->left, val);

	else if (val > root->val)
		root->right = deleteNode(root->right, val);

	else {
		if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		Node* temp = minValueNode(root->right);
		root->val = temp->val;
		root->right = deleteNode(root->right, temp->val);
	}

	return root;
}

void BST::deleteElement(int val) {
	if (root == nullptr) {
		cout << "BST is empty!!" << endl;
		return;
	}

	root = deleteNode(root, val);
}

void BST::inorder(Node* root) {
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void BST::display() {
	if (root == nullptr) {
		cout << "BST is empty!!" << endl;
		return;
	}

	cout << "Inorder Traversal: ";
	inorder(root);
	cout << endl;
}

int main(void) {
	cout << "======================================" << endl;
	cout << "       BINARY SEARCH TREE" << endl;
	cout << "   INSERTION AND DELETION OPERATIONS" << endl;
	cout << "======================================" << endl;

	BST tree;

	int n;
	cout << "Enter Number of Elements: ";
	cin >> n;

	if (n <= 0) {
		cout << "Invalid Number of Elements!!" << endl;
		return 0;
	}

	cout << "--------------------------------------" << endl;
	cout << "Enter Elements to be Inserted:" << endl;

	for (int i = 0; i < n; i++) {
		int val;
		cout << "Enter Element " << i + 1 << ": ";
		cin >> val;

		tree.insert(val);
	}

	cout << "--------------------------------------" << endl;
	cout << "BST After Insertion:" << endl;
	tree.display();

	cout << "--------------------------------------" << endl;

	int val;
	cout << "Enter Element to be Deleted: ";
	cin >> val;

	tree.deleteElement(val);

	cout << "BST After Deletion:" << endl;
	tree.display();

	cout << "--------------------------------------" << endl;
	cout << "Insertion Time Complexity: O(log n) Average, O(n) Worst Case" << endl;
	cout << "Deletion Time Complexity: O(log n) Average, O(n) Worst Case" << endl;
	cout << "Space Complexity: O(n)" << endl;

	return 0;
}