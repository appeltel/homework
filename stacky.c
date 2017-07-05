/* make a simple stack as a linked list */
#include "stdio.h"
#include "stdlib.h"

struct node {
    void *data;
    struct node *next;
};

struct stack {
    struct node *head;
};

struct stack * new_stack() {
    struct stack *new_stack = malloc(sizeof(struct stack));
    new_stack->head = NULL;
    return new_stack;
}

void push(struct stack *s, void *data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node *current = s->head;
    if (current == NULL) {
        s->head = new_node;
        return;
    }
    while (current->next != NULL) current = current->next;
    current->next = new_node;
}

/* this function feels stinky */
void * pop(struct stack *s) {

    struct node *current = s->head;
    if (current == NULL) return NULL;

    while (current->next != NULL) current = current->next;
    void * result = current->data;
    free(current);

    /* set the last element to NULL */
    if (s->head->next == NULL) {
        s->head = NULL;
    } else {
        current = s->head;
        while (current->next->next != NULL) current = current->next;
        current->next = NULL;
    }

    return result; 
}

int main(int argc, char *argv[])
{
    struct stack * s = new_stack();
    int * a = malloc(sizeof(int));
    *a = 12;
    push(s, (void *)a);
    int * b = malloc(sizeof(int));
    *b = 4;
    push(s, (void *)b);
    int * c = malloc(sizeof(int));
    *c = 333;
    push(s, (void *)c);

    for (int i=0; i<3; i++) {
        int * item = (int *) pop(s);
        printf("popped: %d\n", *item);
    }
}

