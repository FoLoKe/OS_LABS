#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>

#define ITERATIONS 25

void dangerous_function(void* arg);
void* thread_func1(void *arg);
void* thread_func2(void *arg);
int number;
pthread_mutex_t mutex;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
int condition = 0;
sem_t semaphore;
int sync_type = 0;

char *fileName;

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    if (argc >= 3) {
        sync_type = atoi(argv[1]);
        fileName = argv[2];
        if (sync_type == 1) {
            pthread_mutex_init(&mutex, NULL);
        } else if (sync_type == 2) {
            sem_init(&semaphore, 0, 0);
            sem_post(&semaphore);
        } else if (sync_type == 3) {
            pthread_mutex_init(&mutex, NULL);
        }
    }

    int res;
    int threads_numadd1 = 1;
    int threads_numadd2 = 2;

    pthread_t thread1;
    res = pthread_create(&thread1, NULL, thread_func1, &threads_numadd1);
    if (res != 0) {
        printf("error creating thread\n");
    }

    pthread_t thread2;
    res = pthread_create(&thread2, NULL, thread_func2, &threads_numadd2);
    if (res != 0) {
        printf("error creating thread\n");
    }

    pthread_cond_signal(&cond);
    res = pthread_join(thread1, NULL);
    if (res != 0) {
        printf("error in join\n");
    } else {
        printf("thread picked\n");
    }

    res = pthread_join(thread2, NULL);
    if (res != 0) {
        printf("error in join\n");
    } else {
        printf("thread picked\n");
    }
    return 0;
}

void* thread_func1(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    for(int a = 0; a < ITERATIONS ; a++) {
        if (sync_type == 1) {
            pthread_mutex_lock(&mutex);
        } else if (sync_type == 2) {
            sem_wait(&semaphore);
        } else if (sync_type == 3) {
            pthread_mutex_lock(&mutex);
            while (condition) {
                pthread_cond_wait(&cond, &mutex);
            }
        }

        dangerous_function(arg);

        if (sync_type == 1) {
            pthread_mutex_unlock(&mutex);
        } else if (sync_type == 2) {
            sem_post(&semaphore);
        } else if (sync_type == 3) {
            condition = 1;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
        }
        usleep((int)(10000.0 * rand()/RAND_MAX));
    }
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_testcancel();
}

void* thread_func2(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    for(int a = 0; a < ITERATIONS ; a++) {
        if (sync_type == 1) {
            pthread_mutex_lock(&mutex);
        } else if (sync_type == 2) {
            sem_wait(&semaphore);
        } else if (sync_type == 3) {
            pthread_mutex_lock(&mutex);
            while (!condition) {
                pthread_cond_wait(&cond, &mutex);
            }
        }

        dangerous_function(arg);

        if (sync_type == 1) {
            pthread_mutex_unlock(&mutex);
        } else if (sync_type == 2) {
            sem_post(&semaphore);
        } else if (sync_type == 3) {
            condition = 0;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
        }
        usleep((int)(10000.0 * rand()/RAND_MAX));
    }
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_testcancel();
}

char *buffer;
void dangerous_function(void* arg) {

    int add = *(int*)arg;
    FILE *file = fopen(fileName, "w+");
    if(file) {
        if (fputc((char)add + '0', file) == EOF) {
            char *errorbuf = strerror(errno);
            printf("%s\n", errorbuf);
            return;
        }
        fflush(file);
        printf("thread %d wrote\n",  add);
        usleep((int)(100000.0 * rand()/RAND_MAX));
        rewind(file);

        int read;

        if((read = fgetc(file)) != EOF) {
            printf("thread %d reading: %c\n", add, read);
        } else {
            char *errorbuf = strerror(errno);
            printf("%s\n", errorbuf);
            return;
        }
        fclose(file);
    } else {
        printf("error file opening");
    }

}
