# 04 — Searching and Binary Search

> Binary Search isn't just an algorithm — it's a *mindset*. Learn to halve your search space and solve problems in logarithmic time.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Binary Search | `binarysearch.cpp` | Easy | Iterative + Recursive Binary Search | O(log n) | O(1) / O(log n) |
| 2 | Peak Index in Mountain Array | `peakindex.cpp` | Medium | Modified Binary Search | O(log n) | O(1) |
| 3 | Search in Rotated Sorted Array | `rotatedsortedarray.cpp` | Medium | Binary Search with Pivot Detection | O(log n) | O(1) |
| 4 | Single Element in Sorted Array | `singleelement.cpp` | Medium | XOR / Binary Search on Index Parity | O(log n) | O(1) |

## 🧠 Key Concepts

- **Classic Binary Search** — The foundation: maintain `lo` and `hi` pointers, compute `mid`, and eliminate half the search space each iteration. Master both iterative and recursive forms.
- **Search Space Reduction** — Binary Search applies to *any* monotonic predicate, not just sorted arrays. If you can define a condition that flips from false → true (or vice versa), you can binary search on it.
- **Rotated Array Insight** — A rotated sorted array has two sorted halves. By checking which half `mid` falls in and whether the target lies within that half, you maintain O(log n).
- **Index Parity Trick** — In a sorted array where every element appears twice except one, pairs sit at (even, odd) indices. The single element disrupts this pattern, enabling binary search by checking `nums[mid] == nums[mid ^ 1]`.
- **Peak Finding** — A mountain array has a single peak. Comparing `nums[mid]` with `nums[mid + 1]` tells you which slope you're on, guiding the search toward the summit.

## 📌 Tips

- **Off-by-One Kills:** The #1 bug in binary search is an infinite loop from incorrect boundary updates. Always verify your loop invariant: use `lo <= hi` for element search, `lo < hi` for range narrowing.
- **Template It:** Develop a personal binary search template (e.g., `lo = 0, hi = n - 1`, `mid = lo + (hi - lo) / 2`) and stick with it to avoid subtle errors under interview pressure.
- **Think Beyond Arrays:** Binary Search on Answer (e.g., "find the minimum capacity to ship packages in D days") is a powerful technique — if the answer space is monotonic, binary search it.
