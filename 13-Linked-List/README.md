# 13 — Linked List

> The foundation of dynamic data structures. Linked Lists teach you pointer manipulation, memory management, and the elegance of node-based thinking — skills that are essential for trees, graphs, and beyond.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Linked List Implementation | `List.cpp` | Easy | Node Class (Push, Pop, Insert) | O(N) | O(N) |
| 2 | Middle of Linked List | `Middle_Of_List.cpp` | Easy | Slow & Fast Pointer (Tortoise-Hare) | O(N) | O(1) |
| 3 | Reverse Linked List | `Reverse_List.cpp` | Easy | Iterative (Three Pointers) | O(N) | O(1) |
| 4 | Linked List Has Cycle | `has_cycle.cpp` | Easy | Floyd's Cycle Detection | O(N) | O(1) |
| 5 | Detect Cycle Start Node | `detect_cycle.cpp` | Medium | Floyd's Algorithm (Two-Phase) | O(N) | O(1) |
| 6 | Merge Two Sorted Lists | `merge_two_lists.cpp` | Easy | Recursive Merge | O(N + M) | O(N + M) |
| 7 | Doubly Linked List Implementation | `Doubly_List.cpp` | Easy | Node Class (Push, Pop) | O(N) | O(N) |
| 8 | Circular Linked List Implementation | `Circular_List.cpp` | Easy | Node Class (Push, Pop) | O(N) | O(N) |
| 9 | Copy List with Random Pointer | `copy_random_list.cpp` | Medium | Hash Map (Node Mapping) | O(N) | O(N) |
| 10 | Swap Nodes in Pairs | `swap_pairs.cpp` | Medium | Iterative (Three Pointers) | O(N) | O(1) |
| 11 | Reverse Nodes in K-Group | `reverse_k_group.cpp` | Hard | Recursive (Reverse K then Recurse) | O(N) | O(N/K) |
| 12 | Flatten Multilevel Doubly Linked List | `flatten.cpp` | Medium | Recursive Flattening (DFS) | O(N) | O(N) |

> **N** = total nodes, **M** = nodes in second list. Space for recursive solutions includes the call stack. Reverse K-Group recursion depth is O(N/K).

## 🧠 Key Concepts

- **Node Structure**: Each node holds data and a pointer to the next node. Understanding this is the gateway to all pointer-based data structures.
- **Slow & Fast Pointers (Tortoise-Hare)**: A powerful technique where one pointer moves at 1× speed and another at 2×. Used for finding the middle, detecting cycles, and more.
- **Floyd's Cycle Detection**: Uses two pointers to not only detect a cycle but also find the exact node where the cycle begins — a classic interview question.
- **Recursive Thinking**: Many linked list problems (merge, reverse, reverse-K-group) have elegant recursive solutions that leverage the self-similar structure of the list.
- **In-Place Pair Swapping**: Swapping adjacent nodes requires careful tracking of `prev`, `first`, and `second` pointers — no extra memory needed.
- **K-Group Reversal**: Count k nodes ahead first; if fewer than k remain, leave them as-is. Recurse on the remainder after reversing each group.
- **Multilevel Flattening**: When a `child` pointer is found, recursively flatten it and splice the result between `curr` and `curr->next`, stitching `prev`/`next` links correctly.

## 📌 Tips

- Always handle edge cases first — empty list (`head == NULL`) and single-node lists.
- When reversing, track three pointers: `prev`, `curr`, and `next`. Drawing the pointer changes on paper before coding helps immensely.
- For cycle detection, remember: if `slow` and `fast` meet, reset one pointer to `head` and move both at 1× speed — they'll meet at the cycle start. The mathematical proof involves modular arithmetic on the cycle length.
- Recursive merge for two sorted lists is concise and elegant, but be aware it uses O(N + M) stack space — an iterative approach with a dummy head node is more space-efficient for large lists.
- For **Swap Pairs**, the key is updating `prev->next` to `second` after each swap so the preceding group links to the newly swapped head.
- For **Reverse K-Group**, always verify there are at least k nodes before reversing — if not, return `head` unchanged. The recursive call handles the rest of the list automatically.
- For **Flatten**, after splicing the child list in, walk to the tail of the newly inserted segment before continuing — this avoids skipping nodes in the original next chain.
