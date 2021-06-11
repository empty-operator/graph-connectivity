#ifndef GRAPH_CONNECTIVITY_GRAPH_H
#define GRAPH_CONNECTIVITY_GRAPH_H
#include "list.h"

typedef struct {
    int numb_of_vert;
    list **adj;
} graph;

void read_graph_from_file(graph *g);
void print_graph(graph *g);
void dfs(graph *g, int vertex, bool *visited);
void dfs_with_stack(graph *g, int vertex, bool *visited, list **stack);
graph *transpose_graph(graph *g);
void print_strongly_connected_components(graph *g);
void free_graph(graph *g);

#endif //GRAPH_CONNECTIVITY_GRAPH_H