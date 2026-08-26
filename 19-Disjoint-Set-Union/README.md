# 19 — Disjoint Set Union

> Disjoint Set Union (DSU) or Union-Find is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It provides near-constant time operations (find and union) and is primarily used to detect cycles in an undirected graph and to implement Kruskal's Algorithm for Minimum Spanning Trees.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Implementation of DSU | `implementation.cpp` | Easy | Implement Union by Rank and Path Compression to optimize the Find and Union operations. | O(α(V)) | O(V) |
| 2 | Kruskal's Algorithm (MST) | `kruskals_algorithm.cpp` | Medium | Sort all edges by weight. Use DSU to greedily pick edges that don't form a cycle until V-1 edges are selected. | O(E log E) | O(V + E) |

## 🧠 Key Concepts

- **Disjoint Sets**: Two sets are disjoint if their intersection is empty.
- **Find Operation**: Determines which subset a particular element is in. Used to check if two elements are in the same subset.
- **Union Operation**: Joins two subsets into a single subset.
- **Path Compression**: An optimization for the Find operation that flattens the structure of the tree, making future Find operations faster.
- **Union by Rank / Size**: An optimization for the Union operation that always attaches the smaller tree to the root of the larger tree, keeping the tree relatively flat.
- **α(V)**: The inverse Ackermann function, which grows so slowly that for all practical purposes, it is ≤ 4. Thus, DSU operations are considered amortized constant time.

## 📌 Tips

- Always try to implement both **Path Compression** and **Union by Rank/Size** together. Using both ensures operations take amortized constant time, O(α(V)).
- DSU is the most efficient way to detect cycles in an **undirected** graph.
- Remember that standard DSU does not work for detecting cycles in a **directed** graph.
