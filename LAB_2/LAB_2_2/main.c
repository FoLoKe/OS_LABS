#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
void sig_child(int signal);
void startThread(char* path1, char* path2);
int threadsCount;

int main(int argc, char *argv[], char *envp[]) {
    if(argc >= 4) {
        DIR *dir1 = opendir(argv[1]);
        DIR *dir2 = opendir(argv[2]);

        if (dir1 && dir2) {

            int maxThreads = atoi(argv[3]);
            threadsCount = 0;

            printf("%s", "stared\n");
            struct dirent *dirent1;
            while ((dirent1 = readdir(dir1))) {
                if(*(dirent1->d_name) == '.') {
                    continue;
                }
                char newPath1[255] = "";//""
                strcat(newPath1, argv[1]);
                strcat(newPath1, "/");
                strcat(newPath1, dirent1 -> d_name);

                struct dirent *dirent2;
                rewinddir(dir2);
                while ((dirent2 = readdir(dir2))) {
                    if(*(dirent2->d_name) == '.') {
                        continue;
                    }
                    char newPath2[255] = "";//""
                    strcat(newPath2, argv[2]);
                    strcat(newPath2, "/");
                    strcat(newPath2, dirent2 -> d_name);

                    while (threadsCount >= maxThreads) {

                    }

                    startThread(newPath1, newPath2);
                }
            }

            if(closedir(dir1) == -1) {
                printf("close error");
            }
            if(closedir(dir2) == -1) {
                printf("close error");
            }

            while (threadsCount>0) {

            }
        } else {
            printf("not a dirs");
        }
    } else {
        printf("too few arguments");
    }
    return 0;
}

void sig_child(int signal) {
    pid_t pid;
    int status;
    printf("terminated, threads count: %i\n", threadsCount - 1);
    threadsCount--;
}

void startThread(char* path1, char* path2) {
    char temp[20] = " ";
    printf("thread %s %s", path1, path2);
    signal(SIGCHLD, sig_child);
    threadsCount++;
    pid_t pid = fork();

    if (pid == 0) {
        if (execl("LAB_2_2_comparator", path1, path2, NULL) == -1) {
            char *errorbuf = strerror(errno);
            printf("%s", errorbuf);
        }
    } else if (pid > 0) {
        printf(" created %s \n", temp);
    } else {
        printf("something went wrong i can feel it");
    }
}
