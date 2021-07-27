#include <vector>
#include <utility> //for pair
#include <queue>
#include <ostream>

class Graph{
    private:
        // 2D Vector of Pair objects representing our ADJACENCY LIST. Each pair represents {destination, cost} (as described in the lab handout) with source being determined by the index in the list the pair is at.
        std::vector<std::vector<std::pair<int,int>>> adj_list;
        // This function is in place to make adding new Vertices easy. It ensures that adj_list is as long as it needs to be in order to represent the Vertices being added to the Graph. This function should be called every time addEdge is called!
        void ensureValidGraph(int source, int destination);
        // Performs a Depth-First Search starting from Vertex vertex and outputs the order that the Vertices are visited.
        void DFS(int vertex, std::vector<bool> &visited, std::ostream& os);
        // Performs a Breadth-First Search starting from Vertex vertex and outputs the order that the Vertices are visited.
        void BFS(std::queue<int> &vertex_queue, std::vector<bool> &discovered, std::ostream& os);

    public:
        // Constructor
        Graph();
        // Displays the graph. This function has been completed in graph.cpp-- DO NOT modify it.
        void displayGraph(std::ostream& os = std::cout); 
        // Accepts a source, destination, and cost. Pushes a new Pair object into the correct location in adj_list.
        void addEdge(int source, int destination, int cost);
        // DFS helper function. Sets up what is needed to call the worker BFS that you will implement. This function has been completed in graph.cpp-- DO NOT modify it.
        void DFS(int vertex, std::ostream& os);
        // BFS helper function. Sets up what is needed to call the worker BFS that you will implement. This function has been completed in graph.cpp-- DO NOT modify it.
        void BFS(int vertex, std::ostream& os);
};