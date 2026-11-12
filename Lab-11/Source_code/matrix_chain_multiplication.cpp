#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct MatrixChainResult {
    long long minimumMultiplications;
    vector<vector<int>> split;
};

MatrixChainResult matrixChainOrder(const vector<int>& dimensions) {
    int numberOfMatrices = static_cast<int>(dimensions.size()) - 1;
    const long long infinity = numeric_limits<long long>::max();
    vector<vector<long long>> cost(
        numberOfMatrices + 1,
        vector<long long>(numberOfMatrices + 1, 0)
    );
    vector<vector<int>> split(
        numberOfMatrices + 1,
        vector<int>(numberOfMatrices + 1, 0)
    );

    for (int chainLength = 2; chainLength <= numberOfMatrices; ++chainLength) {
        for (int first = 1; first <= numberOfMatrices - chainLength + 1; ++first) {
            int last = first + chainLength - 1;
            cost[first][last] = infinity;

            for (int middle = first; middle < last; ++middle) {
                long long multiplicationCost =
                    cost[first][middle] + cost[middle + 1][last] +
                    static_cast<long long>(dimensions[first - 1]) *
                    dimensions[middle] * dimensions[last];

                if (multiplicationCost < cost[first][last]) {
                    cost[first][last] = multiplicationCost;
                    split[first][last] = middle;
                }
            }
        }
    }

    return {cost[1][numberOfMatrices], split};
}

void printParenthesization(
    const vector<vector<int>>& split,
    int first,
    int last
) {
    if (first == last) {
        cout << 'A' << first;
        return;
    }

    cout << '(';
    int middle = split[first][last];
    printParenthesization(split, first, middle);
    printParenthesization(split, middle + 1, last);
    cout << ')';
}

int main() {
    int numberOfMatrices;
    cout << "Enter number of matrices: ";
    cin >> numberOfMatrices;
    if (!cin || numberOfMatrices <= 0) {
        cerr << "Number of matrices must be positive.\n";
        return 1;
    }

    vector<int> dimensions(numberOfMatrices + 1);
    cout << "Enter " << numberOfMatrices + 1
         << " dimensions (p0 p1 ... p" << numberOfMatrices << "):\n";
    for (int& dimension : dimensions) {
        cin >> dimension;
        if (!cin || dimension <= 0) {
            cerr << "Matrix dimensions must be positive integers.\n";
            return 1;
        }
    }

    MatrixChainResult result = matrixChainOrder(dimensions);
    cout << "Minimum scalar multiplications: "
         << result.minimumMultiplications << '\n';
    cout << "Optimal parenthesization: ";
    printParenthesization(result.split, 1, numberOfMatrices);
    cout << '\n';

    return 0;
}
