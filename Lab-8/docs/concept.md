# Lab 8 — Huffman Coding Using a Greedy Approach

## Problem data

The frequencies are given in hundreds:

| Letter | a | c | d | e | o | m | s | t | u |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Count | 20 | 11 | 2 | 10 | 15 | 8 | 10 | 22 | 2 |

The total of the listed counts is 100, so the actual file contains 100 times
these counts, or 10,000 letters.

## Huffman construction

At each step, remove the two least frequent nodes, combine them, and insert
their sum back into the priority queue:

| Step | Nodes combined | New node |
|---:|---|---:|
| 1 | d(2) + u(2) | 4 |
| 2 | 4 + m(8) | 12 |
| 3 | e(10) + s(10) | 20 |
| 4 | c(11) + 12 | 23 |
| 5 | o(15) + a(20) | 35 |
| 6 | 20 + t(22) | 42 |
| 7 | 23 + 35 | 58 |
| 8 | 42 + 58 | 100 |

Assign 0 to every left edge and 1 to every right edge. One optimal code is:

| Letter | Frequency | Huffman code |
|---|---:|---|
| a | 20 | 111 |
| c | 11 | 100 |
| d | 2 | 10100 |
| e | 10 | 000 |
| m | 8 | 1011 |
| o | 15 | 110 |
| s | 10 | 001 |
| t | 22 | 01 |
| u | 2 | 10101 |

The tree represented by these codes is:

```text
                                   (100)
                              0 /       \ 1
                             (42)       (58)
                         0 /    \ 1   0 /    \ 1
                        (20)     t   (23)    (35)
                     0 /  \ 1        0/  \1  0/  \1
                    e      s        c   (12) o    a
                                         0/  \1
                                        (4)   m
                                      0/  \1
                                      d      u
```

Ties can be resolved in another order, producing a different but equally
optimal code. The code lengths and total cost remain optimal.

## Memory calculation

The weighted cost for the listed 100-count block is:

```text
20(3) + 11(3) + 2(5) + 10(3) + 15(3)
+ 8(4) + 10(3) + 22(2) + 2(5) = 294 bits
```

Because every listed count represents 100 occurrences, the encoded file
requires:

```text
294 x 100 = 29,400 bits
29,400 / 8 = 3,675 bytes
```

This is 3.675 KB using decimal units, or approximately 3.589 KiB using
binary units. A fixed-width 8-bit representation would require 10,000 x 8 =
80,000 bits, so Huffman coding reduces the data portion to 36.75% of that
size. The code table itself is not included in this calculation.

## Complexity

Building the tree with a min-priority queue takes `O(n log n)` time for `n`
symbols and `O(n)` auxiliary space. Generating the codes takes `O(n)` time
for the tree, excluding the total length of the generated code strings.

Implementation: `Lab-8/Source code/huffman_code.cpp`
