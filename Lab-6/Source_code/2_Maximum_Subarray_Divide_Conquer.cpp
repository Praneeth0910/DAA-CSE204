#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct SubarrayResult {
    long long sum;
    int left;
    int right;
};

SubarrayResult bestCrossingSubarray(
    const vector<long long>& values,
    int left,
    int middle,
    int right
) {
    long long leftSum = numeric_limits<long long>::lowest();
    long long currentSum = 0;
    int bestLeft = middle;

    for (int index = middle; index >= left; --index) {
        currentSum += values[index];
        if (currentSum > leftSum) {
            leftSum = currentSum;
            bestLeft = index;
        }
    }

    long long rightSum = numeric_limits<long long>::lowest();
    currentSum = 0;
    int bestRight = middle + 1;

    for (int index = middle + 1; index <= right; ++index) {
        currentSum += values[index];
        if (currentSum > rightSum) {
            rightSum = currentSum;
            bestRight = index;
        }
    }

    return {leftSum + rightSum, bestLeft, bestRight};
}

SubarrayResult maximumSubarray(
    const vector<long long>& values,
    int left,
    int right
) {
    if (left == right) {
        return {values[left], left, right};
    }

    int middle = left + (right - left) / 2;
    SubarrayResult leftResult = maximumSubarray(values, left, middle);
    SubarrayResult rightResult = maximumSubarray(values, middle + 1, right);
    SubarrayResult crossingResult = bestCrossingSubarray(values, left, middle, right);

    if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossingResult.sum) {
        return leftResult;
    }
    if (rightResult.sum >= crossingResult.sum) {
        return rightResult;
    }
    return crossingResult;
}

int main() {
    int size;

    cout << "Enter number of elements: ";
    cin >> size;
    if (!cin || size <= 0) {
        cerr << "Number of elements must be positive.\n";
        return 1;
    }

    vector<long long> values(size);
    cout << "Enter " << size << " array elements: ";
    for (long long& value : values) {
        cin >> value;
        if (!cin) {
            cerr << "Invalid array element.\n";
            return 1;
        }
    }

    SubarrayResult result = maximumSubarray(values, 0, size - 1);
    cout << "Maximum subarray sum: " << result.sum << '\n';
    cout << "Subarray (1-based positions): ";
    for (int index = result.left; index <= result.right; ++index) {
        cout << values[index] << (index == result.right ? '\n' : ' ');
    }
    cout << "Starting position: " << result.left + 1 << '\n';
    cout << "Ending position: " << result.right + 1 << '\n';

    return 0;
}