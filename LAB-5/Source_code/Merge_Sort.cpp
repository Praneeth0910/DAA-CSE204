#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& values, int left, int middle, int right) {
    vector<int> merged;
    int first = left;
    int second = middle + 1;

    while (first <= middle && second <= right) {
        if (values[first] <= values[second]) {
            merged.push_back(values[first++]);
        } else {
            merged.push_back(values[second++]);
        }
    }

    while (first <= middle) {
        merged.push_back(values[first++]);
    }

    while (second <= right) {
        merged.push_back(values[second++]);
    }

    for (int index = 0; index < static_cast<int>(merged.size()); ++index) {
        values[left + index] = merged[index];
    }
}

void mergeSort(vector<int>& values, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(values, left, middle);
    mergeSort(values, middle + 1, right);
    merge(values, left, middle, right);
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

    if (!values.empty()) {
        mergeSort(values, 0, size - 1);
    }

    cout << "Array after sorting: ";
    display(values);

    return 0;
}