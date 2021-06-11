#ifndef GRAPH_CONNECTIVITY_LIST_H
#define GRAPH_CONNECTIVITY_LIST_H

typedef struct list {
    int vertex;
    struct list *next;
} list;

void push(list **head, int vertex);
int pop(list **head);
bool is_empty(list *head);
void free_list(list *head);

#endif //GRAPH_CONNECTIVITY_LIST_H