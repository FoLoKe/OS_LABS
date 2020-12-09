#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

void dangerous_function(void* arg);
void* thread_func(void *arg);
int number;
pthread_mutex_t mutex;
pthread_cond_t cond;
int condition = 0;
sem_t semaphore;
int sync_type = 0;

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    if(argc >= 2) {
        sync_type = atoi(argv[1]);
        if(sync_type == 1) {
            pthread_mutex_init(&mutex, NULL);
        } else if (sync_type == 2) {
            sem_init(&semaphore, 0, 0);
            sem_post(&semaphore);
        } else if (sync_type == 3) {
            pthread_mutex_init(&mutex, NULL);
            pthread_cond_signal(&cond);

        }
    }

    int res;
    int threads_numadd1 = 1;
    int threads_numadd2 = 2;

    pthread_t thread1;
    res = pthread_create(&thread1, NULL, thread_func, &threads_numadd1);
    if (res != 0) {
        printf("error creating thread\n");
    }

    pthread_t thread2;
    res = pthread_create(&thread2, NULL, thread_func, &threads_numadd2);
    if (res != 0) {
        printf("error creating thread\n");
    }


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

void* thread_func(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    if(sync_type == 1) {
        pthread_mutex_lock(&mutex);
    } else if (sync_type == 2)  {
        sem_wait(&semaphore);
    } else if (sync_type == 3) {
        //pthread_mutex_lock(&mutex);
        while(condition > 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        condition = 1;
    }

    dangerous_function(arg);

    if(sync_type == 1) {
        pthread_mutex_unlock(&mutex);
    } else if (sync_type == 2) {
        sem_post(&semaphore);
    } else if (sync_type == 3) {
        condition = 0;
        pthread_cond_signal(&cond);
        //pthread_mutex_unlock(&mutex);
    }
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_testcancel();
}

void dangerous_function(void* arg) {
    int add = *(int*)arg;
    for(int i = 0; i<10; i++) {
        number+=add;
        printf("thread report number: %d\n", number);
    }
}