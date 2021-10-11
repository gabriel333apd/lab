#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 2

void *f(void *arg) {
      long id = *(long*) arg;
    for (int i = 0; i <= 100; i++) {
        printf("Hello World din thread-ul %ld!  %d\n", id, i);
    }
      
      pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    long cores = 2;
    pthread_t threads[cores];
      int r;
      long id;
      void *status;
      
    
    long arguments[cores];
    printf("Num of threads = %ld \n", cores);
        arguments[0] = 0;
        r = pthread_create(&threads[0], NULL, f, &arguments[0]);

        if (r) {
              printf("Eroare la crearea thread-ului %d\n", 0);
              exit(-1);
        }
      
        r = pthread_join(threads[0], &status);

        if (r) {
              printf("Eroare la asteptarea thread-ului %d\n", 0);
              exit(-1);
        }
      
      arguments[1] = 1;
      r = pthread_create(&threads[1], NULL, f, &arguments[1]);

      if (r) {
            printf("Eroare la crearea thread-ului %d\n", 1);
            exit(-1);
      }
    
      r = pthread_join(threads[1], &status);

      if (r) {
            printf("Eroare la asteptarea thread-ului %d\n", 1);
            exit(-1);
      }
    

      pthread_exit(NULL);
}

