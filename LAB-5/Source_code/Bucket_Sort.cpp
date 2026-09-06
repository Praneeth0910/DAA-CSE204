#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bucketSort(vector<int>& values) {
    if (values.size() < 2) {
        return;
    }

    int minimum = values[0];
    int maximum = values[0];
    for (int value : values) {
        minimum = min(minimum, value);
        maximum = max(maximum, value);
    }

    long long range = static_cast<long long>(maximum) - minimum + 1;
    int bucketCount = static_cast<int>(values.size());
    vector<vector<int>> buckets(bucketCount);

    for (int value : values) {
        long long offset = static_cast<long long>(value) - minimum;
        int bucketIndex = static_cast<int>(offset * bucketCount / range);
        if (bucketIndex == bucketCount) {
            bucketIndex--;
        }
        buckets[bucketIndex].push_back(value);
    }

    int index = 0;
    for (vector<int>& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        for (int value : bucket) {
            values[index++] = value;
        }
    }
}

void display(const vector<int>& values) {
    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

int main() {
    int size;

    cout << "Enter number of elements: ";
    cin >> size;
    if (!cin || size < 0) {
        cerr << "Number of elements must be non-negative.\n";
        return 1;
    }

    vector<int> values(size);
    cout << "Enter " << size << " array elements: ";
    for (int& value : values) {
        cin >> value;
        if (!cin) {
            cerr << "Invalid array element.\n";
            return 1;
        }
    }

    cout << "Array before sorting: ";
    display(values);

    bucketSort(values);

    cout << "Array after sorting: ";
    display(values);

    return 0;
}