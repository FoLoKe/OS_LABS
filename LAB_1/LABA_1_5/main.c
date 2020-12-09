#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
    if(argc >= 2) {
        char workingDirName[255];
        getcwd(workingDirName, 255);
        DIR *dir1 = opendir(workingDirName);
        DIR *dir2 = opendir(argv[1]);

        struct dirent *dirent1;

        printf("----current working catalog:----\n");
        while ((dirent1 = readdir(dir1))) {
            printf("%s\n", dirent1->d_name);
        }

        struct dirent *dirent2;
        printf("\n----Specified working catalog:----\n");
        while ((dirent2 = readdir(dir2))) {
            printf("%s\n", dirent2->d_name);
        }

        if (closedir(dir1) == -1 || closedir(dir2) == -1) {
            sprintf("%s", "close error");
        }
    }
    return 0;
}