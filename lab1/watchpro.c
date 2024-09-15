// this file has been bullshitted to the extreme, wtf is this


#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>

int isPID(struct dirent *current);

int main(void) {
    char * path[268]; // d_name = 256, 5 for /proc, 7 for /status
    char buf[62];
    char * endptr;
    int pid;
    struct dirent *current;

    // creates file to read memory information
    FILE *fd = fopen("/proc/meminfo","r");

    // gets the first line /proc/meminfo
    fgets(buf, 62, fd);

    // writes numbers to another character array with added 0's as the number is represented in kilobytes, and writes it to an unsigned long
    char num[11] = {buf[16], buf[17], buf[18], buf[19], buf[20], buf[21], buf[22], buf[23], '0','0','0'};
    unsigned long memTotal = strtoull(num, &endptr, 10);

    // clears buffer for future use
    memset(buf, 0, 62);

    // closes /proc/meminfo
    fclose(fd);

    // opens /proc directory
    DIR * proc = opendir("/proc");

    // reads through proc directory
    while ((current = readdir(proc))) {
        // ensures current position in proc is a running process
        if (!isPID(current)) {
            continue;
        }

        snprintf(path, sizeof(path), "/proc/%s/stat");
        // TODO read required info from /proc/[PID]/stat
    }

}


// looks through file names in /proc, returning 1 for every pid found and 0 for eveything else
int isPID(struct dirent *current) {
    for (char * name = current->d_name; *name; name++) {
        if (!isdigit(name)) {
            return 0;
        }
    }
    return 1;
}