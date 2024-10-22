#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double zaokraglenie(double ciezar)
{
    int wynik = ciezar*10;

    if(wynik%25 < 12.5)
        wynik -= wynik%25;
    else
        wynik += 25 - wynik%25;

    return ((double)wynik/10.0);
}

int main()
{
    float x, NowyRekord;
    int i;
    double ciezar1, ciezar2, ciezar3, ciezar4, ciezar5;
    i = 0;

    printf("\n\t\t<<<PROJEKT SILOWNIA>>>\n\n"
    "Metoda tutaj zastosowana opiera sie na cyklach czterotygodniowych,\n"
    "podczas ktorych bedziemy zwiekszac obciazenie treningowe, az do uzyskania \n"
    "oczekiwanego wyniku w danym cwiczeniu. Ta metoda treningowa uwzglednia \n"
    "trzy treningi w tygodniu. Dodatkowo w czwartym tygodniu kazdego cyklu ostatni \n"
    "trening przeznaczony jest na ustanowienie nowego osobistego rekordu w danym cwiczeniu.\n"
    "Pomiedzy kazdym cyklem czterotygodniowym nalezy dokonac tygodniowej przerwy.\n\n");

    printf("Podaj swoj obecny rekord:  ");
    scanf("%f", &NowyRekord);

    printf("\n");

    printf("Podaj swoj oczekiwany rekord:  ");
    scanf("%f", &x);

    printf("\n\n");

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

            printf("Tydzien drugi: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar2);
            printf("5 serii po 5 powtorzen.\n\n");

            printf("Tydzien trzeci: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar3);
            printf("5 serii po 3 powtorzenia.\n\n");

            printf("Tydzien czwarty: \n");
            printf("Ciezar roboczy:  %3.1f , ", ciezar4);
            printf("5 serii po 1 powtorzenie.\n");
            printf("W ostatnim treningu tego tygodnia staramy sie pobic nowy rekord \n");
            printf("czyli uzyskac %3.1f kilogramow\n\n", ciezar5);

            NowyRekord = ciezar5;

            i++;

            printf(" |\n |\n |\n\n");
        }

    printf("\n\nWynik %.2f kilogramow powinienes uzyskac po %d cyklach, \n", x, i);
    printf("czyli po %d tygodniach. \n", 5*i-1);

    printf("\n\t ADNOTACJA: \n");
    printf("Wynik koncowy ostatniego cyklu moze byc mniejszy od oczekiwanego rekordu.\n");
    printf("Jesli zalezy ci na uzyskaniu oczekiwanego wyniku, mozesz sprobowac wykonac\n"
           "jeszcze jeden cykl treningowy, gdzie w pierwszym tygodniu ciezar roboczy\n"
           "wynosi 80% twojego nowego rekordu, w drugim tygodniu 90%, w trzecim\n"
           "100% twojego nowego rekordu, a w czwartym starasz sie uzyskac oczekiwany rekord.\n"
           "Druga opcja to proba uzyskania swojego oczekiwanego rekordu w ostatnim treningu\n"
           "ostatniego cyklu treningowego.\n\n");

    system("PAUSE");
    return 0;
}
