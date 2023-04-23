#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_threads;
int max_num;

int sum = 0;
pthread_mutex_t mutex;

void *calculate_sum(void *thread_id_pointer) {
    int i;
    int thread_id = (*(int*)thread_id_pointer);
    int local_sum = 0;

    int start = thread_id * (max_num / num_threads) + 1;
    int end = (thread_id + 1) * (max_num / num_threads);
    for (i = start; i <= end; i++) {
        local_sum += i;
    }

    pthread_mutex_lock(&mutex);
    sum += local_sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    printf("Please enter the num_threads: ");
    scanf("%d", &num_threads);
    printf("Please enter the max_num: ");
    scanf("%d", &max_num);

    pthread_t threads[num_threads];
    int thread_ids[num_threads];
    int i;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_sum, (void*) &thread_ids[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("1 + 2 + ...... + %d = %d\n", max_num, sum);

    pthread_mutex_destroy(&mutex);

    return 0;
}