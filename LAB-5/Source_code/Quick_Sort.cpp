#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int smaller = low;

    for (int index = low; index < high; ++index) {
        if (values[index] <= pivot) {
            swap(values[smaller], values[index]);
            ++smaller;
        }
    }

    swap(values[smaller], values[high]);
    return smaller;
}

void quickSort(vector<int>& values, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partition(values, low, high);
    quickSort(values, low, pivotIndex - 1);
    quickSort(values, pivotIndex + 1, high);
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
        quickSort(values, 0, size - 1);
    }

    cout << "Array after sorting: ";
    display(values);

    return 0;
}