// graph.c - Implementation of graph functions

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Function to create a new graph with n nodes
Graph* create_graph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) return NULL;
    
    graph->n = n;
    graph->m = 0;
    graph->nodes = (Node*)calloc(n, sizeof(Node));
    
    if (!graph->nodes) {
        free(graph);
        return NULL;
    }
    
    // Initialize nodes with IDs
    for (int i = 0; i < n; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].edges = NULL;
    }
    
    return graph;
}

// Function to add an edge from source to destination
void add_edge(Graph* g, int src, int dst) {
    if (!g || src < 0 || src >= g->n || dst < 0 || dst >= g->n) {
        return; // Invalid input
    }
    
    // Create new edge
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    if (!newEdge) return;
    
    newEdge->dst = &g->nodes[dst];
    newEdge->next = NULL;
    
    // Add to end of list to maintain input order
    if (g->nodes[src].edges == NULL) {
        g->nodes[src].edges = newEdge;
    } else {
        Edge* current = g->nodes[src].edges;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEdge;
    }
    
    g->m++; // Increment edge count
}

// Function to print the graph in the required format
void print_graph(const Graph* g) {
    if (!g) return;
    
    for (int i = 0; i < g->n; i++) {
        printf("%d:", i);
        Edge* current = g->nodes[i].edges;
        while (current) {
            printf(" %d", current->dst->id);
            current = current->next;
        }
        printf(" \n");  // Add space before newline
    }
}

// Function to free the graph memory
void free_graph(Graph* g) {
    if (!g) return;
    
    // Free all edges
    for (int i = 0; i < g->n; i++) {
        Edge* current = g->nodes[i].edges;
        while (current) {
            Edge* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    // Free nodes array and graph
    free(g->nodes);
    free(g);
}
