// graph.h - Header file with structure definitions and function declarations

#ifndef GRAPH_H
#define GRAPH_H

// Forward declarations
typedef struct Edge Edge;
typedef struct Node Node;
typedef struct Graph Graph;

// Edge structure - represents a directed edge to a target node
struct Edge {
    Node* dst;      // Pointer to destination node
    Edge* next;     // Pointer to next edge in adjacency list
};

// Node structure - represents a graph node
struct Node {
    int id;         // Unique node identification
    Edge* edges;    // Pointer to first edge in adjacency list
};

// Graph structure - contains dynamically allocated array of nodes
struct Graph {
    Node* nodes;    // Array of nodes
    int n;         // Number of nodes (private field)
    int m;         // Number of edges (private field)
};

// Function declarations
Graph* create_graph(int n);
void add_edge(Graph* g, int src, int dst);
void print_graph(const Graph* g);
void free_graph(Graph* g);

#endif

