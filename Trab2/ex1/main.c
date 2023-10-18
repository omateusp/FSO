#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int tam;
int cmpfunc(const void *a, const void *b);
void *sort(void *param);
int main(int argc, char *argv[])
{
    int i, j;
    pthread_t tid[2];
    scanf("%d", &tam);
    int vector[2][tam];
    for (i = 0; i < 2; i++)
        for (j = 0; j < tam; j++)
            scanf("%d", &vector[i][j]);

    /* create the thread */
    for (i = 0; i < 2; i++)
        pthread_create(&tid[i], NULL, sort, &vector[i]);
    /* wait for the thread to exit */
    for (i = 0; i < 2; i++)
        pthread_join(tid[i], NULL);

    for (j = 0; j < tam; j++)
        if (vector[0][j] != vector[1][j])
        {
            printf("Diferentes\n");
            return 0;
        }

    printf("Mesmos elementos\n");
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void *sort(void *param)
{
    qsort(param, tam, sizeof(int), cmpfunc);
    pthread_exit(0);
}