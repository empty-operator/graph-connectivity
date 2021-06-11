#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void push(list **head, int vertex) {
    list *new = malloc(sizeof(list));
    if (new != NULL) {
        new->vertex = vertex;
        new->next = *head;
        *head = new;
    }
}

int pop(list **head) {
    int vertex = (*head)->vertex;
    list *new_head = (*head)->next;
    free(*head);
    *head = new_head;
    return vertex;
}

bool is_empty(list *head) {
    return head == NULL;
}

void free_list(list *head) {
    list *node = head;
    while (node != NULL) {
        list *next = node->next;
        free(node);
        node = next;
    }
}
