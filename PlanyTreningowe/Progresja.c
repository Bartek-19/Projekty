#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double zaokraglenie(double ciezar)
{
    int wynik = ciezar * 10;

    if(wynik%25 < 12.5)
        wynik -= wynik%25;
    else
        wynik += 25 - wynik%25;

    return (double)(wynik/10.0);
}

void zapis_progresji(FILE *plik, int n)
{
    float x, NowyRekord;
    int i = 0, j = 1;
    double ciezar1, ciezar2, ciezar3, ciezar4, ciezar5;
    char naglowek1[50], naglowek2[12], naglowek3[10];
    strcpy(naglowek1, "Nazwa cwiczenia:");
    strcpy(naglowek2, "Ser./Powt.:");
    strcpy(naglowek3, "RPE:");

    printf("Podaj swoj obecny rekord:  ");
    scanf("%f", &NowyRekord);

    printf("\n");

    printf("Podaj swoj oczekiwany rekord:  ");
    scanf("%f", &x);

    printf("\n\n");

    switch(n)
    {
    case 1:
        fprintf(plik, "\t >WYCISKANIE NA LAWCE<\n\n");
        fprintf(plik, "Dzien 1:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "WYCISKANIE NA LAWCE*\n");
        fprintf(plik, "%-50s", "Martwy ciag"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie z podporek asekuracyjnych"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/5-8"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie na lawce skosnej"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Prostowanie hantla nad glowa"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 2:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "WYCISKANIE NA LAWCE*\n");
        fprintf(plik, "%-50s", "Przysiad"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie z ziemi lezac"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/6-10"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie JM-Press/Wyciskanie waskie"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie francuskie lezac"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 3:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "WYCISKANIE NA LAWCE*\n");
        fprintf(plik, "%-50s", "Wyciskanie nad glowe"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Pompki na poreczach"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Rozpietki"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/15-20"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Wyciskanie francuskie stojac"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "\n");
        break;
    case 2:
        fprintf(plik, "\t >WYCISKANIE NAD GLOWE<\n\n");
        fprintf(plik, "Dzien 1:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "WYCISKANIE NAD GLOWE*\n");
        fprintf(plik, "%-50s", "Martwy ciag"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Push-press"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/5-8"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie siedzac z podporek asekuracyjnych"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/5-8"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Prostowanie hantla nad glowa (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 2:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "WYCISKANIE NAD GLOWE*\n");
        fprintf(plik, "%-50s", "Przysiad"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Pompki na poreczach"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Shrugsy kapturami"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/12-16"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie francuskie lezac"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/12-16"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 3:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "WYCISKANIE NAD GLOWE*\n");
        fprintf(plik, "%-50s", "Wyciskanie na lawce"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Pompki glowa w dol"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wyciskanie francuskie stojac"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Wznosy boczne"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        break;
    case 3:
        fprintf(plik, "\t >MARTWY CIAG<\n\n");
        fprintf(plik, "Dzien 1:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "MARTWY CIAG*\n");
        fprintf(plik, "%-50s", "Rwanie"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/3-6"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Martwy ciag z podwyzszenia"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/5-8"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Martwy ciag rumunski"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/12-16"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 2:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "MARTWY CIAG*\n");
        fprintf(plik, "%-50s", "Przysiad"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Martwy ciag z obnizenia"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Odgiecia na lawce rzymskiej"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Podnoszenie ciezaru posladkami (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 3:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "MARTWY CIAG*\n");
        fprintf(plik, "%-50s", "Wyciskanie na lawce"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Martwy ciag rumunski sprinterski (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wymahy Kettelbell"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Uginanie nog (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/15-20"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        break;
    case 4:
        fprintf(plik, "\t >PRZYSIAD<\n\n");
        fprintf(plik, "Dzien 1:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "PRZYSIAD*\n");
        fprintf(plik, "%-50s", "Przysiad z wyskokiem"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/5-8"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Przysiad ze sztanga z przodu"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Wykroki (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 2:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "PRZYSIAD*\n");
        fprintf(plik, "%-50s", "Martwy ciag"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Przysiad ze stojakow asekuracyjnych"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/5-8"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Przysiad stepper (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "%-50s", "Przysiad bulgarski plajometryczny (L/P)"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "\n");
        fprintf(plik, "Dzien 3:\n");
        fprintf(plik, "%-50s", naglowek1); fprintf(plik, "%-12s", naglowek2); fprintf(plik, "%10s\n", naglowek3);
        fprintf(plik, "PRZYSIAD*\n");
        fprintf(plik, "%-50s", "Wyciskanie na lawce"); fprintf(plik, "%4s", "5"); fprintf(plik, "%-12s", "/5"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Przysiad z pauza"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Przysiad bulgarski"); fprintf(plik, "%4s", "2*3"); fprintf(plik, "%-12s", "/8-12"); fprintf(plik, "%d\n", 8);
        fprintf(plik, "%-50s", "Przysiad goblet"); fprintf(plik, "%4s", "3"); fprintf(plik, "%-12s", "/10-15"); fprintf(plik, "%d\n", 7);
        fprintf(plik, "\n");
        break;
    default:
        printf("ERROR\nCos poszlo nie tak.");
        break;
    }

    printf("\n\n");
    fprintf(plik, "\n* Plan ciezaru dla wybranego cwiczenia:\n");

    while(NowyRekord*1.05 <= x)
        {
            printf("CYKL NUMER %d:  \n\n", i+1);

            ciezar1 = zaokraglenie(NowyRekord * 0.8);
            ciezar2 = zaokraglenie(NowyRekord * 0.9);
            ciezar3 = zaokraglenie(NowyRekord);
            ciezar4 = zaokraglenie(NowyRekord * 1.05);
            ciezar5 = zaokraglenie(NowyRekord * 1.1);


            printf("Tydzien pierwszy: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar1);
            printf("5 serii po 8-10 powtorzen.\n\n");
            fprintf(plik, "Tydzien %d: %3.1f kg    5/8-10 \n", j, ciezar1);
            j++;

            printf("Tydzien drugi: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar2);
            printf("5 serii po 5 powtorzen.\n\n");
            fprintf(plik, "Tydzien %d: %3.1f kg    5/5 \n", j, ciezar2);
            j++;

            printf("Tydzien trzeci: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar3);
            printf("5 serii po 3 powtorzenia.\n\n");
            fprintf(plik, "Tydzien %d: %3.1f kg    5/3 \n", j, ciezar3);
            j++;

            printf("Tydzien czwarty: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar4);
            printf("5 serii po 1 powtorzenie.\n");
            printf("W ostatnim treningu tego tygodnia staramy sie pobic nowy rekord \n");
            printf("czyli uzyskac %3.1f kilogramow\n\n", ciezar5);
            fprintf(plik, "Tydzien %d: %3.1f kg    5/1 \n", j, ciezar4);
            fprintf(plik, "Tydzien %d trening nr.3: %3.1f kg\n", j, ciezar5);
            j++;

            fprintf(plik, "Tydzien %d: -PRZERWA-\n", j);
            j++;

            NowyRekord = ciezar5;

            i++;

            printf(" |\n |\n |\n\n");
        }

    printf("\n\nWynik %.2f kilogramow powinienes uzyskac po %d cyklach, \n", x, i);
    printf("czyli po %d tygodniach. \n\n", 5*i-1);
    fprintf(plik, "\nPlanowany czas osiagniecia rekordu: %d tygodni.\n\n", j-2);
}

void Progresja()
{
    FILE *plik;
    int cwiczenie = -1;

    plik = fopen(". Progresja.txt", "w");

    if ((plik=fopen(". Progresja.txt", "w"))==NULL)
    {
        printf("Blad programu");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy progresyjny\n\n");
    fprintf(plik, "ADNOTACJA 1\n");
    fprintf(plik, "Podany plan treningowy jest planem typowo silowym,\n");
    fprintf(plik, "dlatego skupia sie on na poprawie jednego cwiczenia\n");
    fprintf(plik, "z jednoczesnym utrzymywaniem sily pozostalych cwiczen\n");
    fprintf(plik, "silowych, czyli wykonywanie ich metoda 5 na 5.\n");
    fprintf(plik, "Podany plan treningowy uwzglednia 3 treningi w tygodniu.\n\n");

    printf("--- Plan treningowy progresywny ---\n\n");
    printf("1. Wyciskanie na lawce \n2. Wyciskanie nad glowe \n3. Martwy ciag \n4. Przysiad \n");
    while (cwiczenie < 1 || cwiczenie > 4)
    {
        printf("Wybierz cwiczenie: ");
        scanf("%d", &cwiczenie);
    }

    printf("\n");

    zapis_progresji(plik, cwiczenie);

    fprintf(plik, "ADNOTACJA 2\n");
    fprintf(plik, "Ze wzgledu na obliczenia procentowe programu nalezy\n");
    fprintf(plik, "podane ponizej wyniki zaokraglic do pieciu.\n");
    fprintf(plik, "Nalezy rowniez wziac pod uwage, ze ludzki organizm\n");
    fprintf(plik, "posiada naturalne ograniczenia, dlatego nalezy rozsadnie\n");
    fprintf(plik, "podchodzic do kwesti oczekiwanego przez nas rekordu.\n\n");

    printf("Zapisuje plik...\n");

    fclose(plik);

    printf("\nZapisano.\n\n");
}
