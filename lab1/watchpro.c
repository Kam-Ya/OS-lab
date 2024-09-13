#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
    char buf[62]={0x0};
    int value=0;
    FILE *fd = fopen("/proc/meminfo","r");
}