This project involves a custom implementation of a weighted, undirected graph data structure and Dijkstra’s algorithm to find the shortest path between intersections in a city. The vertices represent intersections, and the edges represent travel times influenced by distance, speed limits, and real-time traffic conditions.

## Key Features

- **Graph Data Structure**: A generic implementation of a weighted, undirected graph using Object-Oriented Design principles, ensuring encapsulation and proper data handling.
  
- **Dijkstra's Algorithm**: Applied to determine the lowest-weight path between intersections, considering the distance, speed limit, and a real-time traffic adjustment factor (A). If A = 0, the road is fully blocked, resulting in infinite travel time. Optimized Dijkstra's algorithm implementation to meet O(|E| log |V|) complexity, suitable for large-scale graphs with up to 500,000 vertices.

- **Dynamic Traffic Adjustment**: Routes can dynamically adjust based on real-time traffic conditions, modeled by an adjustment factor (0-1). This feature supports decision-making for optimal travel routes under varying conditions.

## Command Features

- **LOAD**: Load graph data from a file to set up vertices and edges.
- **INSERT**: Add or update edges between vertices with specified distance and speed.
- **PRINT**: Display adjacent vertices for a specified vertex.
- **DELETE**: Remove a vertex and its associated edges from the graph.
- **PATH**: Output the lowest-weight path between two specified vertices.
- **TRAFFIC**: Update the traffic adjustment factor for a specific edge.
- **UPDATE**: Batch update traffic conditions for multiple edges from a file.
- **LOWEST**: Calculate the total weight of the shortest path between two vertices.

## Implementation Highlights

- **Error Handling**: Robust input validation with custom exceptions to handle invalid vertices and edges, ensuring that the graph remains consistent and accurate.
  
- **Performance**: Here’s a revised version of the README, framed as a completed project explanation:

---

# Graph Data Structure and Dijkstra's Algorithm

## Project Overview

This project involves a custom implementation of a weighted, undirected graph data structure and Dijkstra’s algorithm to find the shortest path between intersections in a city. The vertices represent intersections, and the edges represent travel times influenced by distance, speed limits, and real-time traffic conditions.

## Key Features

- **Graph Data Structure**: A generic implementation of a weighted, undirected graph using Object-Oriented Design principles, ensuring encapsulation and proper data handling.
  
- **Dijkstra's Algorithm**: Applied to determine the lowest-weight path between intersections, considering the distance, speed limit, and a real-time traffic adjustment factor (A). If A = 0, the road is fully blocked, resulting in infinite travel time.

- **Dynamic Traffic Adjustment**: Routes can dynamically adjust based on real-time traffic conditions, modeled by an adjustment factor (0-1). This feature supports decision-making for optimal travel routes under varying conditions.

## Command Features

- **LOAD**: Load graph data from a file to set up vertices and edges.
- **INSERT**: Add or update edges between vertices with specified distance and speed.
- **PRINT**: Display adjacent vertices for a specified vertex.
- **DELETE**: Remove a vertex and its associated edges from the graph.
- **PATH**: Output the lowest-weight path between two specified vertices.
- **TRAFFIC**: Update the traffic adjustment factor for a specific edge.
- **UPDATE**: Batch update traffic conditions for multiple edges from a file.
- **LOWEST**: Calculate the total weight of the shortest path between two vertices.

