// Preguiçoso até demais…
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
int i = 0;
static void sig_handler(int signum)
{
    if (signum == 10)
    {
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }
    else if (signum == 14 && i < 2)
    {
        i++;
        printf("Ai que sono, quero dormir mais um pouco\n");
    }
    else if (signum == 14 && i >= 2)
    {
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    }
}

int main()
{
    signal(SIGUSR1, sig_handler);
    signal(SIGALRM, sig_handler);

    while (1)
    {
        sleep(1);
    }
    return 0;
}