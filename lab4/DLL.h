#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node { // contains node information
    int key;
};

struct element { // contains node and pointers to previous and next nodes
    struct node info;
    struct element * next, * prev;
};

struct DLLS { // double linked list
    struct element * start;
};

struct queue {
    struct DLLS * list;
    unsigned long elements; // number of entities in queue
};

struct queue * build() { // build the structure of the queue, mostly memory assignment
    struct queue * Q = NULL;
    Q = (struct queue *) malloc(sizeof(struct queue));

    if (Q) {
        if (Q -> list = malloc(sizeof(struct DLLS))) {
            Q -> list -> start;
        } else {
            printf("Error in assigning memory to list\n");
            return 0;
        }

        // since this is a double linked list im assigning the start node to point to itself both forwards and in reverse
        if (Q -> list -> start = malloc(sizeof(struct element))) { 
            Q -> list -> start -> next = Q -> list -> start;
            Q -> list -> start -> prev = Q -> list -> start;

        } else {
            printf("Error in assigning memory to start node");
            return 0;
        }
        
    } else {
        printf("Error in assigning memory for a the Queue");
        return 0;
    }

    return Q;
}

void enqueue(struct queue * L, struct node Node) {

    // create new element and place information into it
    struct element * E = (struct element *) malloc(sizeof(struct element));
    E->info = Node;

    // move pointers
    E->next = L->list->start->next;
    E->prev = L->list->start;
    L->list->start->next->prev = E;
    L->list->start->next = E;

    L->elements++;
}

struct node * dequeue(struct queue * L) { // FIFO
    if (!L || !L->list || !L->list->start || L->elements == 0) { // checking if input is valid
        printf("Invalid Input");
        return 0;
    }

    struct node * values;

    struct element * temp = L->list->start->prev;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    L->elements--;
    values->key = temp->info.key;

    free(temp);
    return values;
}

// search for specific element in queue returns 1 if the target is found, 0 if not
struct element * search (struct queue * L, int target) {
    struct element * E = malloc(sizeof(struct element));
    E = L->list->start->next;
    while (E != L->list->start) {
        if (E->info.key == target) {
            return E;
        }
        E = E->next;
    }
    return NULL;
}

struct node * dequeueFound(struct queue * L, int target ) { // FIFO
    if (!L || !L->list || !L->list->start || L->elements == 0) { // checking if input is valid
        printf("Invalid Input");
        return 0;
    }

    struct node * values;

    struct element * temp = search(L, target);
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    L->elements--;
    values->key = temp->info.key;

    free(temp);
    return values;
}

#endif