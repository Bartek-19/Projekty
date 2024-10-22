#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tCwiczenie {
    char nazwa[50];
    char serie[4];
    char powtorzenia[10];
    int intensywnosc;
};

struct tCwiczenie zapis()
{
    struct tCwiczenie A;
    fflush(stdin);
    printf("Podaj nazwe cwiczenia: ");
    gets(A.nazwa);
    fflush(stdin);
    printf("Podaj ilosc serii: ");
    gets(A.serie);
    fflush(stdin);
    printf("Podaj ilosc powtorzen: ");
    gets(A.powtorzenia);
    fflush(stdin);
    printf("Podaj intensywnosc cwiczenia (RPE 1-10): ");
    scanf("%d", &A.intensywnosc);

    return A;
}

void planJednaSesja(FILE *plik, int n)
{
    char dzien[13];
    int i, dodaj = -1;
    struct tCwiczenie CW;
    char naglowek1[50], naglowek2[12], naglowek3[10];
    strcpy(naglowek1, "Nazwa cwiczenia:");
    strcpy(naglowek2, "Ser./Powt.:");
    strcpy(naglowek3, "RPE:");

    fprintf(plik, "Customowy plan treningowy.\n\n");

    for (i=1; i<=n; i++)
    {
        printf("%d. dzien treningowy.\n", i);
        printf("Podaj nazwe dnia tygodnia: ");
        fflush(stdin);
        scanf("%s", dzien);
        fprintf(plik, "%s\n", dzien);
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s", naglowek2);
        fprintf(plik, "%10s\n", naglowek3);
        CW = zapis();
        fprintf(plik, "%-50s", CW.nazwa);
        fprintf(plik, "%4s", CW.serie);
        fprintf(plik, "/");
        fprintf(plik, "%-15s", CW.powtorzenia);
        fprintf(plik, "%d\n", CW.intensywnosc);

        while (dodaj != 0)
            {
                printf("Czy chcesz dodac jesze jedno cwiczenie do tego dnia?\n0.NIE\n1.TAK\n");
                scanf("%d", &dodaj);
                if (dodaj == 1)
                {
                    CW = zapis();
                    fprintf(plik, "%-50s", CW.nazwa);
                    fprintf(plik, "%4s", CW.serie);
                    fprintf(plik, "/");
                    fprintf(plik, "%-15s", CW.powtorzenia);
                    fprintf(plik, "%d\n", CW.intensywnosc);
                }
                if (dodaj == 0)
                    continue;
                if (dodaj != 0 && dodaj != 1)
                    printf("Zly wybor.\n");
            }
        dodaj = -1;
        fprintf(plik, "\n\n");

        printf("\n\n");
    }

    printf("\n\n");
}

void planDwieSesje(FILE *plik, int n)
{
    char dzien[13];
    int i, dodaj = -1;
    struct tCwiczenie CW;
    char naglowek1[50], naglowek2[12], naglowek3[10];
    strcpy(naglowek1, "Nazwa cwiczenia:");
    strcpy(naglowek2, "Ser./Powt.:");
    strcpy(naglowek3, "RPE:");

    fprintf(plik, "Customowy plan treningowy.\n\n");

    for (i=1; i<=n; i++)
    {
        printf("%d. dzien treningowy.\n", i);
        printf("Podaj nazwe dnia tygodnia: ");
        fflush(stdin);
        scanf("%s", dzien);
        fprintf(plik, "%s\n", dzien);

        printf("RANO: \n");
        fprintf(plik, "Rano:\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s", naglowek2);
        fprintf(plik, "%10s\n", naglowek3);
        CW = zapis();
        fprintf(plik, "%-50s", CW.nazwa);
        fprintf(plik, "%4s", CW.serie);
        fprintf(plik, "/");
        fprintf(plik, "%-15s", CW.powtorzenia);
        fprintf(plik, "%d\n", CW.intensywnosc);
        while (dodaj != 0)
        {
            printf("Czy chcesz dodac jesze jedno cwiczenie do porannej sesji treningowej?\n0.NIE\n1.TAK\n");
            scanf("%d", &dodaj);
            if (dodaj == 1)
            {
                CW = zapis();
                fprintf(plik, "%-50s", CW.nazwa);
                fprintf(plik, "%4s", CW.serie);
                fprintf(plik, "/");
                fprintf(plik, "%-15s", CW.powtorzenia);
                fprintf(plik, "%d\n", CW.intensywnosc);
            }
            if (dodaj == 0)
                continue;
            else
                printf("Zly wybor.\n");
        }
        dodaj = -1;

        printf("\nWIECZOR: \n");
        fprintf(plik, "\nWieczor:\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s", naglowek2);
        fprintf(plik, "%10s\n", naglowek3);
        CW = zapis();
        fprintf(plik, "%-50s", CW.nazwa);
        fprintf(plik, "%4s", CW.serie);
        fprintf(plik, "/");
        fprintf(plik, "%-15s", CW.powtorzenia);
        fprintf(plik, "%d\n", CW.intensywnosc);
        while (dodaj != 0)
        {
            printf("Czy chcesz dodac jesze jedno cwiczenie do wieczornej sesji treningowej?\n0.NIE\n1.TAK\n");
            scanf("%d", &dodaj);
            if (dodaj == 1)
            {
                CW = zapis();
                fprintf(plik, "%-50s", CW.nazwa);
                fprintf(plik, "%4s", CW.serie);
                fprintf(plik, "/");
                fprintf(plik, "%-15s", CW.powtorzenia);
                fprintf(plik, "%d\n", CW.intensywnosc);
            }
            if (dodaj == 0)
                continue;
            else
                printf("Zly wybor.\n");
        }
        dodaj = -1;
        fprintf(plik, "\n");

        printf("\n\n");
    }

    printf("\n\n");
}
//----------

void customowy_plan()
{
    FILE *plik;
    int iledni, ilesesji;

    plik = fopen(". Custom.txt", "w");

    if ((plik = fopen(". Custom.txt", "w"))==NULL)
    {
        printf("Blad programu");
        system("PAUSE");
        abort();
    }

    printf("Tworzenie customowego planu treningowego.\n\n");

    while (iledni < 0 || iledni > 7)
    {
        printf("Podaj ile dni w tygodniu chcesz wykonywac treningi: ");
        scanf("%d", &iledni);
        if (iledni < 0 || iledni > 7)
            printf("Podano zla ilosc dni. Podaj jeszcze raz.\n");
    }

    while (ilesesji!=1 && ilesesji!=2)
    {
        printf("Podaj ile sesji treningowych chcesz wykonywac w ciagu dnia: \n1.Jedna \n2.Dwie \n");
        scanf("%d", &ilesesji);
        if (ilesesji!=1 && ilesesji!=2)
            printf("Podano zly numer, wybierz jeszcze raz.\n");
    }

    if (ilesesji == 1)
        {
            planJednaSesja(plik, iledni);
            printf("\nZakonczono tworzenie planu.\n\n");
        }
    if (ilesesji == 2)
        {
            planDwieSesje(plik, iledni);
            printf("\nZakonczono tworzenie planu.\n\n");
        }

    fclose(plik);
}
