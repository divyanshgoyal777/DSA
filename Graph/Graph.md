# Graphs in Data Structures and Algorithms (DSA)

## 1. What is a Graph?

- A graph is a data structure made up of **nodes** (also called vertices) and **edges** that connect pairs of nodes.
- Graphs are used to represent relationships between objects, such as:
  - Connections on social media
  - Routes in maps
  - Network links

## 2. Types of Graphs

- **Undirected Graph**:
  - Edges have no direction.
  - If there's an edge between A and B, you can go both ways.
- **Directed Graph** (Digraph):
  - Each edge has a direction.
  - An edge from A to B means you can only go from A to B, not vice versa.
- **Weighted Graph**:
  - Edges have weights (values) representing the cost or distance between nodes.
- **Unweighted Graph**:
  - Edges have no weights.

## 3. Graph Terminology

- **Vertex** (Node): A fundamental part of a graph that represents an entity.
- **Edge**: A connection between two vertices.
- **Path**: A sequence of vertices connected by edges.
- **Cycle**: A path that starts and ends at the same vertex.
- **Degree**: The number of edges connected to a vertex.

## 4. Graph Representations

- **Adjacency Matrix**:
  - A 2D array where cell (i, j) is 1 if there’s an edge between vertices i and j, otherwise 0.
  - Great for dense graphs but uses more memory.
- **Adjacency List**:
  - An array of lists, where each list represents a vertex and contains its neighboring vertices.
  - More memory efficient for sparse graphs.

## 5. Graph Traversal

- **Depth-First Search (DFS)**:
  - Explores as far down a branch as possible before backtracking.
  - Uses a stack (either recursive call stack or explicit stack data structure).
- **Breadth-First Search (BFS)**:
  - Explores neighbors level by level.
  - Uses a queue.
- Both DFS and BFS are used to find paths, connected components, and cycles in graphs.

## 6. Common Graph Algorithms

- **Dijkstra’s Algorithm**:
  - Finds the shortest path from a source vertex to all other vertices in a weighted graph.
- **Bellman-Ford Algorithm**:
  - Also finds shortest paths but can handle negative weights.
- **Floyd-Warshall Algorithm**:
  - Finds shortest paths between all pairs of vertices (used for dense graphs).
- **Kruskal’s and Prim’s Algorithms**:
  - Used to find the Minimum Spanning Tree (MST) in weighted undirected graphs.

## 7. Applications of Graphs

- **Social Networks**: To model connections between users.
- **Web Crawling**: To traverse and index websites.
- **GPS and Maps**: To find shortest routes and optimize paths.
- **Network Routing**: For data packet transmission and load balancing.

## 8. Key Points to Remember

- **Connected Graph**: All vertices are reachable from any other vertex.
- **Disconnected Graph**: Contains at least one isolated vertex or group of vertices.
- **Acyclic Graph**: No cycles are present (e.g., trees).
- **Cyclic Graph**: Contains at least one cycle.

This overview provides a good starting point for understanding graphs in DSA. Try implementing some basic graph algorithms to get hands-on experience!
