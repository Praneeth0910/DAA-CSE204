#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<long long>>;

Matrix add(const Matrix& first, const Matrix& second, int sign) {
    int size = static_cast<int>(first.size());
    Matrix result(size, vector<long long>(size));

    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            result[row][column] = first[row][column] + sign * second[row][column];
        }
    }
    return result;
}

Matrix strassenMultiply(const Matrix& first, const Matrix& second) {
    int size = static_cast<int>(first.size());
    Matrix result(size, vector<long long>(size, 0));

    if (size == 1) {
        result[0][0] = first[0][0] * second[0][0];
        return result;
    }

    int half = size / 2;
    Matrix first11(half, vector<long long>(half));
    Matrix first12(half, vector<long long>(half));
    Matrix first21(half, vector<long long>(half));
    Matrix first22(half, vector<long long>(half));
    Matrix second11(half, vector<long long>(half));
    Matrix second12(half, vector<long long>(half));
    Matrix second21(half, vector<long long>(half));
    Matrix second22(half, vector<long long>(half));

    for (int row = 0; row < half; ++row) {
        for (int column = 0; column < half; ++column) {
            first11[row][column] = first[row][column];
            first12[row][column] = first[row][column + half];
            first21[row][column] = first[row + half][column];
            first22[row][column] = first[row + half][column + half];
            second11[row][column] = second[row][column];
            second12[row][column] = second[row][column + half];
            second21[row][column] = second[row + half][column];
            second22[row][column] = second[row + half][column + half];
        }
    }

    Matrix product1 = strassenMultiply(add(first11, first22, 1), add(second11, second22, 1));
    Matrix product2 = strassenMultiply(add(first21, first22, 1), second11);
    Matrix product3 = strassenMultiply(first11, add(second12, second22, -1));
    Matrix product4 = strassenMultiply(first22, add(second21, second11, -1));
    Matrix product5 = strassenMultiply(add(first11, first12, 1), second22);
    Matrix product6 = strassenMultiply(add(first21, first11, -1), add(second11, second12, 1));
    Matrix product7 = strassenMultiply(add(first12, first22, -1), add(second21, second22, 1));

    Matrix result11 = add(add(add(product1, product4, 1), product5, -1), product7, 1);
    Matrix result12 = add(product3, product5, 1);
    Matrix result21 = add(product2, product4, 1);
    Matrix result22 = add(add(add(product1, product3, 1), product2, -1), product6, 1);

    for (int row = 0; row < half; ++row) {
        for (int column = 0; column < half; ++column) {
            result[row][column] = result11[row][column];
            result[row][column + half] = result12[row][column];
            result[row + half][column] = result21[row][column];
            result[row + half][column + half] = result22[row][column];
        }
    }
    return result;
}

void printMatrix(const Matrix& matrix) {
    for (const vector<long long>& row : matrix) {
        for (long long value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}

int nextPowerOfTwo(int value) {
    int power = 1;
    while (power < value) {
        power *= 2;
    }
    return power;
}

int main() {
    int size;

    cout << "Enter the order of square matrices: ";
    cin >> size;
    if (!cin || size <= 0) {
        cerr << "Matrix order must be positive.\n";
        return 1;
    }

    int paddedSize = nextPowerOfTwo(size);
    Matrix first(paddedSize, vector<long long>(paddedSize, 0));
    Matrix second(paddedSize, vector<long long>(paddedSize, 0));

    cout << "Enter the first matrix:\n";
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            cin >> first[row][column];
            if (!cin) {
                cerr << "Invalid matrix element.\n";
                return 1;
            }
        }
    }

    cout << "Enter the second matrix:\n";
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            cin >> second[row][column];
            if (!cin) {
                cerr << "Invalid matrix element.\n";
                return 1;
            }
        }
    }

    Matrix product = strassenMultiply(first, second);
    Matrix displayedProduct(size, vector<long long>(size));
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            displayedProduct[row][column] = product[row][column];
        }
    }

    cout << "Product matrix using Strassen's algorithm:\n";
    printMatrix(displayedProduct);

    return 0;
}