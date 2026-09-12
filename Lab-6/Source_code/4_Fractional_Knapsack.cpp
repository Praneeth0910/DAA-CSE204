#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    double value;
    double weight;
};

bool compareByRatio(const Item& first, const Item& second) {
    return first.value / first.weight > second.value / second.weight;
}

double fractionalKnapsack(vector<Item>& items, double capacity) {
    sort(items.begin(), items.end(), compareByRatio);
    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity == 0.0) {
            break;
        }

        double selectedWeight = min(item.weight, capacity);
        totalValue += selectedWeight * item.value / item.weight;
        capacity -= selectedWeight;
    }

    return totalValue;
}

int main() {
    int numberOfItems;
    double capacity;

    cout << "Enter number of items: ";
    cin >> numberOfItems;
    if (!cin || numberOfItems < 0) {
        cerr << "Number of items must be non-negative.\n";
        return 1;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    if (!cin || capacity < 0.0) {
        cerr << "Capacity must be non-negative.\n";
        return 1;
    }

    vector<Item> items(numberOfItems);
    cout << "Enter value and weight for each item:\n";
    for (Item& item : items) {
        cin >> item.value >> item.weight;
        if (!cin || item.value < 0.0 || item.weight <= 0.0) {
            cerr << "Each item must have a non-negative value and positive weight.\n";
            return 1;
        }
    }

    double maximumValue = fractionalKnapsack(items, capacity);
    cout << fixed << setprecision(2);
    cout << "Maximum value in the knapsack: " << maximumValue << '\n';

    return 0;
}