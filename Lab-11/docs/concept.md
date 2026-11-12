# Lab 11 — Matrix Chain Multiplication Using Dynamic Programming

The program in `Lab-11/Source code/matrix_chain_multiplication.cpp` finds the
order of multiplying a sequence of matrices that uses the fewest scalar
multiplications. Matrix multiplication is associative, so the parenthesization
can change without changing the result, but different parenthesizations have
different costs.

## Problem

For matrices `A1, A2, ..., An`, let matrix `Ai` have dimensions
`p[i-1] × p[i]`. Determine the parenthesization with minimum multiplication
cost.

## Dynamic Programming Strategy

Let `cost[i][j]` be the minimum number of scalar multiplications needed to
multiply matrices `Ai` through `Aj`. If the final split is after matrix `Ak`,
the recurrence is:

```
cost[i][j] = min(
    cost[i][k] + cost[k + 1][j] + p[i - 1] * p[k] * p[j]
)
```

The program also stores the split point that produced each minimum so it can
print the optimal parenthesization.

## Complexity Analysis

- Time complexity: `O(n^3)`
- Space complexity: `O(n^2)`

Here, `n` is the number of matrices. The dynamic programming table prevents
repeated computation of the same matrix-chain subproblems.

## Example

For matrices with dimensions `10×30`, `30×5`, and `5×60`, enter:

```text
3
10 30 5 60
```

The optimal parenthesization is `((A1A2)A3)`, with `4500` scalar
multiplications.
