#include <stdio.h>
#include <stdlib.h>
#include "Prototypy.h"

int main()
{
    int wybor = -1;
    printf("--- program do tworzenia planu treningowego --- \n\n");

    while (wybor != 0)
    {
        printf("MENU PROGRAMU: \n");
        printf("  0. Wyjdz z programu.\n");
        printf("  1. Stworz wlasny plan treningowy.\n");
        printf("  2. Stworz plan treningowy dedykowany do progresji okreslonego cwiczenia.\n");
        printf("  3. Wybierz plan treningowy rehabilitacyjny.\n");
        printf("  4. Wybierz gotowy plan treningowy z gotowej bazy.\n\n");
        printf("Wybierz numer z menu:  ");
        scanf("%d", &wybor);
        printf("\n\n");

        switch (wybor)
        {
        case 1:
            customowy_plan();
            break;
        case 2:
            Progresja();
            break;
        case 3:
            Rehabilitacja();
            break;
        case 4:
            gotowy_plan();
            break;
        case 0:
            printf("KONIEC PROGRAMU");
            break;
        default:
            printf("Podano zly numer");
            break;
        }

        printf("\n\n");
    }

    system("PAUSE");
    return 0;
}
