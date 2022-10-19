#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define NTHREADS 2

static void *
worker(void *arg)
{
	printf("Thread %ld\n", (intptr_t)arg);

	return NULL;
}

int main()
{
	pthread_t th[NTHREADS];

	for (int i = 0; i < NTHREADS; i++)
		pthread_create(&th[i], NULL, worker, (void *)(intptr_t)i);

	for (int i = 0; i < NTHREADS; i++)
		pthread_join(th[i], NULL);

	return 0;
}
