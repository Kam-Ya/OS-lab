#include <stdio.h> 
#include <stdbool.h>
#include <math.h>

int main(void) {

    int blocks, files, sizeBlocks, sizeFiles;
    printf("input number of memory blocks: ");
    scanf("%d", &blocks);

    printf("input number of files: ");
    scanf("%d", &files);

    printf("input size of memory blocks: ");
    scanf("%d", &sizeBlocks);

    printf("input size of files: ");
    scanf("%d", &sizeFiles);

    // error checking if any inputs are 0 or less as that is redudent to the program
    if (blocks <= 0 || files <= 0 || sizeBlocks <= 0 || sizeFiles <= 0) { 
        printf("Please only input positive integers greater than 0\n");
        return 1;
    } else if (sizeBlocks < sizeFiles) { // checking if the files can fit into the blocks
        printf("Files can not fit into the memory blocks\n");
        return 1;
    }


    bool unusedBlocks[blocks]; 
    return 0;
}