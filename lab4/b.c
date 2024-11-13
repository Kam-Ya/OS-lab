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


int main(void) {

    return 0;
}