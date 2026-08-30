#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Returns true when two distinct array elements add up to target.
// unordered_set operations are O(1) on average, so this is O(n) on average.
bool hasPairWithSum(const vector<long long>& values, long long target) {
    unordered_set<long long> seen;

    for (long long value : values) {
        long long complement = target - value;
        if (seen.find(complement) != seen.end()) {
            return true;
        }
        seen.insert(value);
    }

    return false;
}

int main() {
    int n;
    long long target;

    cout << "Enter number of elements: ";
    cin >> n;
    if (!cin || n < 0) {
        cerr << "Number of elements must be non-negative.\n";
        return 1;
    }

    vector<long long> values(n);
    cout << "Enter " << n << " array elements: ";
    for (long long& value : values) {
        cin >> value;
        if (!cin) {
            cerr << "Invalid array element.\n";
            return 1;
        }
    }

    cout << "Enter target value: ";
    cin >> target;
    if (!cin) {
        cerr << "Invalid target value.\n";
        return 1;
    }

    if (hasPairWithSum(values, target)) {
        cout << "A pair with sum " << target << " exists.\n";
    } else {
        cout << "No pair with sum " << target << " exists.\n";
    }

    return 0;
}
