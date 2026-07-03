# 11 — Advanced Backtracking Techniques

> When choices multiply and constraints tighten, backtracking becomes an art. This module explores classic, complex puzzles where you must systematically explore all possibilities and elegantly undo choices that lead to dead ends.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Combination Sum | `Combination-Sum.cpp` | Medium | Backtracking (Include/Exclude) | O(2^T) | O(T) |
| 2 | Knight's Tour | `Knight-Tour.cpp` | Hard | Backtracking (8 Directions) | O(8^(N²)) | O(N²) |
| 3 | N-Queens Problem | `N-QueenProblem.cpp` | Hard | Backtracking (Safe Placements) | O(N!) | O(N²) |
| 4 | Palindrome Partitioning | `Palindrome-Partioning.cpp` | Medium-Hard | Backtracking (Substring Check) | O(N × 2ᴺ) | O(N) |
| 5 | Rat In A Maze | `Rat-In-A-Maze.cpp` | Medium-Hard | Backtracking (4 Directions) | O(4^(N²)) | O(N²) |
| 6 | Sudoku Solver | `Sudoku-Solver.cpp` | Hard | Backtracking (1-9 Placements) | O(9^(N²)) | O(N²) |

> **N** = input size / grid size, **T** = target sum. Space complexity generally includes the recursion stack depth.

## 🧠 Key Concepts

- **State Space Tree**: Visualizing the problem as a tree of choices. Each node represents a state, and branches represent valid choices.
- **Pruning**: The key to efficient backtracking. Identifying invalid states early and returning (`return false`) before exploring deeper to save computation time.
- **Do and Undo**: The core pattern. Make a move (e.g., place a queen, mark visited), recurse, and if it fails or after exploring, undo the move to backtrack and try the next choice.
- **Constraints Checking**: Using helper functions like `isValid` or `isSafe` to verify if a move violates the problem's rules (e.g., checking rows/cols/diagonals in N-Queens).

## 📌 Tips

- Always define the base case first (e.g., all queens placed, maze exit reached, board fully filled).
- Be careful with passing collections by reference (like `vector<string>& path` or `vector<vector<int>>& board`) and remember to restore the state after the recursive call returns.
- For grid-based problems (Rat in a Maze, Knight's Tour), use direction arrays (`dr[]`, `dc[]`) to clean up the code for traversing neighbors instead of writing manual checks for every direction.
