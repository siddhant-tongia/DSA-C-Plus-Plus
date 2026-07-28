# 15 — Queue

> The First-In-First-Out (FIFO) data structure. Queues are fundamental for scheduling, buffering, and Breadth-First Search (BFS) traversals.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Queue Implementation (List) | `queue_implementation_from_list.cpp` | Easy | Linked List-based (Push, Pop) | O(1) | O(N) |
| 2 | Circular Queue Implementation (Array) | `circular_queue_implementation_from_array.cpp` | Easy | Array-based with wrapping indices | O(1) | O(N) |
| 3 | Queue Implementation (Stack) | `queue_implementation_using_stack.cpp` | Easy | Using two Stacks | O(N) | O(N) |

## 🧠 Key Concepts

- **FIFO Principle**: The first element added is the first one to be removed. Think of a line at a ticket counter.
- **Implementation Choices**: Queues can be implemented using Linked Lists (straightforward) or Arrays. Array implementations typically use a circular approach to avoid O(N) shifting when elements are dequeued.
- **Circular Queue**: Resolves the limitation of standard array-based queues by wrapping around to the beginning of the array when the end is reached, efficiently utilizing available space.

## 📌 Tips

- For array-based circular queues, the next position is calculated using modulo arithmetic: `(index + 1) % capacity`.
- Always track the `front` and `rear` (or `size`) to differentiate between an empty queue and a full queue.
