# 06 — Binary Search on Answers

> When the answer itself becomes the search space — master the art of binary searching over possible results to crack optimization problems in logarithmic time.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Aggressive Cows (SPOJ) | `aggressivecow.cpp` | Hard | Binary Search on Min Distance + Greedy Placement | O(N log D) | O(1) |
| 2 | Book Allocation / Allocate Minimum Pages | `bookallocation.cpp` | Medium | Binary Search on Answer + Feasibility Check | O(N log S) | O(1) |
| 3 | Painter's Partition Problem | `painterpartition.cpp` | Medium-Hard | Binary Search on Answer + Greedy Partitioning | O(N log S) | O(1) |

> **N** = number of elements, **D** = max distance range, **S** = sum of all elements

## 🧠 Key Concepts

- **Binary Search on Answer**: Instead of searching in an array, search over the space of possible answers (e.g., minimum distance, maximum pages).
- **Feasibility Function**: For each candidate answer, write a helper function that checks whether that answer is achievable under the given constraints.
- **Monotonic Property**: These problems exhibit monotonicity — if an answer `x` is feasible, then all values greater (or lesser, depending on min/max) than `x` are also feasible.
- **Greedy Validation**: The feasibility check typically uses a greedy strategy to verify if the candidate answer works.
- **Search Space Bounds**: Carefully identify `low` and `high` — usually `low = min(array)` or `0`, and `high = sum(array)` or `max(range)`.

## 📌 Tips

- **Pattern Recognition**: If a problem asks to *minimize the maximum* or *maximize the minimum*, it's almost always Binary Search on Answer.
- **Get the Feasibility Right**: The binary search framework is the easy part — the real challenge is writing a correct and efficient `isPossible()` / `isValid()` function.
- **Edge Cases**: Always handle cases where the number of partitions equals the number of elements, or where a single element exceeds the candidate answer.
