# Search Algorithms — Linear & Binary

## Overview

This note covers two fundamental search algorithms: Linear Search and Binary Search. It explains how they work, their time and space complexities, typical use-cases, and links to the C implementations in this workspace.

## Linear Search

- **Description:** Sequentially checks each element until the target is found or the list ends.
- **Pseudocode:

```
for i from 0 to n-1:
    if a[i] == target:
        return i
return -1
```

- **Time Complexity:** O(n) worst-case, O(1) best-case (found at first index).
- **Space Complexity:** O(1).
- **When to use:** Small or unsorted datasets; single-pass searches; when simplicity matters more than speed.
- **Example implementation:** [linear_search.c](Lab-1/linear_search.c)

## Binary Search

- **Description:** Repeatedly divides a sorted array in half to locate the target. Requires the array to be sorted beforehand.
- **Pseudocode:

```
low = 0
high = n - 1
while low <= high:
    mid = low + (high - low) // 2
    if a[mid] == target: return mid
    if a[mid] < target: low = mid + 1
    else: high = mid - 1
return -1
```

- **Time Complexity:** O(log n).
- **Space Complexity:** O(1) (iterative). Recursive variants use O(log n) stack.
- **When to use:** Large datasets where random access is cheap and the data is already sorted, or can be sorted once and queried many times.
- **Example implementation (includes a bubble sort step to ensure sorting):** [binary_search.c](Lab-1/binary_search.c)

## Comparison & Notes

- **Performance:** Binary Search is asymptotically faster (O(log n)) than Linear Search (O(n)) for large n, but only for sorted arrays.
- **Preprocessing:** If the array is unsorted and only a single search is needed, the cost of sorting (O(n log n)) may make Linear Search preferable.
- **Stability & Simplicity:** Linear Search is simpler and requires no preconditions.

## Quick Examples

- Use `linearsearch` for one-off lookups in small or unsorted arrays.
- Use `binarysearch` after sorting when performing repeated queries on large arrays.

---

Files:
- [linear_search.c](Lab-1/linear_search.c)
- [binary_search.c](Lab-1/binary_search.c)
