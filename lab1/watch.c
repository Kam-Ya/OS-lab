#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
    while (1) {
        system("kill $(ps aux | grep libreoffice | awk '{print $2}')");
        sleep(1);
    }

    return;
}