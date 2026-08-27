#include <iostream>

using namespace std;

class HashMap {
private:
	static const int TABLE_SIZE = 10;

	enum SlotState {
		EMPTY,
		OCCUPIED,
		DELETED
	};

	struct Entry {
		int key;
		int value;
		SlotState state;

		Entry() : key(0), value(0), state(EMPTY) {}
	};

	Entry table[TABLE_SIZE];

	int hashFunction(int key) const {
		int index = key % TABLE_SIZE;
		return index < 0 ? index + TABLE_SIZE : index;
	}

public:
	bool insert(int key, int value) {
		int start = hashFunction(key);
		int firstDeleted = -1;

		for (int step = 0; step < TABLE_SIZE; ++step) {
			int index = (start + step) % TABLE_SIZE;

			if (table[index].state == OCCUPIED && table[index].key == key) {
				table[index].value = value;
				return true;
			}

			if (table[index].state == DELETED && firstDeleted == -1) {
				firstDeleted = index;
			}

			if (table[index].state == EMPTY) {
				if (firstDeleted != -1) {
					index = firstDeleted;
				}
				table[index].key = key;
				table[index].value = value;
				table[index].state = OCCUPIED;
				return true;
			}
		}

		if (firstDeleted != -1) {
			table[firstDeleted].key = key;
			table[firstDeleted].value = value;
			table[firstDeleted].state = OCCUPIED;
			return true;
		}

		return false;
	}

	bool search(int key, int& value) const {
		int start = hashFunction(key);

		for (int step = 0; step < TABLE_SIZE; ++step) {
			int index = (start + step) % TABLE_SIZE;

			if (table[index].state == EMPTY) {
				return false;
			}

			if (table[index].state == OCCUPIED && table[index].key == key) {
				value = table[index].value;
				return true;
			}
		}

		return false;
	}

	bool remove(int key) {
		int start = hashFunction(key);

		for (int step = 0; step < TABLE_SIZE; ++step) {
			int index = (start + step) % TABLE_SIZE;

			if (table[index].state == EMPTY) {
				return false;
			}

			if (table[index].state == OCCUPIED && table[index].key == key) {
				table[index].state = DELETED;
				return true;
			}
		}

		return false;
	}

	void display() const {
		cout << "\nIndex\tKey\tValue\n";
		for (int index = 0; index < TABLE_SIZE; ++index) {
			cout << index << "\t";
			if (table[index].state == OCCUPIED) {
				cout << table[index].key << "\t" << table[index].value;
			} else if (table[index].state == DELETED) {
				cout << "DELETED";
			} else {
				cout << "EMPTY";
			}
			cout << '\n';
		}
	}
};

int main() {
	HashMap map;
	int choice;

	do {
		cout << "\n1. Insert/Update\n"
			 << "2. Search\n"
			 << "3. Delete\n"
			 << "4. Display\n"
			 << "5. Exit\n"
			 << "Enter your choice: ";
		cin >> choice;

		if (!cin) {
			cout << "Invalid input.\n";
			return 1;
		}

		int key;
		int value;

		switch (choice) {
		case 1:
			cout << "Enter key and value: ";
			cin >> key >> value;
			if (map.insert(key, value)) {
				cout << "Key inserted/updated successfully.\n";
			} else {
				cout << "Hash table is full.\n";
			}
			break;
		case 2:
			cout << "Enter key to search: ";
			cin >> key;
			if (map.search(key, value)) {
				cout << "Value: " << value << '\n';
			} else {
				cout << "Key not found.\n";
			}
			break;
		case 3:
			cout << "Enter key to delete: ";
			cin >> key;
			cout << (map.remove(key) ? "Key deleted successfully.\n"
									 : "Key not found.\n");
			break;
		case 4:
			map.display();
			break;
		case 5:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice.\n";
		}
	} while (choice != 5);

	return 0;
}
