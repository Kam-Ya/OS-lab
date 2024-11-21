#include <stdio.h>

int main(void) {
    int index;
    int offset;
    int pageTable[8] = {1, 5, 2, 9, 2, 7, 11, 4};

    printf("Enter a page number (0-7): ");
    scanf("%d", &index);
    printf("Enter offset: ");
    scanf("%d", &offset);

    printf("Frame number is: %d\n", pageTable[index]);
    printf("Offset is: %d\n", offset);

    return 0;
}