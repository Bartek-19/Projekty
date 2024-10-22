#include <stdio.h>
#include <stdlib.h>

double zaokraglenie(double wynik)
{
    int ciezar = wynik * 10;

    if(ciezar%25 < 12.5)
        ciezar -= ciezar%25;
    else
        ciezar += 25 - ciezar%25;

    wynik = ciezar/10.0;

    return wynik;
}

int main()
{
    int i=1, rekord;
    double ciezar1, ciezar2;

    printf("Podaj ciezar roboczy do metody 5/5:  ");
    scanf("%lf", &ciezar1);
    printf("Podaj swoj oczekiwany rekord:  ");
    scanf("%d", &rekord);

    printf("\n\n");

    ciezar2 = zaokraglenie(ciezar1 * 1.125);

    printf("Tydzien %2d: %6.1f kg    5/5\n", i++, ciezar1);

    while(ciezar2*1.111 <= rekord){

        printf("Tydzien %2d: %6.1f kg    3/3\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    4/3\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    5/3\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    3/4\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    4/4\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    5/4\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    3/5\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    4/5\n", i++, ciezar2);
        printf("Tydzien %2d: %6.1f kg    5/5\n", i++, ciezar2);

        ciezar1 = ciezar2;
        ciezar2 = zaokraglenie(ciezar1 * 1.125);

        //if(ciezar1 >= ciezar2)
          //  ciezar2+=5;
    }

    printf("\n\n");

    system("PAUSE");
    return 0;
}
