#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

void getTime(char* time_string);

int main() {
    pid_t mainPid = getpid();
    pid_t pid1 = fork();

    if (pid1 == 0) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            char time_string[128]="";
            getTime(time_string);
            printf("%i %i %s\n", mainPid, getpid(), time_string);
            //system("ps -x");
        } else if (pid2 > 0) {
            int status;
            wait(&status);
            char time_string2[128]="";
            getTime(time_string2);
            printf("%i %i %s\n", mainPid, getpid(), time_string2);
        } else {
            //printf("something went wrong\n");
        }
    } else if (pid1 > 0) {
        int status;
        wait(&status);

        char time_string3[128]="";
        getTime(time_string3);
        printf("%i %i %s\n", mainPid, getpid(), time_string3);
    } else {
        printf("something went wrong\n");
    }
    return 0;
}

void getTime(char* time_string) {
    struct timeval tv;
    struct tm* ptm;
    long millis;
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);
    strftime(time_string, sizeof(time_string), "%H:%M", ptm);

    //SOME BUGS OR IDK, NO SECOND IN strftime with minutes
    char seconds_string[32];
    strftime(seconds_string, sizeof(seconds_string), "%S", ptm);
    millis = tv.tv_usec / 1000;
    sprintf(time_string,"%s:%s:%3ld",time_string, seconds_string, millis);
}