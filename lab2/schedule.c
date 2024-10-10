#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node { // contains node information
    char* key;
    int priority;
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
struct node * dequeue(struct queue * L);
struct node * dequeueLong(struct queue * L);
struct queue * build();
struct node * dequeueShort(struct queue * L);

int main (void) {
    struct queue *high = build();
    struct queue *med = build();
    struct queue *low = build();

    // nodes for test cases
    struct node one = {.key = "high 1", .priority = 3, .time = 5};
    struct node two = {.key = "high 2", .priority = 3, .time = 3};
    struct node three = {.key = "medium 1, time = 5", .priority = 2, .time = 5};
    struct node four = {.key = "medium 2, time = 3", .priority = 2, .time = 3};
    struct node five = {.key = "low 1, time = 5", .priority = 2, .time = 5};
    struct node six = {.key = "low 2, time = 3", .priority = 2, .time = 3};

    struct node processes[] = {one, two, three, four, five, six};

    for (int i = 0; i < 6; i++) {
        if (processes[i].priority == 3) {
            enqueue(high, processes[i]);
        } else if (processes[i].priority == 2) {
            enqueue(med, processes[i]);
        } else {
            enqueue(low, processes[i]);
        }
    }

    while (high->list->start->next != high->list->start) {
        struct node *temp = dequeue(high);
        printf("dequeued: %s\npriority: %d\nlength: %d\n", temp->key, temp->priority, temp->time);
        free(temp); // no floating memory here
    }

    while (med->list->start->next != med->list->start) {
        struct node *temp = dequeue(med);
        printf("dequeued: %s\npriority: %d\nlength: %d\n", temp->key, temp->priority, temp->time);
        free(temp); // no floating memory here
    }

    while (low->list->start->next != low->list->start) {
        struct node *temp = dequeue(low);
        printf("dequeued: %s\npriority: %d\nlength: %d\n", temp->key, temp->priority, temp->time);
        free(temp); // no floating memory here
    }
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

struct node * dequeueLong(struct queue * L) {
    if (!L || !L->list || !L->list->start || L->elements == 0) { // checking if input is valid
        printf("Invalid Input");
        return;
    }

    struct element *current = L->list->start->next;
    struct element *MAX = current;

    // find the element that will take the longest
    while (current != L->list->start) {
        if (current->info.time >= MAX->info.time) {
            MAX = current;
        }
        current = current->next;
    }

    // Remove task from DLLS
    MAX->next->prev = MAX->prev;
    MAX->prev->next = MAX->next;

    struct node * temp = malloc(sizeof(struct node));
    *temp = MAX->info;
    L->elements--;
    free(MAX);
    free(current);
    return temp;
}

struct node * dequeueShort(struct queue * L) {
    if (!L || !L->list || !L->list->start || L->elements == 0) { // checking if input is valid
        printf("Invalid Input");
        return;
    }

    struct element *current = L->list->start->next;
    struct element *MIN = current;

    // find shortest task
    while (current != L->list->start) {
        if (current->info.time <= MIN->info.time) {
            MIN = current;
        }
        current = current->next;
    }

    // remove task from DLLS
    MIN->next->prev = MIN->prev;
    MIN->prev->next = MIN->next;

    struct node * temp = malloc(sizeof(struct node));
    *temp = MIN->info;
    L->elements--;
    free(MIN);
    free(current);
    return temp;
}