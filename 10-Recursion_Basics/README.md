# 10 — Recursion Basics

> Trust the leap of faith — recursion teaches you to solve complex problems by breaking them into elegant, self-similar subproblems. It's the foundation for trees, graphs, dynamic programming, and backtracking.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Check if Array is Sorted | `ArrayIsSortedOrNot.cpp` | Easy | Recursive Comparison | O(N) | O(N) |
| 2 | Factorial | `Factorial.cpp` | Easy | Linear Recursion | O(N) | O(N) |
| 3 | Fibonacci | `Fibbonacci.cpp` | Easy | Recursive (Exponential) / Memoized | O(2ᴺ) / O(N) | O(N) |
| 4 | Generate All Permutations | `Permutation.cpp` | Medium-Hard | Backtracking (Swap + Recurse + Undo) | O(N × N!) | O(N) |
| 5 | Print All Subsets | `PrintAllSubsets.cpp` | Medium | Include / Exclude Pattern | O(2ᴺ) | O(N) |
| 6 | Binary Search (Recursive) | `RecursiveBinarySearch.cpp` | Easy | Divide and Conquer | O(log N) | O(log N) |
| 7 | Generate All Subsets | `Subsets.cpp` | Medium | Bit Manipulation / Recursion | O(N × 2ᴺ) | O(N) |
| 8 | Sum of N Numbers | `SumOfnNums.cpp` | Easy | Tail Recursion / Linear Recursion | O(N) | O(N) |

> **N** = input size / array length. Space complexity includes recursion stack depth.

## 🧠 Key Concepts

- **Base Case & Recursive Case**: Every recursive function must have a well-defined base case to terminate and a recursive case that moves toward it.
- **Call Stack**: Each recursive call adds a frame to the call stack — understand this to reason about space complexity and debug stack overflow errors.
- **Include / Exclude Pattern**: The fundamental technique for subset generation — at each element, branch into two paths: include it or skip it.
- **Backtracking**: Make a choice → recurse → undo the choice. This pattern powers permutations, N-Queens, Sudoku, and countless combinatorial problems.
- **Recursion Tree Visualization**: Draw the recursion tree to understand the branching factor, total nodes (time complexity), and depth (space complexity).
- **Tail Recursion**: When the recursive call is the last operation, compilers can optimize it into iteration — reducing stack usage.

## 📌 Tips

- **Think in Subproblems**: Before coding, clearly define: *"What is the smaller version of this problem?"* and *"What do I do with the result of the smaller problem?"*
- **Memoize Fibonacci**: Naive Fibonacci is O(2ᴺ) — adding a simple cache (`dp[]` array) drops it to O(N). This is your gateway to Dynamic Programming.
- **Trust the Recursion**: Don't try to mentally trace every recursive call. Define the function's contract (what it takes, what it returns), trust it works for smaller inputs, and build from there.
