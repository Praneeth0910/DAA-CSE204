#include <iostream>
using namespace std;

void hanoiRecursive(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    hanoiRecursive(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    hanoiRecursive(n - 1, auxiliary, destination, source);
}

int main() {
    cout << "--- Recursive Towers of Hanoi ---" << endl;
    hanoiRecursive(3, 'A', 'C', 'B');
    return 0;
}
