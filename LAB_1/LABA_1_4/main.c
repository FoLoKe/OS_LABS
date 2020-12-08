#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    if(argc >= 3) {
        FILE *file1 = fopen(argv[1], "r");
        FILE *file2 = fopen(argv[2], "w");
        if (file1 && file2) {
            int c;
            do {
                c = fgetc(file1);
                if (c!= EOF) {
                    fputc(c, file2);
                }
            } while (c!= EOF);

            if(fclose(file1) == EOF || fclose(file2) == EOF) {
                printf("close error");
                return 2;
            }

            printf("end of file copying or read error");
        } else {
            printf("can't open files");
        }
    } else {
        printf("no file names provided");
    }

    return 0;
}
