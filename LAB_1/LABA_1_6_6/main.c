#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

void readCatalog(char* path, long min, long max);

int main(int argc, char *argv[], char *envp[]) {
    if(argc >= 4) {

        long min =  atol(argv[2]);

        char max =  atol(argv[3]);

        readCatalog(argv[1], min, max);
    }
    return 0;
}

void readCatalog(char* path, long min, long max) {

    DIR *dir1 = opendir(path);
    if(dir1) {
        struct dirent *dirent1;
        while ((dirent1 = readdir(dir1))) {
            if(*(dirent1->d_name) == '.') {
                continue;
            }
            char newPath[255] = "";//""
            sprintf(newPath, "%s/%s", path, dirent1 -> d_name);

            readCatalog(newPath, min, max);
        }

        if (closedir(dir1) == -1) {
            sprintf("%s", "close error");
        }
    } else {
        struct stat stat1;
        stat(path, &stat1);
        if(stat1.st_size >= min && stat1.st_size <= max) {
            printf("%s |||| size: %li \n", path, stat1.st_size);
        }
    }
}
