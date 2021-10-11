#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// schimbare nr de thread-uri
#define NUM_THREADS 3

void *f(void *arg) {

  	long id = *(long*) arg;
	
	// Afisarea repetitiva de 100 de ori a msg ului
    for (int i = 0; i <= 100; i++) {
        printf("Hello World din thread-ul %ld!  %d\n", id, i);
    }
  	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

	pthread_t threads[NUM_THREADS];
  	int r;
  	long id;
  	void *status;
  	
	// nr de core uri
    long cores = sysconf(_SC_NPROCESSORS_CONF);
    long arguments[cores];

    printf("Num of threads = %ld \n", cores);

  	for (id = 0; id < cores; id++) {

  		arguments[id] = id;
		r = pthread_create(&threads[id], NULL, f, &arguments[id]);

		if (r) {
	  		printf("Eroare la crearea thread-ului %ld\n", id);
	  		exit(-1);
		}
  	}

  	for (id = 0; id < cores; id++) {
		r = pthread_join(threads[id], &status);

		if (r) {
	  		printf("Eroare la asteptarea thread-ului %ld\n", id);
	  		exit(-1);
		}
  	}

  	pthread_exit(NULL);
}
