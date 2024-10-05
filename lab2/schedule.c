#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node { // contains node information
    char key;
    unsigned long priority;
};

struct element { // contains node and pointers to previous and next nodes
    struct node info;
    struct Elements * next, * prev;
};

struct DLLS { // double linked list
    struct Element * start;
};

struct queue {
    struct DLLS list;
    unsigned long elements; // number of entities in queue
};

void addElement(struct queue * L, struct node Node);
void removeElement (struct queue * L);
void runScheduled(struct queue * L);


int main (void) {

}

void addElement(struct queue * L, struct node Node) {

}

void runScheduled(struct queue * L) {

}

void removeElement (struct queue * L) {
    
}