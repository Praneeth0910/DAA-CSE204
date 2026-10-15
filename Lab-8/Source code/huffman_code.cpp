#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
    char symbol;
    int frequency;
    int order;
    Node* left;
    Node* right;

    Node(char symbol, int frequency, int order)
        : symbol(symbol), frequency(frequency), order(order), left(nullptr), right(nullptr) {}

    Node(Node* left, Node* right, int order)
        : symbol('\0'), frequency(left->frequency + right->frequency), order(order),
          left(left), right(right) {}
};

struct CompareNodes {
    bool operator()(const Node* first, const Node* second) const {
        if (first->frequency != second->frequency) {
            return first->frequency > second->frequency;
        }
        return first->order > second->order;
    }
};

void printCodes(const Node* node, const string& code, vector<pair<char, string>>& codes) {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        codes.push_back({node->symbol, code.empty() ? "0" : code});
        return;
    }

    printCodes(node->left, code + "0", codes);
    printCodes(node->right, code + "1", codes);
}

void deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    const vector<pair<char, int>> frequencies = {
        {'a', 20}, {'c', 11}, {'d', 2}, {'e', 10}, {'o', 15},
        {'m', 8}, {'s', 10}, {'t', 22}, {'u', 2}
    };

    priority_queue<Node*, vector<Node*>, CompareNodes> queue;
    int nextOrder = 0;
    for (const auto& entry : frequencies) {
        queue.push(new Node(entry.first, entry.second, nextOrder++));
    }

    cout << "Huffman construction steps (frequencies are in hundreds):\n";
    while (queue.size() > 1) {
        Node* first = queue.top();
        queue.pop();
        Node* second = queue.top();
        queue.pop();

        cout << "Combine " << first->frequency << " and " << second->frequency
             << " -> " << first->frequency + second->frequency << '\n';
        queue.push(new Node(first, second, nextOrder++));
    }

    Node* root = queue.top();
    vector<pair<char, string>> codes;
    printCodes(root, "", codes);
    sort(codes.begin(), codes.end());

    long long weightedBitsPerHundred = 0;
    cout << "\nHuffman encoding table:\n";
    cout << "Letter\tFrequency\tCode\tBits for listed counts\n";
    for (const auto& entry : codes) {
        auto frequency = find_if(
            frequencies.begin(), frequencies.end(),
            [&entry](const pair<char, int>& item) { return item.first == entry.first; });
        long long bits = static_cast<long long>(frequency->second) * entry.second.size();
        weightedBitsPerHundred += bits;
        cout << entry.first << '\t' << frequency->second << "\t\t"
             << entry.second << '\t' << bits << '\n';
    }

    const long long actualBits = weightedBitsPerHundred * 100;
    cout << "\nWeighted cost for the listed counts: " << weightedBitsPerHundred
         << " bits per 100-count block\n";
    cout << "Actual encoded file size: " << actualBits << " bits = "
         << actualBits / 8 << " bytes (" << fixed << setprecision(3)
         << actualBits / 8000.0 << " KB, " << actualBits / 8192.0 << " KiB)\n";

    deleteTree(root);
    return 0;
}
