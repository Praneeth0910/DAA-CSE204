# Lab 12 — N-Queens Problem Using Backtracking

The program in `Lab-12/Source code/n_queens.cpp` places `N` queens on an
`N × N` chessboard so that no two queens attack each other.

## Problem

Place exactly one queen in every row and column such that no two queens share:

- a row,
- a column,
- a descending diagonal, or
- an ascending diagonal.

The program prints every valid board and the total number of solutions.

## Backtracking Strategy

The solver places one queen at a time, beginning with the first row. For each
row, it tries every column that is not already occupied and whose two diagonals
are unused.

After placing a queen, the solver recursively processes the next row. If a
placement leads to a dead end, it removes that queen and tries the next
possible column. This is the backtracking step.

The three boolean arrays make conflict checks constant time:

- `usedColumns[column]`
- `usedDescendingDiagonals[row - column + N - 1]`
- `usedAscendingDiagonals[row + column]`

## Complexity Analysis

- Worst-case time complexity: `O(N!)`
- Space complexity: `O(N)`

The recursion depth is `N`, and the boolean arrays store column and diagonal
occupancy. Backtracking prunes partial arrangements as soon as they violate a
constraint.

## Example

For `N = 4`, the program prints the two valid solutions and reports:

```text
Total solutions: 2
```
