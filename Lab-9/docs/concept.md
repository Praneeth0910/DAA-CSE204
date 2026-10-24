# Lab 9 — All-Pairs Shortest Path (Floyd-Warshall Algorithm)

## Problem data

A directed weighted graph with **4 vertices** and the following edges:

| Source | Destination | Weight |
|-------:|------------:|-------:|
| 1 | 2 | 3 |
| 1 | 4 | 7 |
| 2 | 3 | 2 |
| 3 | 4 | 1 |

All other pairs have no direct edge (represented as ∞).

Initial distance matrix:

|   |  1  |  2  |  3  |  4  |
|--:|:---:|:---:|:---:|:---:|
| **1** | 0 | 3 | ∞ | 7 |
| **2** | ∞ | 0 | 2 | ∞ |
| **3** | ∞ | ∞ | 0 | 1 |
| **4** | ∞ | ∞ | ∞ | 0 |

## Floyd-Warshall construction

The algorithm iterates over each vertex `k` (1 to 4) as a potential
intermediate stop and relaxes every pair `(i, j)` using the rule:

```
if dist[i][k] + dist[k][j] < dist[i][j]:
    dist[i][j] = dist[i][k] + dist[k][j]
```

### Iteration k = 1 (vertex 1 as intermediate)

No pair can be improved via vertex 1 (no incoming edges to vertex 1 exist from
others in this graph). Matrix unchanged.

### Iteration k = 2 (vertex 2 as intermediate)

Path 1→3 relaxed: 1→2→3 costs 3+2 = **5** (was ∞)

|   |  1  |  2  |  3  |  4  |
|--:|:---:|:---:|:---:|:---:|
| **1** | 0 | 3 | **5** | 7 |
| **2** | ∞ | 0 | 2 | ∞ |
| **3** | ∞ | ∞ | 0 | 1 |
| **4** | ∞ | ∞ | ∞ | 0 |

### Iteration k = 3 (vertex 3 as intermediate)

Path 1→4 relaxed: 1→2→3→4 costs 5+1 = **6** (was 7)  
Path 2→4 relaxed: 2→3→4 costs 2+1 = **3** (was ∞)

|   |  1  |  2  |  3  |  4  |
|--:|:---:|:---:|:---:|:---:|
| **1** | 0 | 3 | 5 | **6** |
| **2** | ∞ | 0 | 2 | **3** |
| **3** | ∞ | ∞ | 0 | 1 |
| **4** | ∞ | ∞ | ∞ | 0 |

### Iteration k = 4 (vertex 4 as intermediate)

No further improvements possible (no outgoing edges from vertex 4).  
Matrix unchanged — this is the **final shortest-distance matrix**.

## Final shortest paths

| Pair | Distance | Path |
|------|:--------:|------|
| 1 → 2 | 3 | 1 → 2 |
| 1 → 3 | 5 | 1 → 2 → 3 |
| 1 → 4 | 6 | 1 → 2 → 3 → 4 |
| 2 → 3 | 2 | 2 → 3 |
| 2 → 4 | 3 | 2 → 3 → 4 |
| 3 → 4 | 1 | 3 → 4 |
| All others | ∞ | No path |

## Graph visualisation

```text
       3           2           1
  1 -------> 2 -------> 3 -------> 4
  |                               /
  |__________7___________________/
             (direct, but 6 < 7 via 1→2→3→4)
```

## Complexity

| Aspect | Value |
|--------|-------|
| Time | O(V³) — three nested loops over V vertices |
| Space | O(V²) — distance and path-reconstruction matrices |
| Handles negative edges | Yes (provided no negative-weight cycles) |

The algorithm improves upon running Dijkstra's algorithm from every source
(O(V · E log V)) when the graph is dense (E ≈ V²), giving a simpler
O(V³) bound with the same asymptotic cost.

Implementation: `Lab-9/Source code/floyd_warshall.cpp`
