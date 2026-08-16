/*
Program Name: Summation of Series - Method 2
Program Description: Takes the inputs {x, n} and calculates the sum of the
                     series 1 + X + X^2 + X^3 + ... + X^n using an iterative
                     approach

*/

#include<iostream>
using namespace std;

double sumGeoSeries(double x, int n);

int main(void) {
	cout << "======================================" << endl;
	cout << "SUMMATION OF SERIES USING ITERATION" << endl;
	cout << "======================================" << endl;

	double x;
	int n;

	cout << "Series: 1 + X + X^2 + X^3 + ... + X^n" << endl;

	cout << "Enter Value of X: ";
	cin >> x;

	cout << "Enter Value of n: ";
	cin >> n;

	if (n < 0) {
		cout << "Invalid value of n!!" << endl;
		return 0;
	}

	cout << "--------------------------------------" << endl;

	double sum = sumGeoSeries(x, n);

	cout << "Sum of the given series = " << sum << endl;

	cout << "--------------------------------------" << endl;
	cout << "Time Complexity: O(n)" << endl;
	cout << "Space Complexity: O(1)" << endl;

	return 0;
}

double sumGeoSeries(double x, int n) {
	double sum = 0;
	double term = 1;

	for (int i = 0; i <= n; i++) {
		sum += term;
		term *= x;
	}

	return sum;
}