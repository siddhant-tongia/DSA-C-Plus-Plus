# 18 — Graphs

> A Graph is a non-linear data structure consisting of vertices (nodes) and edges (lines connecting them), widely used to model real-world relationships like networks, maps, and social connections.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Implementation of Graph | `implementation_of_graph.cpp` | Easy | Use an adjacency list (hash map/vector) or an adjacency matrix to represent the connections between nodes. | O(V + E) | O(V + E) |
| 2 | BFS Traversal | `BFS_traversal.cpp` | Easy | Traverse the graph level by level using a Queue. | O(V + E) | O(V) |
| 3 | DFS Traversal | `DFS_traversal.cpp` | Easy | Traverse the graph depth-wise using Recursion (Call Stack). | O(V + E) | O(V) |
| 4 | Detect Cycle in Undirected Graph (BFS) | `detect_cycle_in_undirected_graph_using_BFS.cpp` | Medium | Use BFS. Keep track of the parent of each node. If an adjacent visited node is not the parent, a cycle exists. | O(V + E) | O(V) |
| 5 | Detect Cycle in Undirected Graph (DFS) | `detect_cycle_in_undirected_graph_using_DFS.cpp` | Medium | Use DFS. Pass the parent node in the recursive call. If an adjacent visited node is not the parent, a cycle exists. | O(V + E) | O(V) |
| 6 | Number of Islands | `number_of_islands.cpp` | Medium | Traverse matrix. For each unvisited '1', increment count and use DFS to mark connected '1's as visited. | O(N * M) | O(N * M) |

## 🧠 Key Concepts

- **Vertices (Nodes)**: The fundamental units of a graph.
- **Edges**: The links connecting pairs of vertices. They can be directed or undirected.
- **Adjacency Matrix**: A 2D array of size `V x V` where `matrix[i][j]` is 1 if there is an edge from vertex `i` to vertex `j`, otherwise 0.
- **Adjacency List**: An array of lists where each element `i` contains a list of vertices adjacent to vertex `i`.
- **Directed Graph**: Edges have a direction (e.g., from A to B).
- **Undirected Graph**: Edges are bidirectional.
- **Weighted Graph**: Edges have an associated weight or cost.

## 📌 Tips

- Adjacency List is generally preferred over Adjacency Matrix because it saves space for sparse graphs.
- Understand Depth First Search (DFS) and Breadth First Search (BFS) as they are the building blocks for most graph algorithms.
- Always check if the graph is connected or has disconnected components, and handle loops/cycles depending on the problem.
