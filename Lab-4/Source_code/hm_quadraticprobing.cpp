#include <iostream>
#include <vector>

using namespace std;

enum SlotState { EMPTY, OCCUPIED, DELETED };

struct Slot {
    int key = 0;
    SlotState state = EMPTY;
};

class QuadraticProbingHashTable {
private:
    vector<Slot> table;

    int hashFunction(int key) const {
        int index = key % static_cast<int>(table.size());
        return (index < 0) ? index + static_cast<int>(table.size()) : index;
    }

    int probeIndex(int key, int attempt) const {
        return (hashFunction(key) + attempt * attempt) % static_cast<int>(table.size());
    }

public:
    explicit QuadraticProbingHashTable(int size) : table(size) {}

    bool insert(int key) {
        int firstDeleted = -1;

        for (int attempt = 0; attempt < static_cast<int>(table.size()); ++attempt) {
            int index = probeIndex(key, attempt);

            if (table[index].state == OCCUPIED && table[index].key == key) {
                cout << "Key " << key << " already exists.\n";
                return false;
            }

            if (table[index].state == DELETED && firstDeleted == -1) {
                firstDeleted = index;
            } else if (table[index].state == EMPTY) {
                if (firstDeleted != -1) {
                    index = firstDeleted;
                }
                table[index].key = key;
                table[index].state = OCCUPIED;
                cout << "Inserted " << key << " at index " << index << ".\n";
                return true;
            }
        }

        if (firstDeleted != -1) {
            table[firstDeleted].key = key;
            table[firstDeleted].state = OCCUPIED;
            cout << "Inserted " << key << " at index " << firstDeleted << ".\n";
            return true;
        }

        cout << "Cannot insert " << key << ": no reachable slot is available.\n";
        return false;
    }

    int search(int key) const {
        for (int attempt = 0; attempt < static_cast<int>(table.size()); ++attempt) {
            int index = probeIndex(key, attempt);

            if (table[index].state == EMPTY) {
                return -1;
            }
            if (table[index].state == OCCUPIED && table[index].key == key) {
                return index;
            }
        }
        return -1;
    }

    bool remove(int key) {
        int index = search(key);
        if (index == -1) {
            cout << "Key " << key << " was not found.\n";
            return false;
        }

        table[index].state = DELETED;
        cout << "Deleted " << key << " from index " << index << ".\n";
        return true;
    }

    void display() const {
        cout << "\nIndex\tValue\n";
        for (int index = 0; index < static_cast<int>(table.size()); ++index) {
            cout << index << "\t";
            if (table[index].state == OCCUPIED) {
                cout << table[index].key;
            } else if (table[index].state == DELETED) {
                cout << "<deleted>";
            } else {
                cout << "<empty>";
            }
            cout << '\n';
        }
    }
};

int main() {
    int size;
    cout << "Enter hash table size (a prime number is recommended): ";
    cin >> size;

    if (!cin || size <= 0) {
        cerr << "Table size must be a positive integer.\n";
        return 1;
    }

    QuadraticProbingHashTable hashTable(size);
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoose an option: ";
        cin >> choice;

        if (!cin) {
            cerr << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                if (cin) hashTable.insert(key);
                break;
            case 2: {
                cout << "Enter key: ";
                cin >> key;
                if (cin) {
                    int index = hashTable.search(key);
                    if (index == -1) cout << "Key " << key << " was not found.\n";
                    else cout << "Key " << key << " found at index " << index << ".\n";
                }
                break;
            }
            case 3:
                cout << "Enter key: ";
                cin >> key;
                if (cin) hashTable.remove(key);
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                cout << "Goodbye.\n";
                break;
            default:
                cout << "Please choose a number from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
