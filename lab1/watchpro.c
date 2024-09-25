#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

int isPID(struct dirent *current);

int main(void) {
    char path[268]; // d_name = 256, 5 for /proc, 7 for /status
    char buf[62];
    char * endptr;
    int pid;
    struct dirent *current;
    FILE *fd;
    
    while (1) {

        int mem = 0;
        int tim = 0;
        char *memory[100][2];
        char *time[100][2];


        // opens /proc directory
        DIR * proc = opendir("/proc");

        // reads through proc directory
        while ((current = readdir(proc)) != NULL) {
            // ensures current position in proc is a running process
            if (!isPID(current)) {
                continue;
            }

            snprintf(path, sizeof(path), "/proc/%s/stat", current->d_name);
            FILE * fd = fopen(path, "r");
            if (fd == NULL) {
                printf("Error opening stat file\n");
                continue;
            }

            // sores info from /proc/[pid]/stat into the buffer
            char buffer[200];
            char temp[100];
            while(fgets(temp, 100, fd) != NULL) {
                strcat(buffer, temp);
            }

            char *token;
            int count = 1;
            token = strtok(buffer, " ");
            char* PID;
            char *name;

            // go through all the tokens looking for processes using more than 200Kb of memory or 3 minutes+ of cpu time
            while (token != NULL) {
                PID = token;
                
                if (count == 2) {
                    name = token;
                } else if (count == 14) {
                    if (!isdigit(token)) { 
                        printf("you messed up");
                        continue; // if this runs i messed up
                    }

                    if ((int) token/sysconf(_SC_CLK_TCK) >= 180) {
                        time[tim][0] = PID;
                        time[tim][1] = name;
                        tim++;
                    } 
                } else if (count == 24) { // checking if memory usage is 200kb or more
                    if (!isdigit(token)) {
                        printf("you messed up");
                        continue; // if this runs i messed up
                    }

                    if ((int) token >= 200000) {
                        memory[mem][0] = PID;
                        memory[mem][1] = name;
                        mem++;
                    }
                }
                count++;
                token = strtok(NULL, " ");
            }
            
            fclose(fd);
        }

        // prints the programs that meet the criteria to possibly be killed
        printf("Using more than 200K:\n");
        for (int i = 0; i < mem; i++) {
            printf("%d - %sn", i + 1, memory[i][0]);
        }

        printf("\nUsing more than 3 minutes:\n");
        for (int i = 0; i < tim; i++) {
            printf("%d - %sn", i + mem + 1, time[i][0]);
        }

        // gets input from user on which process to kill, or to pass and refresh
        int input;
        printf("Input the number of what program to kill, or any other number to wait for next refresh: ");
        scanf("%d", &input);

        //decides what to do with input
        char *command;
        if(input > 0 && input < mem + 1) {
            snprintf(command, sizeof(command), "kill %d", (int) memory[input - 1][0]);
            system(command);
        } else if (input > 0 && input < mem + tim + 1) {
            snprintf(command, sizeof(command), "kill %d", (int) time[input - 1 - mem][0]);
            system(command);
        } else {
            continue;
        }

    }

}


// looks through file names in /proc, returning 10 for every non PID found
int isPID(struct dirent *current) {
    int test = 0;

    for (char * name = current->d_name; *name; name++) {
        if (!isdigit(*name)) {
            return 0;
        }
    }

    return 1;
}