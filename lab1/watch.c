#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>


// this program is meant to loop infinitely, so to end it kill the process (ctrl + c)
int main(void) {

    // inifite loop checking for any libre office instance and immediately kills it (repeating every second)
    while (1) {
        system("kill $(ps aux | grep libreoffice | awk '{print $2}')");
        sleep(1);
    }

    return;
}