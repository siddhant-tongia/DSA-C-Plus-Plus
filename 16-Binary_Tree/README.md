# 16 — Binary Tree

> A hierarchical data structure where each node has at most two children (left and right). Binary Trees form the foundation for BSTs, Heaps, and many divide-and-conquer algorithms.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Implementation & Basic Traversals | `implementation_and_basic_traversal_in_binary_tree.cpp` | Easy | Build from preorder + DFS/BFS traversals | O(N) | O(N) |
| 2 | Count of Nodes | `count_node.cpp` | Easy | Recursive DFS — left count + right count + 1 | O(N) | O(H) |
| 3 | Height of Tree | `height_of_tree.cpp` | Easy | Recursive DFS — max(leftHt, rightHt) + 1 | O(N) | O(H) |
| 4 | Sum of Nodes | `sum_of_node.cpp` | Easy | Recursive DFS — left sum + right sum + root data | O(N) | O(H) |

## 🧠 Key Concepts

- **Node Structure**: Each node stores data and two pointers — `left` and `right`. A `NULL` pointer indicates the absence of a child.
- **Building from Preorder**: A tree can be recursively built from a preorder sequence where `-1` denotes a null node. Process root → left subtree → right subtree.
- **Pre-order Traversal (Root → Left → Right)**: Visit the root first, then recursively traverse the left and right subtrees. Useful for copying/serializing a tree.
- **In-order Traversal (Left → Root → Right)**: Recursively traverse the left subtree, visit the root, then the right subtree. Produces sorted output for BSTs.
- **Post-order Traversal (Left → Right → Root)**: Recursively traverse both subtrees before visiting the root. Useful for deletion and expression evaluation.
- **Level-order Traversal (BFS)**: Uses a queue to visit nodes level by level. A `NULL` marker in the queue signals the end of a level, enabling level-wise printing.
- **Count of Nodes**: Recursively count nodes in left and right subtrees, then return `leftCount + rightCount + 1`. Base case: a `NULL` node returns `0`.
- **Height of Tree**: Recursively compute the height of left and right subtrees, then return `max(leftHt, rightHt) + 1`. Base case: a `NULL` node has height `0`.
- **Sum of Nodes**: Recursively sum the left and right subtrees, then return `leftSum + rightSum + root->data`. Base case: a `NULL` node contributes `0`.

## 📌 Tips

- Use a `NULL` sentinel in the queue during level-order traversal to detect when one level ends and the next begins.
- Pre/In/Post-order are all DFS-based and naturally implemented with recursion (implicit stack). Level-order is BFS-based and requires a queue.
- The time complexity for all four traversals is **O(N)** since every node is visited exactly once.
- Count, Height, and Sum all follow the same recursive pattern: solve for left subtree, solve for right subtree, combine results at the root. Only the combine step differs.
- Space complexity for recursive solutions is **O(H)** where H is the height of the tree (recursion stack). In the worst case (skewed tree), H = N.
