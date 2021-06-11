#include <stdbool.h>
#include <stdio.h>
#include "graph.h"

int main() {
    graph g;
    read_graph_from_file(&g);
    print_graph(&g);
    print_strongly_connected_components(&g);
    free_graph(&g);
    getchar(); getchar();
    return 0;
}

// D:\files\graph_connectivity\large_graph.txt
// D:\files\graph_connectivity\strongly_connected_graph.txt
// D:\files\graph_connectivity\weakly_connected_graph.txt
// D:\files\graph_connectivity\disconnected_graph.txt
// D:\files\graph_connectivity\one_vertex.txt
// D:\files\graph_connectivity\test.txt