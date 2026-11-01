#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int value;
    int weight;
};

struct KnapsackResult {
    int maximumValue;
    vector<int> selectedItems;
};

KnapsackResult zeroOneKnapsack(const vector<Item>& items, int capacity) {
    int numberOfItems = static_cast<int>(items.size());
    vector<vector<int>> table(
        numberOfItems + 1,
        vector<int>(capacity + 1, 0)
    );

    for (int item = 1; item <= numberOfItems; ++item) {
        for (int currentCapacity = 1; currentCapacity <= capacity; ++currentCapacity) {
            table[item][currentCapacity] = table[item - 1][currentCapacity];

            if (items[item - 1].weight <= currentCapacity) {
                int includeValue = items[item - 1].value
                    + table[item - 1][currentCapacity - items[item - 1].weight];
                table[item][currentCapacity] = max(
                    table[item][currentCapacity],
                    includeValue
                );
            }
        }
    }

    vector<int> selectedItems;
    int currentCapacity = capacity;
    for (int item = numberOfItems; item >= 1; --item) {
        if (table[item][currentCapacity] != table[item - 1][currentCapacity]) {
            selectedItems.push_back(item);
            currentCapacity -= items[item - 1].weight;
        }
    }

    reverse(selectedItems.begin(), selectedItems.end());
    return {table[numberOfItems][capacity], selectedItems};
}

int main() {
    int numberOfItems;
    int capacity;

    cout << "Enter number of items: ";
    cin >> numberOfItems;
    if (!cin || numberOfItems < 0) {
        cerr << "Number of items must be non-negative.\n";
        return 1;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    if (!cin || capacity < 0) {
        cerr << "Knapsack capacity must be non-negative.\n";
        return 1;
    }

    vector<Item> items(numberOfItems);
    cout << "Enter value and weight for each item:\n";
    for (int item = 0; item < numberOfItems; ++item) {
        cin >> items[item].value >> items[item].weight;
        if (!cin || items[item].value < 0 || items[item].weight <= 0) {
            cerr << "Each item must have a non-negative value and positive weight.\n";
            return 1;
        }
    }

    KnapsackResult result = zeroOneKnapsack(items, capacity);

    cout << "Maximum value in the 0/1 knapsack: " << result.maximumValue << '\n';
    cout << "Selected item numbers: ";
    if (result.selectedItems.empty()) {
        cout << "None";
    } else {
        for (int item : result.selectedItems) {
            cout << item << ' ';
        }
    }
    cout << '\n';

    int totalWeight = 0;
    for (int item : result.selectedItems) {
        totalWeight += items[item - 1].weight;
    }
    cout << "Total weight: " << totalWeight << '\n';

    return 0;
}