#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tRehab {
    char nazwa[50];
    char serie[4];
    char powtorzenia[10];
};

void Baza(FILE *plik, int wybor)
{
    int i;

    char naglowek1[50], naglowek2[12];
    strcpy(naglowek1, "Nazwa cwiczenia:");
    strcpy(naglowek2, "Ser./Powt.:");

    struct tRehab kostki[3];
    strcpy(kostki[0].nazwa, "Rozciaganie stawu z guma na kostce (L/P)");
    strcpy(kostki[0].serie, "2*3");
    strcpy(kostki[0].powtorzenia, "10*5s");
    strcpy(kostki[1].nazwa, "Rozciaganie stawu w pozycji przysiadu (L/P)");
    strcpy(kostki[1].serie, "2*3");
    strcpy(kostki[1].powtorzenia, "5*10s");
    strcpy(kostki[2].nazwa, "Rozciaganie stawu z ciezarem na kolanie (L/P)");
    strcpy(kostki[2].serie, "2*3");
    strcpy(kostki[2].powtorzenia, "10*5s");

    struct tRehab kolana[4];
    strcpy(kolana[0].nazwa, "Prostowanie kolan z oporem gumy");
    strcpy(kolana[0].serie, "3");
    strcpy(kolana[0].powtorzenia, "20");
    strcpy(kolana[1].nazwa, "Przysiad na jednej nodze (L/P)");
    strcpy(kolana[1].serie, "2*3");
    strcpy(kolana[1].powtorzenia, "10");
    strcpy(kolana[2].nazwa, "Wykroki ATG (L/P)");
    strcpy(kolana[2].serie, "2*3");
    strcpy(kolana[2].powtorzenia, "10");
    strcpy(kolana[3].nazwa, "Uginanie nog");
    strcpy(kolana[3].serie, "3");
    strcpy(kolana[3].powtorzenia, "20");

    struct tRehab biodra[7];
    strcpy(biodra[0].nazwa, "Przysiad kozacki (L/P)");
    strcpy(biodra[0].serie, "2*3");
    strcpy(biodra[0].powtorzenia, "10");
    strcpy(biodra[1].nazwa, "Dociazanie biodra w pozycji otwartej (L/P)");
    strcpy(biodra[1].serie, "2*3");
    strcpy(biodra[1].powtorzenia, "5*5s");
    strcpy(biodra[2].nazwa, "Obroty nogi na czworaka (L/P)");
    strcpy(biodra[2].serie, "2*3");
    strcpy(biodra[2].powtorzenia, "10");
    strcpy(biodra[3].nazwa, "Napinanie i rozluznianie biodra z guma (L/P)");
    strcpy(biodra[3].serie, "2*3");
    strcpy(biodra[3].powtorzenia, "5");
    strcpy(biodra[4].nazwa, "Jaskolki rotacyjne (L/P)");
    strcpy(biodra[4].serie, "2*3");
    strcpy(biodra[4].powtorzenia, "5");
    strcpy(biodra[5].nazwa, "Podciagniecia pachwinami (L/P)");
    strcpy(biodra[5].serie, "2*3");
    strcpy(biodra[5].powtorzenia, "10");
    strcpy(biodra[6].nazwa, "Otwieranie bioder z mini-bandem na udach (L/P)");
    strcpy(biodra[6].serie, "2*3");
    strcpy(biodra[6].powtorzenia, "10");

    struct tRehab plecy[7];
    strcpy(plecy[0].nazwa, "Wyginanie i prostowanie kregoslupa na czworaka");
    strcpy(plecy[0].serie, "3");
    strcpy(plecy[0].powtorzenia, "10");
    strcpy(plecy[1].nazwa, "Przejscia koci grzbiet ---> foczka");
    strcpy(plecy[1].serie, "3");
    strcpy(plecy[1].powtorzenia, "10");
    strcpy(plecy[2].nazwa, "Martwy ciag rumunski z pauza na dole (5s.)");
    strcpy(plecy[2].serie, "3");
    strcpy(plecy[2].powtorzenia, "10");
    strcpy(plecy[3].nazwa, "Martwy ciag Bala");
    strcpy(plecy[3].serie, "3");
    strcpy(plecy[3].powtorzenia, "10");
    strcpy(plecy[4].nazwa, "Deska boczna");
    strcpy(plecy[4].serie, "3");
    strcpy(plecy[4].powtorzenia, "2*15s");
    strcpy(plecy[5].nazwa, "Supermen (L/P)");
    strcpy(plecy[5].serie, "2*3");
    strcpy(plecy[5].powtorzenia, "5*5s");
    strcpy(plecy[6].nazwa, "Antyrotacje z guma lub z ciezarem (L/P)");
    strcpy(plecy[6].serie, "2*3");
    strcpy(plecy[6].powtorzenia, "10");

    struct tRehab barki[7];
    strcpy(barki[0].nazwa, "Dyslokatki");
    strcpy(barki[0].serie, "3");
    strcpy(barki[0].powtorzenia, "10");
    strcpy(barki[1].nazwa, "Wyciskanie pod sciana");
    strcpy(barki[1].serie, "3");
    strcpy(barki[1].powtorzenia, "10");
    strcpy(barki[2].nazwa, "Wyciskanie 'W'");
    strcpy(barki[2].serie, "3");
    strcpy(barki[2].powtorzenia, "5");
    strcpy(barki[3].nazwa, "'A'+'T'+'Y'");
    strcpy(barki[3].serie, "3");
    strcpy(barki[3].powtorzenia, "5*3*3s");
    strcpy(barki[4].nazwa, "Zabki");
    strcpy(barki[4].serie, "3");
    strcpy(barki[4].powtorzenia, "5");
    strcpy(barki[5].nazwa, "Wyciskanie nad glowe z przednim oporem (L/P)");
    strcpy(barki[5].serie, "2*3");
    strcpy(barki[5].powtorzenia, "5");
    strcpy(barki[6].nazwa, "Rotacje zewnetrzne + wewnetrzne (L/P)");
    strcpy(barki[6].serie, "2*3");
    strcpy(barki[6].powtorzenia, "10");

    struct tRehab lokcie[6];
    strcpy(lokcie[0].nazwa, "Rozciaganie tricepsa za glowa (L/P)");
    strcpy(lokcie[0].serie, "2*3");
    strcpy(lokcie[0].powtorzenia, "20s");
    strcpy(lokcie[1].nazwa, "Rozciaganie bicepsa z rekami z przodu");
    strcpy(lokcie[1].serie, "3");
    strcpy(lokcie[1].powtorzenia, "20s");
    strcpy(lokcie[2].nazwa, "Prostowanie lokcia nad glowa z 5s pauza (L/P)");
    strcpy(lokcie[2].serie, "2*3");
    strcpy(lokcie[2].powtorzenia, "10");
    strcpy(lokcie[3].nazwa, "Izometryczne ugiecia lokci - 'Homer'");
    strcpy(lokcie[3].serie, "3");
    strcpy(lokcie[3].powtorzenia, "20s");
    strcpy(lokcie[4].nazwa, "Rotacja wew. + zew. nadgarstkiem (L/P)");
    strcpy(lokcie[4].serie, "2*3");
    strcpy(lokcie[4].powtorzenia, "10");
    strcpy(lokcie[5].nazwa, "Obroty kettelbellem przy pomocy dloni (L/P)");
    strcpy(lokcie[5].serie, "2*3");
    strcpy(lokcie[5].powtorzenia, "5");

    struct tRehab kark[6];
    strcpy(kark[0].nazwa, "Obroty glowy lezac na brzuchu z 5s pauzy");
    strcpy(kark[0].serie, "3");
    strcpy(kark[0].powtorzenia, "10");
    strcpy(kark[1].nazwa, "Izometryczne prostowanie glowy (L/P/Prz/T)");
    strcpy(kark[1].serie, "4*3");
    strcpy(kark[1].powtorzenia, "10s");
    strcpy(kark[2].nazwa, "Izometryczne odgiecie z 'Korona karku'");
    strcpy(kark[2].serie, "3");
    strcpy(kark[2].powtorzenia, "30s");
    strcpy(kark[3].nazwa, "Izometryczne 'W' z 5s pauzy");
    strcpy(kark[3].serie, "3");
    strcpy(kark[3].powtorzenia, "10");
    strcpy(kark[4].nazwa, "Prostowanie gornej czesci kregoslupa z 5s pauzy");
    strcpy(kark[4].serie, "3");
    strcpy(kark[4].powtorzenia, "10");
    strcpy(kark[5].nazwa, "Martwy ciag Bala");
    strcpy(kark[5].serie, "3");
    strcpy(kark[5].powtorzenia, "10");


    switch (wybor)
    {
    case 0:
        fprintf(plik, "DZIEN WOLNY.\n");
        break;
    case 1:
        fprintf(plik, ">STAW SKOKOWY<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=2; i++)
        {
            fprintf(plik, "%-50s", kostki[i].nazwa);
            fprintf(plik, "%4s", kostki[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", kostki[i].powtorzenia);
        }
        break;

    case 2:
        fprintf(plik, ">STAW KOLANOWY<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=3; i++)
        {
            fprintf(plik, "%-50s", kolana[i].nazwa);
            fprintf(plik, "%4s", kolana[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", kolana[i].powtorzenia);
        }
        break;

    case 3:
        fprintf(plik, ">STAW BIODROWY<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=6; i++)
        {
            fprintf(plik, "%-50s", biodra[i].nazwa);
            fprintf(plik, "%4s", biodra[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", biodra[i].powtorzenia);
        }
        break;

    case 4:
        fprintf(plik, ">PLECY<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=6; i++)
        {
            fprintf(plik, "%-50s", plecy[i].nazwa);
            fprintf(plik, "%4s", plecy[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", plecy[i].powtorzenia);
        }
        break;

    case 5:
        fprintf(plik, ">STAW BARKOWY<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=6; i++)
        {
            fprintf(plik, "%-50s", barki[i].nazwa);
            fprintf(plik, "%4s", barki[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", barki[i].powtorzenia);
        }
        break;

    case 6:
        fprintf(plik, ">STAW LOKCIOWY<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=5; i++)
        {
            fprintf(plik, "%-50s", lokcie[i].nazwa);
            fprintf(plik, "%4s", lokcie[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", lokcie[i].powtorzenia);
        }
        break;

    case 7:
        fprintf(plik, ">KARK<\n");
        fprintf(plik, "%-50s", naglowek1);
        fprintf(plik, "%-12s\n", naglowek2);
        for (i=0; i<=5; i++)
        {
            fprintf(plik, "%-50s", kark[i].nazwa);
            fprintf(plik, "%4s", kark[i].serie);
            fprintf(plik, "/");
            fprintf(plik, "%-10s\n", kark[i].powtorzenia);
        }
        break;

    default:
        printf("Error.\n");
        break;
    }
}

void Rehabilitacja()
{
    FILE *plik;
    int i, cwicz = -1;
    char dni[6][20] = {"PONIEDZIALEK", "WTOREK", "SRODA", "CZWARTEK", "PIATEK", "SOBOTA"};

    plik = fopen(". Rehabilitacja.txt", "w");

    if ((plik = fopen(". Rehabilitacja.txt", "w"))==NULL)
    {
        printf("Blad programu");
        system("PAUSE");
        abort();
    }

    printf("Program do tworzenia planu treningowego rehabilitacyjnego.\n\n");
    fprintf(plik, "Plan treningowy rehabilitacyjny.\n\n");

    for (i=0; i<=5; i++)
    {
        printf("%20s\n", dni[i]);
        fprintf(plik, "%-20s\n", dni[i]);

        while (cwicz < 0 || cwicz > 7)
        {
            printf("Podaj co chcesz cwiczyc tego dnia: \n");
            printf("0. Nic \n1. Stawy skokowe \n2. Stawy kolanowe \n3. Stawy biodrowe \n");
            printf("4. Kregoslup \n5. Stawy barkowe \n6. Stawy lokciowe \n7. Kark \n");
            scanf("%d", &cwicz);
            if (cwicz < 0 || cwicz > 7)
                printf("Blad - podano zly numer!\n");
        }

        Baza(plik, cwicz);
        fprintf(plik, "\n");
        printf("Zapisano.\n\n");
        cwicz = -1;
    }


    printf("\nZakonczono tworzenie planu.\n\n");

    fclose(plik);
}
