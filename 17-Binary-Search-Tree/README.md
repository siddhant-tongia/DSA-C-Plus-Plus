# 17 — Binary Search Tree

> A node-based binary tree data structure where each node has a comparable key, and satisfies the condition that left subtree nodes have keys strictly lesser than the node's key, and right subtree nodes have keys strictly greater.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Build BST & Search | `build_BST.cpp` | Easy | Recursively insert nodes to maintain BST property. Search by comparing target with root. | O(H) | O(H) |
| 2 | Delete Node in BST | `delete_node_in_BST.cpp` | Medium | Find node, then handle 3 cases: leaf, 1 child, 2 children (replace with inorder successor). | O(H) | O(H) |
| 3 | Sorted Array to Balanced BST | `sorted_array_to_balanced_BST.cpp` | Easy | Recursively pick the middle element of the array as the root to ensure balance. | O(N) | O(log N) |
| 4 | Validate BST | `validate_BST.cpp` | Medium | Recursively check if each node's value falls strictly within a valid `(min, max)` range. | O(N) | O(H) |
| 5 | Kth Smallest Element in BST | `kth_smallest_in_BST.cpp` | Medium | Inorder traversal (Left -> Root -> Right) keeps track of count. When count reaches K, return the node's value. | O(N) | O(H) |
| 6 | Lowest Common Ancestor in BST | `lowest_common_ancesstor_in_BST.cpp` | Medium | If both p and q are smaller than root, go left. If both are greater, go right. Otherwise, root is LCA. | O(H) | O(H) |
| 7 | Minimum Distance Between BST Nodes | `minimm_distance_between_BST_nodes.cpp` | Easy | Inorder traversal to find min difference between adjacent nodes. | O(N) | O(H) |
| 8 | Construct BST from Preorder | `construct_BST_from_preorder.cpp` | Medium | Maintain an upper bound and recursively build the left and right subtrees. | O(N) | O(H) |

## 🧠 Key Concepts

- **Node Structure**: Same as a standard Binary Tree, with `left` and `right` child pointers.
- **BST Property**: For any node `N`, all nodes in `N.left` are `< N.data`, and all nodes in `N.right` are `> N.data`.
- **Inorder Traversal**: An inorder traversal (Left -> Root -> Right) of a Binary Search Tree always produces a sorted sequence.
- **Search**: Instead of exploring both left and right subtrees, we make a deterministic choice based on the current node's value. If `key < root->data`, go left. If `key > root->data`, go right.
- **Deletion**: 
  1. **Node with 0 children (Leaf)**: Simply delete the node and return `NULL`.
  2. **Node with 1 child**: Delete the node and replace it with its only child.
  3. **Node with 2 children**: Find the **inorder successor** (the smallest node in the right subtree), replace the target node's value with the successor's value, and then recursively delete the successor in the right subtree.

## 📌 Tips

- Time complexity for operations like Search, Insert, and Delete is strictly bound by the height of the tree `O(H)`.
- In a perfectly balanced BST, `H = log(N)`. However, in the worst-case scenario (a skewed tree), `H = N`, which degrades performance to `O(N)`.
- The inorder successor of a node `N` with two children is always the leftmost node of `N`'s right subtree.
