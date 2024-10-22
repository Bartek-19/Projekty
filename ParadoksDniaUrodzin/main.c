#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 365, k, i, j;
    double p;

    printf("> Paradoks dnia urodzin\n Paradoks ten przedstawia jakie jest prawdopodobienstwo,\n");
    printf(" ze kazda z k osob bedzie miala urodziny innego dnia niz pozostali\n\n");
    do {
        printf("Podaj dla jakiego k chcesz wyswietlic tabele prawdopodobienstwa:  ");
        scanf("%d", &k);
    }while(k<=1 || k>365);

    printf("\n");

    for(i=1; i<=k; i++)
    {
        p = 1;
        for(j=2; j<=i; j++)
        {
            p *= 1-(j-1)/(n*1.0);
        }
        printf("%4d | %1.8f \n", i, p);
    }

    printf("\n");
    system("PAUSE");
    return 0;
}
