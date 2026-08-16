/*
Program Name: Kth Smallest Element Using Sorting
Program Description: Takes the inputs {arr, arr size, k} and finds the Kth
                     smallest element in the given array by first sorting
                     the array

*/

#include<iostream>
#include<algorithm>
using namespace std;

int kthSmallest(int arr[], int n, int k);

int main(void) {
	cout << "======================================" << endl;
	cout << "FINDING KTH SMALLEST ELEMENT USING SORTING" << endl;
	cout << "======================================" << endl;

	int n = 0;

	cout << "Enter Size of array to be Created: ";
	cin >> n;

	if (n <= 0) {
		cout << "Invalid array size!!" << endl;
		return 0;
	}

	int arr[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter Element " << i << " in array: ";
		cin >> arr[i];
	}

	cout << "--------------------------------------" << endl;

	int k;

	cout << "Enter value of K: ";
	cin >> k;

	if (k < 1 || k > n) {
		cout << "Invalid value of K!!" << endl;
		return 0;
	}

	int result = kthSmallest(arr, n, k);

	cout << "The " << k << "th smallest element is: "
	     << result << endl;

	cout << "--------------------------------------" << endl;
	cout << "Time Complexity: O(n log n)" << endl;
	cout << "Space Complexity: O(log n)" << endl;

	return 0;
}

int kthSmallest(int arr[], int n, int k) {
	sort(arr, arr + n);
	return arr[k - 1];
}