#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;  // Represents no direct edge (infinity)

// Print the distance or path matrix with aligned columns
void printMatrix(const vector<vector<int>>& mat, int n) {
    cout << "     ";
    for (int j = 0; j < n; ++j)
        cout << setw(6) << j + 1;
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        cout << setw(3) << i + 1 << "  ";
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == INF)
                cout << setw(6) << "INF";
            else
                cout << setw(6) << mat[i][j];
        }
        cout << '\n';
    }
}

// Reconstruct and print the shortest path from src to dst
void printPath(const vector<vector<int>>& next, int src, int dst) {
    if (next[src][dst] == -1) {
        cout << "No path";
        return;
    }
    cout << src + 1;
    while (src != dst) {
        src = next[src][dst];
        cout << " -> " << src + 1;
    }
}

int main() {
    // ----------------------------------------------------------------
    // Graph: 4 vertices, directed weighted edges
    //        (0-indexed internally, displayed as 1-indexed)
    //
    //   1 --(3)--> 2
    //   1 --(INF)-> 3   (no direct edge)
    //   1 --(7)--> 4
    //   2 --(INF)-> 1
    //   2 --(2)--> 3
    //   2 --(INF)-> 4
    //   3 --(INF)-> 1
    //   3 --(INF)-> 2
    //   3 --(1)--> 4
    //   4 --(INF)-> 1
    //   4 --(INF)-> 2
    //   4 --(INF)-> 3
    // ----------------------------------------------------------------
    const int n = 4;

    // dist[i][j] = weight of direct edge i->j, INF if no edge, 0 on diagonal
    vector<vector<int>> dist = {
        {  0,   3, INF,   7 },
        {INF,   0,   2, INF },
        {INF, INF,   0,   1 },
        {INF, INF, INF,   0 }
    };

    // next[i][j] = next vertex on shortest path i->j (-1 if unreachable)
    vector<vector<int>> next(n, vector<int>(n, -1));

    // Initialise `next` from the initial edge set
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && dist[i][j] != INF)
                next[i][j] = j;

    // ---------------------------------------------------------------
    // Floyd-Warshall: relax all pairs through each intermediate k
    // ---------------------------------------------------------------
    cout << "Initial distance matrix (INF = no direct edge):\n";
    printMatrix(dist, n);
    cout << '\n';

    for (int k = 0; k < n; ++k) {
        cout << "After considering vertex " << k + 1 << " as intermediate:\n";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Only relax if both legs of the path are reachable
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j]  = dist[i][k] + dist[k][j];
                        next[i][j]  = next[i][k];  // route i->j via k
                    }
                }
            }
        }

        printMatrix(dist, n);
        cout << '\n';
    }

    // ---------------------------------------------------------------
    // Final results
    // ---------------------------------------------------------------
    cout << "Final shortest distance matrix:\n";
    printMatrix(dist, n);

    cout << "\nShortest paths between all pairs:\n";
    cout << left << setw(12) << "Pair"
         << setw(8)          << "Dist"
         << "Path\n";
    cout << string(50, '-') << '\n';

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            cout << left << setw(12)
                 << (to_string(i + 1) + " -> " + to_string(j + 1));
            if (dist[i][j] == INF)
                cout << setw(8) << "INF" << "No path\n";
            else {
                cout << setw(8) << dist[i][j];
                printPath(next, i, j);
                cout << '\n';
            }
        }
    }

    return 0;
}
