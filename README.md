This project involves a custom implementation of a weighted, undirected graph data structure and Dijkstra’s algorithm to find the shortest path between intersections in a city. The vertices represent intersections, and the edges represent travel times influenced by distance, speed limits, and real-time traffic conditions.

## Key Features

- **Dijkstra's Algorithm**: Applied to determine the lowest-weight path between intersections, considering the distance, speed limit, and a real-time traffic adjustment factor (A). If A = 0, the road is fully blocked, resulting in infinite travel time. Optimized Dijkstra's algorithm implementation to meet O(|E| log |V|) complexity, suitable for large-scale graphs with up to 500,000 vertices.

- **Dynamic Traffic Adjustment**: Routes can dynamically adjust based on real-time traffic conditions, modeled by an adjustment factor (0-1). This feature supports decision-making for optimal travel routes under varying conditions.
