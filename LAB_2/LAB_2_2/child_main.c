#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("thread started %s %s %i\n", argv[0], argv[1], getpid());
    if(argc >= 2) {
        FILE *file1 = fopen(argv[0], "r");
        FILE *file2 = fopen(argv[1], "r");
        if(file1 && file2) {
            char a, b;
            int same = 1;
            int bytes = 0;
            do {
                a = getc(file1);
                b = getc(file2);
                if((a == EOF || b == EOF) && a == b) {
                    break;
                }
                bytes += 2;
                if (a == b) {
                    continue;
                } else {
                    same = 0;
                    break;
                }
            } while (a != EOF || b != EOF);

            printf("files: %s and %s, pid: %i, bytes: %i ", argv[0], argv[1], getpid(), bytes);
            if(same == 1) {
                printf("files are same\n");
            } else {
                printf("files are different\n");
            }

            if(fclose(file1) == EOF || fclose(file2) == EOF) {
                printf("close error\n");
                return 2;
            }
        } else {
            printf("cant open files\n");
        }
    }
    return 0;
}
