#include <stdlib.h>

#include <stdio.h>

#define __USE_GNU

#include <sched.h>

#include <pthread.h>

#include <semaphore.h>

sem_t begin_sem1;

sem_t begin_sem2;

sem_t end_sem;

int x, y, r1, r2;

void func1(void *arg)

{

    printf("thread1 running\n");

    while (1)

    {

        sem_wait(&begin_sem1);

        y = 1;

        asm volatile("dmb ish" ::
                         : "memory");

        r1 = x;

        sem_post(&end_sem);
    }
}

void func2(void *arg)

{

    printf("pthread2 running\n");

    while (1)

    {

        sem_wait(&begin_sem2);

        x = 2;

        asm volatile("dmb ish" ::
                         : "memory");

        r2 = y;

        sem_post(&end_sem);
    }
}

int main()

{

    pthread_t thread_id[2];

    cpu_set_t mask;

    r1 = 0;

    r2 = 0;

    sem_init(&begin_sem1, 0, 0);

    sem_init(&begin_sem2, 0, 0);

    sem_init(&end_sem, 0, 0);

    CPU_ZERO(&mask);

    CPU_SET(0, &mask);

    if (pthread_setaffinity_np(pthread_self(), sizeof(mask), &mask) < 0)

    {

        printf("pthread_setaffinity_np() err!\n");

        return -1;
    }

    pthread_create(&thread_id[0], NULL, (void *)func1, NULL);

    pthread_create(&thread_id[1], NULL, (void *)func2, NULL);

    CPU_ZERO(&mask);

    CPU_SET(1, &mask);

    if (pthread_setaffinity_np(thread_id[0], sizeof(mask), &mask) < 0)

    {

        printf("pthread_setaffinity_np() err!\n");

        return -1;
    }

    CPU_ZERO(&mask);

    CPU_SET(2, &mask);

    if (pthread_setaffinity_np(thread_id[1], sizeof(mask), &mask) < 0)

    {

        printf("pthread_setaffinity_np() err!\n");

        return -1;
    }

    long itimes = 0;

    long cycles = 0;

    while (1)

    {

        x = 0;

        y = 0;

        sem_post(&begin_sem1);

        sem_post(&begin_sem2);

        sem_wait(&end_sem);

        sem_wait(&end_sem);

        if (0 == r1 && 0 == r2)

        {

            printf("vmm cache sync catched afer %ld times!\n", itimes);

            itimes = 0;

            // exit(-1);
        }

        itimes++;

        cycles++;

        if (0 == cycles % 100000)

            printf("========> After %ld cycles ...\n", cycles);
    }

    return 0;
}