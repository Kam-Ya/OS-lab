#include <stdio.h> 
#include <stdbool.h>
#include <unistd.h>

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
    bool more = false;

    // all these ifs are redudent and need to be better optimised
    while (files != 0) {

        for (int i = 0; i < blocks; i++) { // release all memory as if processes finishes running
            unusedBlocks[i] = true;
            if (files != 0) {
                unusedBlocks[i] = false;
                files--;
            }
        }
        
        if (files != 0) {
            more = true; 
            printf("All memory blocks in use, waiting for free memory\n");
        }
        sleep(1);
    }

    if (more == false) { // output for the lab
        printf("All files fit into memory blocks on without having to wait!\n");
    } else {
        printf("all processes have been run!\n");
    }
    
    return 0;
}