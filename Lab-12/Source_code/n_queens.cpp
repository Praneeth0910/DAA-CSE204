#include <iostream>
#include <vector>

using namespace std;

class NQueensSolver {
    int boardSize;
    vector<int> queenColumn;
    vector<bool> usedColumns;
    vector<bool> usedDescendingDiagonals;
    vector<bool> usedAscendingDiagonals;
    long long solutionCount = 0;

    void printBoard() const {
        cout << "Solution " << solutionCount << ":\n";
        for (int row = 0; row < boardSize; ++row) {
            for (int column = 0; column < boardSize; ++column) {
                cout << (queenColumn[row] == column ? 'Q' : '.') << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void placeQueen(int row) {
        if (row == boardSize) {
            ++solutionCount;
            printBoard();
            return;
        }

        for (int column = 0; column < boardSize; ++column) {
            int descendingDiagonal = row - column + boardSize - 1;
            int ascendingDiagonal = row + column;

            if (usedColumns[column] ||
                usedDescendingDiagonals[descendingDiagonal] ||
                usedAscendingDiagonals[ascendingDiagonal]) {
                continue;
            }

            queenColumn[row] = column;
            usedColumns[column] = true;
            usedDescendingDiagonals[descendingDiagonal] = true;
            usedAscendingDiagonals[ascendingDiagonal] = true;

            placeQueen(row + 1);

            usedColumns[column] = false;
            usedDescendingDiagonals[descendingDiagonal] = false;
            usedAscendingDiagonals[ascendingDiagonal] = false;
        }
    }

public:
    explicit NQueensSolver(int size)
        : boardSize(size),
          queenColumn(size, -1),
          usedColumns(size, false),
          usedDescendingDiagonals(2 * size - 1, false),
          usedAscendingDiagonals(2 * size - 1, false) {}

    long long solve() {
        placeQueen(0);
        return solutionCount;
    }
};

int main() {
    int boardSize;
    cout << "Enter the value of N: ";
    cin >> boardSize;
    if (!cin || boardSize <= 0) {
        cerr << "N must be a positive integer.\n";
        return 1;
    }

    NQueensSolver solver(boardSize);
    long long solutionCount = solver.solve();
    cout << "Total solutions: " << solutionCount << '\n';

    return 0;
}
