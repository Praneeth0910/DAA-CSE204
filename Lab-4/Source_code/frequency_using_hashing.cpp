#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (!cin || n < 0) {
        cerr << "Number of elements must be non-negative.\n";
        return 1;
    }

    vector<long long> values(n);
    unordered_map<long long, int> frequency;
    vector<long long> order;

    cout << "Enter " << n << " array elements: ";
    for (long long& value : values) {
        cin >> value;
        if (!cin) {
            cerr << "Invalid array element.\n";
            return 1;
        }

        if (frequency.find(value) == frequency.end()) {
            order.push_back(value);
        }
        ++frequency[value];
    }

    cout << "\nElement\tFrequency\n";
    for (long long value : order) {
        cout << value << "\t" << frequency[value] << '\n';
    }

    return 0;
}
