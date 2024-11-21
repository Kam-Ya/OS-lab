#include <stdio.h>
#include <ctype.h>
#include "DLL.h"


int main(void) {
    struct queue * Q = build();
    int number;
    char buff[20];
    struct node current;
    char sequence [50];
    int hits = 0;
    int faults = 0;
    int total = 0;

    // collect input from user for later calculations;
    printf("How many frames: ");
    fgets(buff, sizeof(buff), stdin);
    number = atoi(buff);

    printf("Enter page (single digit) sequence seperated by spaces: ");
    fgets(sequence, sizeof(sequence), stdin);

    for (int i = 0; i < sizeof(sequence); i++) {
        // checks if input is valid and if current loop is workable
        if (sequence[i] == '\0') {
            break;
        } else if (sequence[i] == ' ') {
            continue;
        } else if (isdigit(sequence[i]) == 0) {
            break;
        }

        current.key = (int) sequence[i];

        // finds if current page already exists adnd moves it to the front
        if (search(Q, current.key) != NULL) {
            hits++;
            dequeueFound(Q, current.key);
            enqueue(Q, current);
        } else { // otherwise adds element to front of queue, removing last element if necesarry
            faults++;
            if (Q->elements == number) {
                dequeue(Q);
                enqueue(Q, current);
            } else {
                enqueue(Q, current);
            }
        }   
        total++;
    }

    printf("----------------\nhits = %d\nfaults = %d\nhit ratio = %.2f\n----------------\n", hits, faults, (double) hits/total);


    return 0;
}
