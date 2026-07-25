# 14 — Stack

> The Last-In-First-Out (LIFO) data structure. Stacks are fundamental for tracking state, managing function calls, evaluating expressions, and solving complex problems with the Monotonic Stack technique.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Stack Implementation (Vector) | `stack_implementation_from_vector.cpp` | Easy | Array-based (Push, Pop, Top) | O(1) | O(N) |
| 2 | Stack Implementation (List) | `stack_implementation_from_list.cpp` | Easy | Linked List-based (Push, Pop) | O(1) | O(N) |
| 3 | Valid Parentheses | `valid_parentheses.cpp` | Easy | Stack for matching pairs | O(N) | O(N) |
| 4 | Next Greater Element | `next_greater_element.cpp` | Medium | Monotonic Decreasing Stack (Right to Left) | O(N) | O(N) |
| 5 | Right Greater Element | `right_greater.cpp` | Medium | Monotonic Stack | O(N) | O(N) |
| 6 | Previous Smaller Element | `previous_smaller_element.cpp` | Medium | Monotonic Increasing Stack | O(N) | O(N) |
| 7 | Stock Span Problem | `stock_span.cpp` | Medium | Monotonic Stack with Index Tracking | O(N) | O(N) |
| 8 | Min Stack | `min_stack.cpp` | Medium | Single Stack with Math Encoding | O(1) | O(N) |
| 9 | Largest Rectangle in Histogram | `largest_rectangle_in_histogram.cpp` | Hard | Monotonic Stack (Next & Prev Smaller) | O(N) | O(N) |
| 10 | The Celebrity Problem | `celebrity_problem.cpp` | Medium | Stack Elimination | O(N) | O(N) |
| 11 | Next Greater Element (Circular) | `next_greater_element_in_loop.cpp` | Medium | Monotonic Decreasing Stack (2N loop) | O(N) | O(N) |
| 12 | Trapping Rain Water | `traping_rainwater.cpp` | Hard | Monotonic Decreasing Stack | O(N) | O(N) |

> **N** = number of elements. Time complexity for monotonic stack problems is O(N) overall because each element is pushed and popped at most once.

## 🧠 Key Concepts

- **LIFO Principle**: The last element added is the first one to be removed. Think of a stack of plates.
- **Implementation Choices**: Stacks can be built using Arrays (vectors) for cache locality or Linked Lists for dynamic sizing without reallocation overhead.
- **Monotonic Stack**: A stack whose elements are strictly increasing or decreasing. This is the ultimate weapon for "Next Greater/Smaller" or "Previous Greater/Smaller" problems. By maintaining the monotonic property, we can find these elements in O(N) time instead of O(N²).
- **State Tracking**: Stacks are perfect for matching problems (like Valid Parentheses) where the most recent unmatched item needs to be resolved first.

## 📌 Tips

- For **Valid Parentheses**, always check if the stack is empty before popping. If you encounter a closing bracket and the stack is empty, it's invalid. At the end, the stack must be completely empty.
- When using a **Monotonic Stack**, always ask yourself: "Am I looking for the *next* or *previous* element?" and "Am I looking for a *greater* or *smaller* element?". This determines whether you iterate left-to-right or right-to-left, and whether you maintain an increasing or decreasing stack.
- For **Stock Span** and similar distance-based problems, store the *indices* in the stack rather than the values, or store a pair of `{value, index}`. This makes calculating the span (difference in indices) trivial.
