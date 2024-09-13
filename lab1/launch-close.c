#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
    int rc = fork();

    if (rc < 0) {
        printf("fork error");
    } else if (rc == 0) {

        // executes libre office in child program
        system("exec libreoffice --writer");
    } else {

        // waits 3 seconds before killing it
        sleep(3);
        system("kill $(ps aux | grep libreoffice | awk '{print $2}')");
    }
    

    return 0;
}