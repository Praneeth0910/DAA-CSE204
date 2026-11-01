# Lab 10 — 0/1 Knapsack Using Dynamic Programming

The program in `Lab-10/Source code/0_1_Knapsack_Dynamic_Programming.cpp` solves the 0/1 Knapsack problem.

## Problem

Given items with values and weights, select items whose total weight does not exceed the knapsack capacity while maximizing total value. Each item can either be selected once or not selected at all.

## Dynamic Programming Strategy

Let `table[i][capacity]` represent the maximum value obtainable using the first `i` items and a knapsack capacity of `capacity`.

For item `i`, there are two choices:

1. Do not select the item: `table[i - 1][capacity]`.
2. Select the item when it fits: `value[i] + table[i - 1][capacity - weight[i]]`.

The recurrence is

$$
DP[i][c] =
\begin{cases}
DP[i-1][c], & \text{if } weight_i > c \\
\max(DP[i-1][c], value_i + DP[i-1][c-weight_i]), & \text{otherwise}
\end{cases}
$$

The program backtracks through the completed table to report the selected item numbers, their total weight, and the maximum value.

## Complexity Analysis

- Time complexity: $O(nC)$
- Space complexity: $O(nC)$

Here, $n$ is the number of items and $C$ is the integer knapsack capacity. The dynamic programming approach avoids recalculating the same subproblems, unlike the direct recursive solution whose worst-case time complexity is $O(2^n)$.

The greedy ratio-based strategy used for Fractional Knapsack cannot generally solve 0/1 Knapsack optimally because an item cannot be divided. Dynamic programming considers both include and exclude choices and therefore guarantees the optimal result.