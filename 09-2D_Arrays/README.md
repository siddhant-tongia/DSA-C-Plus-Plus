# 09 — 2D Arrays

> Step into the matrix — literally. Two-dimensional arrays unlock grid-based problem solving, from image rotation to efficient search in sorted matrices.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Diagonal Sum of Matrix | `DigonalSum.cpp` | Easy | Primary + Secondary Diagonal Traversal | O(N) | O(1) |
| 2 | Find Missing and Repeated Value | `FindMissingAndRepeatedValue.cpp` | Medium | Frequency Count / Math Equations | O(N²) | O(N²) |
| 3 | 2D Array Input/Output | `Input_Output.cpp` | Easy | Nested Loop I/O | O(N × M) | O(N × M) |
| 4 | Linear Search in 2D Array | `LinerSearch.cpp` | Easy | Row-wise + Column-wise Scan | O(N × M) | O(1) |
| 5 | Maximum Column Sum | `MaiximumColumnSum.cpp` | Easy | Column-wise Accumulation | O(N × M) | O(1) |
| 6 | Maximum Row Sum | `MaximumRowSum.cpp` | Easy | Row-wise Accumulation | O(N × M) | O(1) |
| 7 | Search in Sorted 2D Matrix | `SearchInMatrix.cpp` | Medium | Binary Search (Treat as 1D) / Staircase Search | O(log(N×M)) | O(1) |
| 8 | Spiral Order Matrix Traversal | `SpiralMatrix.cpp` | Medium | Boundary Shrinking (Top→Right→Bottom→Left) | O(N × M) | O(1) |

> **N** = number of rows, **M** = number of columns

## 🧠 Key Concepts

- **Row-Major vs. Column-Major**: Understand memory layout — C++ uses row-major order. Traversing row-by-row is cache-friendly and faster.
- **Staircase Search**: For a row-wise and column-wise sorted matrix, start from the top-right (or bottom-left) corner to eliminate an entire row or column per comparison — O(N + M).
- **Flattened Index Mapping**: Treat an N×M matrix as a 1D array: `matrix[mid / M][mid % M]` enables standard binary search on sorted matrices.
- **Boundary Simulation**: Spiral traversal uses four boundaries (`top`, `bottom`, `left`, `right`) that shrink inward — a classic simulation pattern.
- **Diagonal Properties**: Primary diagonal has `i == j`; secondary diagonal has `i + j == N - 1`. For odd-sized matrices, the center element is shared.

## 📌 Tips

- **Spiral Traversal Pitfall**: Always check boundary conditions (`top <= bottom`, `left <= right`) inside the loop after each direction change to avoid duplicate prints.
- **Sorted Matrix Search**: If the matrix is fully sorted (each row starts after the previous row ends), use binary search. If only row-wise and column-wise sorted, use the staircase approach.
- **Index Gymnastics**: Practice converting between 1D and 2D indices fluently — it's a skill that appears in matrix problems, dynamic programming on grids, and graph traversals.
