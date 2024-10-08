#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node { // contains node information
    char* key;
    unsigned long priority;
};

struct element { // contains node and pointers to previous and next nodes
    struct node info;
    struct Elements * next, * prev;
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
void dequeue(struct queue * L);
struct queue * build();

int main (void) {

}

void enqueue(struct queue * L, struct node Node) {

}

void dequeue(struct queue * L) {

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