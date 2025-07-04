#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge Edge;
typedef struct Node Node;
typedef struct Graph Graph;

struct Edge {
    Node* dst;
    Edge* next;
};

struct Node {
    int id;
    Edge* edges;
};

struct Graph {
    Node* nodes;
    int n;
    int m;
};

Graph* create_graph(int n);
void add_edge(Graph* g, int src, int dst);
void print_graph(const Graph* g);
void free_graph(Graph* g);

#endif
