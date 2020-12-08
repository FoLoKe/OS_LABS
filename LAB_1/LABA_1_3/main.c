#include <stdio.h>


int main(int argc, char *argv[], char *envp[]) {
    if(argc >= 3) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            char count =  *argv[2];
            count -= '0';
            int counter;
            int c;

            //Ctrl + D to stop reading
            do {
                counter = 0;
                do {
                    c = fgetc(file);
                    if (c!= EOF) {
                        printf("%c", c);
                        if(c != 10) {
                            counter++;
                        }
                    } else {
                        if(fclose(file) == EOF) {
                            printf("close error");
                            return 2;
                        }
                        printf("end of file or read error");
                        return 0;
                    }
                } while (counter < count || count == 0);
                getchar();
            } while (1);
        } else {
            printf("can't open file");
        }
    } else {
        printf("no file name or rows count has not provided");
    }

    return 0;
}