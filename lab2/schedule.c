#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node { // contains node information
    char* key;
    unsigned long priority;
    int time;
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

void enqueue(struct queue * L, struct node Node);
void removeElement (struct queue * L);
struct node * dequeue(struct queue * L);
struct queue * build();

int main (void) {

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

struct node * dequeue(struct queue * L) {
    if (!L || !L->list || !L->list->start || L->elements == 0) { // checking if input is valid
        printf("Invalid Input");
        return;
    }

    struct node * values = malloc(sizeof(struct node));

    struct element * temp = L->list->start->next;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    L->elements--;
    values->key = temp->info.key;
    values->priority = temp->info.priority;
    values->time = temp->info.time;

    free(temp);
    return values;
}

void removeElement (struct queue * L) {
    
}

struct queue * build() { // build the structure of the queue, mostly memory assignment
    struct queue * Q = NULL;
    Q = (struct queue *) malloc(sizeof(struct queue));

    if (Q) {
        if (Q -> list = malloc(sizeof(struct DLLS))) {
            Q -> list -> start = malloc(sizeof(struct element));
        } else {
            printf("Error in assigning memory to list\n");
            return 0;
        }

        // since this is a double linked list im assigning the start node to point to itself both forwards and in reverse
        if (Q -> list -> start) { 
            Q -> list -> start -> next = Q -> list -> start;
            Q -> list -> start -> prev = Q -> list -> start;

            // start node doesnt need any information its never read besides its next and prev pointers
            Q -> list -> start -> info.key = NULL;
            Q -> list -> start -> info.priority = NULL;
            Q -> list -> start -> info.time = NULL;
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