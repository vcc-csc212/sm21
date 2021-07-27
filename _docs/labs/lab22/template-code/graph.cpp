#include "graph.h"
#include <iostream>


/*********************** BEGIN: Public functions provided for you ***********************/

Graph::Graph(){
    // nothing to do here
}

void Graph::displayGraph(){
    for(unsigned int i = 0; i < this->adj_list.size(); i++){
        std::cout << i << ": ";
        for(unsigned int j = 0; j < this->adj_list[i].size(); j++){
            std::cout << "(" << this->adj_list[i][j].first << "," << this->adj_list[i][j].second << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::DFS(int vertex, std::ostream& os){
    std::vector<bool> visited(this->adj_list.size(), false);
    DFS(vertex, visited, os);
}

void Graph::BFS(int vertex, std::ostream& os){
    std::queue<int> vertex_queue;
    std::vector<bool> discovered(this->adj_list.size(), false);

    discovered[vertex] = true;
    vertex_queue.push(vertex);

    BFS(vertex_queue, discovered, os);
}

/*********************** END: Public functions provided for you ***********************/

/*********************** BEGIN: Public functions for you to implement ***********************/

void Graph::addEdge(int source, int destination, int cost){
    /**
     * Accepts a source, destination, and cost. 
     * Pushes a new Pair object into the correct location in adj_list. 
     * Algorithm:
     *  ensure 'adj_list' is the correct size (Hint: Which function do we have that's supposed to do this?)
     *  create an edge from 'source' to 'destination' with the weight as 'cost'
     *  create an edge from 'destination' to 'source' with the weight as 'cost'
     **/    
}

/*********************** END: Public functions for you to implement ***********************/

/*********************** BEGIN: Private Helper Functions for you to implement ***********************/

void Graph::ensureValidGraph(int source, int destination){
    /**
     * This function is in place to make adding new Vertices easy. 
     * It ensures that adj_list is as long as it needs to be in order to represent the Vertices being added to the Graph. 
     * This function should be called every time addEdge is called! 
     * Algorithm:
     *  'l' = max(source, destination)
     *  while 'adj_list' is smaller than the # of vertices we need:
     *      push an empty Vector of Pairs onto 'adj_list'
     **/
}

void Graph::BFS(std::queue<int> &vertex_queue, std::vector<bool> &discovered, std::ostream& os){
    /**
     * Performs a Breadth-First Search starting from Vertex vertex and outputs the order that the Vertices are visited. 
     * Algorithm:
        if 'vertex_queue' is empty:
            return

        'current_vertex' = front of 'vertex_queue'
        pop 'vertex_queue'
            
        output 'vertex'
                
        for each Pair 'p' in this Vertex:
            if 'p' has not been discovered:
                mark 'p' discovered
                    push 'p' into 'vertex_queue'
                    
        BFS('vertex_queue', 'discovered', 'os')
     **/

}


void Graph::DFS(int vertex, std::vector<bool> &visited, std::ostream& os){
    /**
     * Performs a Depth-First Search starting from Vertex vertex and outputs the order that the Vertices are visited. 
     * Algorithm:
        mark 'vertex' visited
        output 'vertex'

        for each Pair 'p' in this Vertex:
            if 'p' has not been visited
                    DFS('p', 'visited', os)
     **/

}

/*********************** END: Private Helper Functions for you to implement ***********************/
