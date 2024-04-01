#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex_sprawdz;
pthread_mutex_t mutex_suma;

int N;              /* liczba liczb pierwszych do znalezienia (arg.wywolania) */
int sprawdz = 2;    /* nastepna liczba do sprawdzania */
int znalezione = 0; /* liczba znalezionych i zsumowanych l.pierwszych */
long suma = 0;      /* to bedzie obliczona suma liczb pierwszych */

int l_pierwsza(int liczba)
{
    for (int i = 2; i * i <= liczba; i++)
    {
        if (liczba % i == 0 && i != liczba)
        {
            return 0; // liczba dzieli się przez coś innego niż 1 i ona sama
        }
    }
    return 1; // liczba jest liczbą pierwszą
}

void *watek_wypisanie(void *arg)
{
    while (znalezione < N)
    {
        int lokalna_sprawdz;

        pthread_mutex_lock(&mutex_sprawdz);
        lokalna_sprawdz = sprawdz;
        sprawdz++;
        pthread_mutex_unlock(&mutex_sprawdz);

        if (l_pierwsza(lokalna_sprawdz))
        {
            pthread_mutex_lock(&mutex_suma);
            if (znalezione >= N)
            {
                pthread_mutex_unlock(&mutex_suma);
                break;
            }
            suma += lokalna_sprawdz;
            znalezione++;
            pthread_mutex_unlock(&mutex_suma);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int l_watkow = 0;
    if (argc != 3)
    {
        printf("Użycie zbyt malej liczby argumentow przy wywolaniu.\n");
        return 1;
    }

    N = atoi(argv[1]);        // Pobranie liczby N jako argumentu wywołania programu
    l_watkow = atoi(argv[2]); // Pobranie liczby wątków
    pthread_t th[l_watkow];

    if (N <= 0)
    {
        printf("N musi być liczbą dodatnią\n");
        return 1;
    }

    pthread_mutex_init(&mutex_sprawdz, NULL);
    pthread_mutex_init(&mutex_suma, NULL);

    for (int i = 0; i < l_watkow; i++)
    {
        printf("Utworzenie watku %d\n", i);
        if (pthread_create(&th[i], NULL, &watek_wypisanie, NULL) != 0)
        {
            printf("Blad: pthread_create\n");
        }
    }

    for (int i = 0; i < l_watkow; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            printf("Blad: pthread_join\n");
        }
    }

    printf("Suma = %ld\n", suma);
    printf("Zalezione = %d\n", znalezione);

    pthread_mutex_destroy(&mutex_sprawdz);
    pthread_mutex_destroy(&mutex_suma);

    return 0;
}