#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("waiting for input, Ctrl+D to stop\n");

    if(argv[1]) {
        FILE *file = fopen(argv[1], "w");
        if (file) {
            char a;
            //Ctrl + F to stop writing
            while((int)(a = (char)getchar()) != 6) {
                if (fputc(a, file) == EOF) {
                    printf("write error");
                    return 1;
                }
            }

            if(fclose(file) == EOF) {
                printf("saving error");
                return 2;
            }

            printf("file saved");
        } else {
            printf("can't create or open file");
        }
    } else {
        printf("no file name has provided");
    }

    return 0;
}
