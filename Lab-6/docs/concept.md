# Lab 6 — Divide and Conquer and Greedy Algorithms

The programs in `Lab-6/Source_code` are interactive C++17 implementations of four algorithms.

## 1. Maximum and Minimum Using Divide and Conquer

The array is divided into two halves recursively. Each half returns its minimum and maximum, and the two results are combined with two comparisons. The recurrence is

$$T(n) = 2T(n/2) + O(1)$$

so the running time is $O(n)$ and the recursive stack uses $O(\log n)$ space. A traditional one-pass approach also takes $O(n)$ time and $O(1)$ extra space. Therefore, divide and conquer is not asymptotically faster here; its advantage is the clear recursive structure and the ability to process independent subarrays in parallel. The traditional approach is usually preferable when only a simple sequential scan is required.

Implementation: `1_Max_Min_Divide_Conquer.cpp`

## 2. Maximum-Subarray Problem

The best subarray is either completely in the left half, completely in the right half, or crosses the midpoint. The crossing result is found by scanning outward from the midpoint. The recurrence is

$$T(n) = 2T(n/2) + O(n) = O(n\log n).$$

The implementation also reports the sum and the 1-based start and end positions. Kadane's algorithm solves the same problem in $O(n)$ time and $O(1)$ extra space, so the divide-and-conquer version is mainly useful for demonstrating the strategy and for extensions where subproblem results are combined.

Implementation: `2_Maximum_Subarray_Divide_Conquer.cpp`

## 3. Strassen's Matrix Multiplication

Strassen's method divides each matrix into four blocks. It computes seven recursive products instead of the eight products used by the direct block multiplication method, then combines them with additions and subtractions. Its recurrence is

$$T(n) = 7T(n/2) + O(n^2) = O(n^{\log_2 7}) \approx O(n^{2.807}).$$

Normal triple-loop multiplication takes $O(n^3)$ time. Thus Strassen's algorithm has a better asymptotic running time for sufficiently large matrices. It performs extra additions, uses more temporary memory, and can have numerical or implementation overhead, so ordinary multiplication can still be faster for small matrices. The program pads a non-power-of-two order with zeros and displays only the requested portion of the product.

Implementation: `3_Strassen_Matrix_Multiplication.cpp`

## 4. Fractional Knapsack Using a Greedy Approach

Each item is sorted by value-to-weight ratio in descending order. The algorithm takes as much as possible from the best remaining ratio, allowing the final item to be fractional. This greedy choice is optimal because every unit of remaining capacity is assigned to the highest available value per unit weight.

Sorting dominates the running time, giving $O(n\log n)$ time and $O(n)$ space for the item list. Unlike 0/1 knapsack, fractional knapsack permits splitting items; the same greedy strategy is not generally optimal when items must be taken whole.

Implementation: `4_Fractional_Knapsack.cpp`