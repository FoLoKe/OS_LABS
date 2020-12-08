#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {
    if(argc >= 4) {
        DIR *dir1 = opendir(argv[1]);
        DIR *dir2 = opendir(argv[2]);

        int maxThreads = atoi(argv[3]);

        printf("%s", "stared\n");
        for(int i = 0; i<maxThreads; i++) {
            char temp[20] = " ";
            sprintf(temp, "%s %i", "thread ", i);
            pid_t pid = fork();

            if(pid == 0) {
                if (execl("LAB_2_2_comparator", temp, "sasd", NULL) == -1) {
                    char *errorbuf = strerror(errno);
                    printf("%s", errorbuf);
                }
            } else if (pid > 0) {
                printf("created %s \n", temp);
            } else {
                printf("something went wrong i can feel it");
            }
        }

        while (waitpid(-1, NULL, 0)) {
            if(errno == ECHILD) {
                break;
            }
        }
    }
    return 0;
}
