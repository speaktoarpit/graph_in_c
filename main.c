// exercise.c - Main program that reads input and processes the graph

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int n, m;
    
    // Read number of nodes and edges
    scanf("%d %d", &n, &m);
    
    // Create graph
    Graph* g = create_graph(n);
    if (!g) {
        printf("Error creating graph\n");
        return 1;
    }
    
    // Read edges and add them to the graph
    for (int i = 0; i < m; i++) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        add_edge(g, src, dst);
    }
    
    // Print the adjacency list
    print_graph(g);
    
    // Free memory
    free_graph(g);
    
    return 0;
}
