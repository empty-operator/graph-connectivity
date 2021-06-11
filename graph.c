#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void read_graph_from_file(graph *g) {
    int numb_of_vert, temp;
    FILE *f = NULL;
    char fname[FILENAME_MAX];
    printf("Enter file name: ");
    gets_s(fname, FILENAME_MAX);
    fopen_s(&f, fname, "r");
    if (f != NULL) {
        fscanf_s(f, "%d", &numb_of_vert);
        g->numb_of_vert = numb_of_vert;
        g->adj = malloc(numb_of_vert * sizeof(list *));
        for (int i = 0; i < g->numb_of_vert; ++i) {
            g->adj[i] = NULL;
            fscanf_s(f, "%d", &temp);
            while (temp) {
                push(&g->adj[i], temp);
                fscanf_s(f, "%d", &temp);
            }
        }
    } else {
        fprintf(stderr, "File not found.\n\a");
        getchar(); getchar();
        exit(0);
    }
}

void print_graph(graph *g) {
    printf("\nThe graph has %d %s:\n", g->numb_of_vert, g->numb_of_vert > 1 ? "vertices" : "vertex");
    for (int i = 0; i < g->numb_of_vert; ++i) {
        printf("%d: ", i + 1);
        list *adjacency_list = g->adj[i];
        while (adjacency_list != NULL) {
            printf("%d -> ", adjacency_list->vertex);
            adjacency_list = adjacency_list->next;
        }
        printf("(0)\n");
    }
}

void dfs(graph *g, int vertex, bool *visited) {
    printf("%d -> ", vertex);
    visited[vertex - 1] = true;
    list *adjacency_list = g->adj[vertex - 1];
    while (adjacency_list != NULL) {
        if (!visited[adjacency_list->vertex - 1])
            dfs(g, adjacency_list->vertex, visited);
        adjacency_list = adjacency_list->next;
    }
}

void dfs_with_stack(graph *g, int vertex, bool *visited, list **stack) {
    visited[vertex - 1] = true;
    list *adjacency_list = g->adj[vertex - 1];
    while (adjacency_list != NULL) {
        if (!visited[adjacency_list->vertex - 1])
            dfs_with_stack(g, adjacency_list->vertex, visited, stack);
        adjacency_list = adjacency_list->next;
    }
    push(stack, vertex);
}

graph *transpose_graph(graph *g) {
    graph *transposed = malloc(sizeof(graph));
    transposed->numb_of_vert = g->numb_of_vert;
    transposed->adj = malloc(g->numb_of_vert * sizeof(list *));
    for (int i = 0; i < transposed->numb_of_vert; ++i)
        transposed->adj[i] = NULL;
    for (int i = 0; i < transposed->numb_of_vert; ++i) {
        list *adjacency_list = g->adj[i];
        while (adjacency_list != NULL) {
            push(&transposed->adj[adjacency_list->vertex] - 1, i + 1);
            adjacency_list = adjacency_list->next;
        }
    }
    return transposed;
}

void print_strongly_connected_components(graph *g) {
    list *stack = NULL;
    int numb_of_comp = 0;
    bool *visited = malloc(g->numb_of_vert * sizeof(bool));
    for (int i = 0; i < g->numb_of_vert; ++i)
        visited[i] = false;
    for (int i = 0; i < g->numb_of_vert; ++i)
        if (!visited[i])
            dfs_with_stack(g, i + 1, visited, &stack);
    graph *transposed = transpose_graph(g);
    for (int i = 0; i < g->numb_of_vert; ++i)
        visited[i] = false;
    printf("\nStrongly connected components:\n");
    while (!is_empty(stack)) {
        int vertex = pop(&stack);
        if (!visited[vertex - 1]) {
            printf("%d. ", ++numb_of_comp);
            dfs(transposed, vertex, visited);
            printf("(0)\n");
        }
    }
    if (numb_of_comp == 1)
        printf("\nThe graph is strongly connected.\n");
    else
        printf("\nThe graph isn`t strongly connected.\n");
    free(visited);
    free_graph(transposed);
    free(transposed);
}

void free_graph(graph *g) {
    for (int i = 0; i < g->numb_of_vert; ++i)
        free_list(g->adj[i]);
    free(g->adj);
}
