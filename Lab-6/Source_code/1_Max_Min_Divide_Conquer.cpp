#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct MinMax {
    long long minimum;
    long long maximum;
};

MinMax findMinMax(const vector<long long>& values, int left, int right) {
    if (left == right) {
        return {values[left], values[left]};
    }

    if (right == left + 1) {
        if (values[left] < values[right]) {
            return {values[left], values[right]};
        }
        return {values[right], values[left]};
    }

    int middle = left + (right - left) / 2;
    MinMax firstHalf = findMinMax(values, left, middle);
    MinMax secondHalf = findMinMax(values, middle + 1, right);

    return {
        min(firstHalf.minimum, secondHalf.minimum),
        max(firstHalf.maximum, secondHalf.maximum)
    };
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

    MinMax result = findMinMax(values, 0, size - 1);
    cout << "Minimum element: " << result.minimum << '\n';
    cout << "Maximum element: " << result.maximum << '\n';

    return 0;
}