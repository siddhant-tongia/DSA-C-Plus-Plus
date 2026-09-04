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
| 7 | Detect Cycle in Directed Graph (DFS) | `detect_cycle_in_directed_graph_using_DFS.cpp` | Medium | Use DFS with a path visited array. If an adjacent node is already in the current path, a cycle exists. | O(V + E) | O(V) |
| 8 | Rotting Oranges | `rotting_oranges.cpp` | Medium | Use Multi-source BFS starting with all initially rotten oranges. Track time and check if any fresh oranges are left. | O(N * M) | O(N * M) |
| 9 | Course Schedule | `course_schedule_problem.cpp` | Medium | Use DFS to detect a cycle in a directed graph using a path visited array. If a cycle exists, return false. | O(V + E) | O(V) |
| 10 | Flood Fill Algorithm | `flood_fill_algorithm.cpp` | Easy | Use DFS to traverse and replace connected pixels of the original color with the new color. | O(N * M) | O(N * M) |
| 11 | Course Schedule II | `course_schedule_problem_2.cpp` | Medium | Use Topological Sort (DFS with a stack) to find a valid ordering of courses. | O(V + E) | O(V) |
| 12 | Dijkstra's Algorithm | `dijkstras_algorithm.cpp` | Medium | Use a priority queue (min-heap) to find the shortest path from a source node to all other nodes. | O(E log V) | O(V + E) |
| 13 | Topological Sort (Kahn's Algorithm) | `topological_sort_using_kahns_algorithm.cpp` | Medium | Calculate in-degrees of nodes. Use a Queue to process nodes with 0 in-degree and reduce in-degrees of adjacent nodes. | O(V + E) | O(V) |
| 14 | Bellman Ford Algorithm | `bellman_ford_algorithm.cpp` | Medium | Relax all edges V-1 times to find the shortest path. Can handle negative weights and detect negative cycles. | O(V * E) | O(V) |
| 15 | Prim's Algorithm (MST) | `prims_algorithm.cpp` | Medium | Use a priority queue (min-heap) to greedily connect the minimum weight edge to the growing spanning tree. | O(E log V) | O(V + E) |
| 16 | Minimum Cost to Connect All Points | `minimum_cost_to_connect_all_points.cpp` | Medium | Use Prim's Algorithm with a min-heap, computing Manhattan distance dynamically as edge weights. | O(V² log V) | O(V²) |
| 17 | Cheapest Flights Within K Stops | `cheapest_flight_within_k_stop.cpp` | Medium | Use BFS with a queue storing `{node, {cost, stops}}`. Process level by level based on stops, updating minimum cost to reach each node. | O(K * E) | O(V + E) |
| 18 | Bridge in Graph | `bridge_in_graph.cpp` | Hard | Use Tarjan's Algorithm (DFS). Track discovery time and lowest reachable time for each node to find critical connections (bridges). | O(V + E) | O(V) |

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
