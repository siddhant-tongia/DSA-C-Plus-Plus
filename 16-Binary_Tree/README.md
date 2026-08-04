# 16 — Binary Tree

> A hierarchical data structure where each node has at most two children (left and right). Binary Trees form the foundation for BSTs, Heaps, and many divide-and-conquer algorithms.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Implementation & Basic Traversals | `implementation_and_basic_traversal_in_binary_tree.cpp` | Easy | Build from preorder + DFS/BFS traversals | O(N) | O(N) |
| 2 | Count of Nodes | `count_node.cpp` | Easy | Recursive DFS — left count + right count + 1 | O(N) | O(H) |
| 3 | Height of Tree | `height_of_tree.cpp` | Easy | Recursive DFS — max(leftHt, rightHt) + 1 | O(N) | O(H) |
| 4 | Sum of Nodes | `sum_of_node.cpp` | Easy | Recursive DFS — left sum + right sum + root data | O(N) | O(H) |
| 5 | Identical Tree | `identical_tree.cpp` | Easy | Recursive DFS — compare structure & values simultaneously | O(N) | O(H) |
| 6 | Subtree of Another Tree | `subtree_of_another_tree.cpp` | Easy | DFS + Identical check at each matching root | O(M×N) | O(H) |
| 7 | Diameter of Binary Tree | `diameter_of_tree.cpp` | Medium | Track max(leftHt + rightHt) while computing height | O(N) | O(H) |
| 8 | Right View of Binary Tree | `right_view.cpp` | Medium | BFS level-order — print last node of each level | O(N) | O(W) |
| 9 | Top View of Binary Tree | `top_view.cpp` | Medium | BFS + Horizontal Distance map — first node at each HD | O(N) | O(W) |

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
- **Identical Tree**: Two trees are identical if they have the same structure and every corresponding pair of nodes has equal values. Base case: both `NULL` → identical; one `NULL` → not identical.
- **Subtree of Another Tree**: Tree `S` is a subtree of tree `T` if there exists a node in `T` such that the subtree rooted at that node is identical to `S`. Traverse `T` and run an identical check whenever `node->data == subRoot->data`.
- **Diameter of Binary Tree**: The diameter is the longest path between any two nodes (measured in edges). It equals the maximum of `leftHeight + rightHeight` across all nodes. Compute it in O(N) by tracking the max sum during the height computation itself.
- **Right View**: The right view of a binary tree contains the last node visible at each level when viewed from the right side. Use BFS and print the last node processed in each level (`i == levelSize - 1`).
- **Top View**: The top view contains the first node visible at each horizontal distance (HD) when viewed from the top. Use BFS with `(node, HD)` pairs and a map — only record a node if its HD hasn't been seen before. The map's sorted keys give the left-to-right top view.

## 📌 Tips

- Use a `NULL` sentinel in the queue during level-order traversal to detect when one level ends and the next begins.
- Pre/In/Post-order are all DFS-based and naturally implemented with recursion (implicit stack). Level-order is BFS-based and requires a queue.
- The time complexity for all four traversals is **O(N)** since every node is visited exactly once.
- Count, Height, and Sum all follow the same recursive pattern: solve for left subtree, solve for right subtree, combine results at the root. Only the combine step differs.
- Space complexity for recursive solutions is **O(H)** where H is the height of the tree (recursion stack). In the worst case (skewed tree), H = N.
- The naive diameter approach (call height at every node) is O(N²). The optimized approach computes diameter inside the height function itself, achieving O(N).
- For Right View, you can also use DFS (preorder with right child first) and track the max level seen — the first node at each new level is the right-view node.
- For Top View, **horizontal distance** is the key idea: root is at HD 0, going left decrements HD, going right increments HD. BFS ensures the first node at each HD is the topmost one.
- **Width (W)** in BFS-based space complexity refers to the maximum number of nodes at any single level. In a complete binary tree, W ≈ N/2.
