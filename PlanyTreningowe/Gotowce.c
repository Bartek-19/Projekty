#include <stdio.h>
#include <stdlib.h>

void zapis_dnia(int n, char cwiczenia[][50], char serie[][4], char powtorzenia[][10], int rpe[], FILE * plik)
{
    fprintf(plik, "%-50s", "Nazwa Cwiczenia:");
    fprintf(plik, "%-14s", "Ser./Powt.:");
    fprintf(plik, "%s\n", "RPE:");

    for (int i=0; i<n; i++)
    {
        fprintf(plik, "%-50s", cwiczenia[i]);
        fprintf(plik, "%4s/", serie[i]);
        fprintf(plik, "%-10s", powtorzenia[i]);
        fprintf(plik, "%d\n", rpe[i]);
    }

    fprintf(plik, "\n");
}

//----------

void planSilowy()
{
    FILE * plik;
    int wybor, wybor2, ind;

    char C[3][3][50] = { {"Wyciskanie na lawce", "Wyciskanie (hantli) na lawce skosnej", "Wyciskanie francuskie stojac (L/P)"},
                         {"Przysiad", "Przysiady ze sztanga z przodu", "Przysiad bulgarski (L/P)"},
                         {"Martwy ciag", "Martwy ciag sprinterski rumunski (L/P)", "Odgiecia na lawce rzymskiej"} };
    char S[3][3][4] = { {"5", "3", "2*3"},
                        {"5", "3", "2*3"},
                        {"5", "3", "2*3"} };
    char P[3][3][10] = { {"1-5", "8-12", "12-16"},
                         {"1-5", "8-12", "8-12"},
                         {"1-5", "8-12", "8-12"} };
    int I[3][3] = { {9, 8, 8},
                    {9, 8, 8},
                    {9, 8, 7} };

    char C4[4][50] = {"Podnoszenie sztangi biodrami", "Przysiad z pauza 3 sek.", "Wyciskanie sztangi nad glowe", "Podciaganie na drazku"};
    char S4[4][4] = {"3", "3", "3", "5"};
    char P4[4][10] = {"10-15", "6-10", "8-12", "8-12"};
    int I4[4] = {8, 7, 8, 9};

    plik = fopen("0 Plan Silowy.txt", "w");

    if ((plik=fopen("0 Plan Silowy.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy silowy\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc (3-6):  ");
        scanf("%d", &wybor);
    } while (wybor < 3 || wybor > 6);

    switch (wybor)
        {
        case 3:
            for(int i=0; i<3; i++)
            {
                fprintf(plik, ">DZIEN %d\n", i+1);
                zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
            }
            break;

        case 4:
            for(int i=0; i<3; i++)
            {
                fprintf(plik, ">DZIEN %d\n", i+1);
                zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
            }
            fprintf(plik, "\n>DZIEN 4:\n");
            zapis_dnia(4, C4, S4, P4, I4, plik);
            break;

        case 5:
            fprintf(plik, "\n>DZIEN 1:\n");
            do {
                printf("\nTrening dodatkowy\n");
                printf("1. Wyciskanie na lawce\n");
                printf("2. Przysiad\n");
                printf("3. Martwy ciag\n");
                printf("\n Wybierz trening dodatkowy:  ");
                scanf("%d", &wybor2);
            } while(wybor2 < 1 || wybor2 > 3);

            ind = wybor2 - 1;

            zapis_dnia(3, C[ind], S[ind], P[ind], I[ind], plik);

            for(int i=0; i<3; i++)
            {
                fprintf(plik, ">DZIEN %d\n", i+2);
                zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
            }
            fprintf(plik, "\n>DZIEN 5:\n");
            zapis_dnia(4, C4, S4, P4, I4, plik);
            break;

        case 6:
            for(int j=0; j<2; j++)
            {
                for(int i=0; i<3; i++)
                {
                    fprintf(plik, ">DZIEN %d\n", i+1+3*j);
                    zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
                }
            }
            break;

        default:
            printf("blad programu");
        }

    fclose(plik);

    printf("\nZapisano.\n\n");
}

void kalistenika()
{
    FILE * plik;
    int wybor;

    char C[4][3][50] = { {"Pompki na poreczach - dipy", "Pompki", "Prostowanie lokci na drazku"},
                          {"Podciaganie nachwytem", "Podciaganie podchwytem/neutralne", "Podciaganie australijskie"},
                          {"Sprint (interwalowo)", "Wykroki plajometryczne", "Skoki obunoz wzwyz"},
                          {"Unoszenie kolan na drazku", "Deska", "Rotacje z guma (L/P)"} };
    char S[4][3][4] = { {"3", "3", "3"},
                        {"3", "3", "3"},
                        {"<20", "5", "5"},
                        {"3", "3", "2*5"} };
    char P[4][3][10] = { {"8-12", "12-15", "15-18"},
                         {"6-10", "8-12", "16-20"},
                         {"40-100m", "5-8", "5-8"},
                         {"8-12", "40-60s", "12-15"} };
    int I[4][3] = { {9, 8, 8},
                     {9, 9, 8},
                     {8, 7, 7},
                     {9, 8, 8} };

    plik = fopen("0 Kalistenika.txt", "w");

    if ((plik=fopen("0 Kalistenika.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy kalisteniczny\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc (3, 4, 6):  ");
        scanf("%d", &wybor);
    } while (wybor < 3 || wybor > 6 || wybor == 5);

    switch (wybor)
    {
    case 3:
        for(int i=0; i<3; i++)
        {
            fprintf(plik, ">DZIEN %d\n", i+1);
            zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
        }
        break;
    case 4:
        for(int i=0; i<4; i++)
        {
            fprintf(plik, ">DZIEN %d\n", i+1);
            zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
        }
        break;
    case 6:
        for(int j=0; j<2; j++)
        {
            for(int i=0; i<3; i++)
            {
                fprintf(plik, ">DZIEN %d\n", i+1+3*j);
                zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
            }
        }
        break;
    default:
        printf("blad programu\n");
    }

    fprintf(plik, "\n  ADNOTACJA - PROGRESJE CWICZEN\n");
    fprintf(plik, "Proponowane sposoby na progresje cwiczen:\n\n");
    fprintf(plik, "pompki z podwyz. rekami -> dipy z podpartymi nogami -> dipy z asysta -> negatywy -> dipy ->\n"
                  "-> dipy na prostym drazku -> dipy na krazkach -> dipy plajometryczne -> dipy lucznicze ->\n"
                  "-> dipy lucz. na krazkach\n\n");
    fprintf(plik, "pompki z podwyz. rekami -> negatywy -> pompki z asysta -> pompki -> diamentowe pompki -> pompki z poglebieniem ->\n"
                  "-> pompki japonskie -> pompki z gumami -> pompki z podwyz. nogami -> pompki plajometryczne -> pompki jednoracz ->\n"
                  "-> pompki glowa w dol -> pompki glowa w dol z poglebieniem -> pompki na rekach\n\n");
    fprintf(plik, "podciaganie australijskie -> podciaganie aust. na krazkach -> podciaganie aust. z podwyzszonymi nogami -> negatywy ->\n"
                  "-> podciaganie z guma -> podciaganie podchwytem -> podciaganie neutralne -> podciaganie nachwytem -> podciaganie szerokie ->\n"
                  "-> podciaganie na krazkach -> podciaganie wysokie -> podciaganie lucznicze -> podciaganie jedna reka\n\n");
    fprintf(plik, "sprint krotki -> sprint -> sprint pod gorke -> sprint ze spadochronem oporowym\n\n"
                  "przeskoki z nogi na noge -> wykroki plajometryczne -> przysiady bulgarskie plajometryczne -> steppery plajometryczne ->\n"
                  "-> steppery plajometryczne boczne -> skoki na skrzynie jednonozne -> skoki na skrzynie jendonoz. boczne\n\n"
                  "skoki obunoz w dal -> przysiady z wyskokiem -> wybicia z kolan na nogi -> skoki na skrzynie -> skok w dal+na skrzynie ->\n"
                  "-> przysiady z wyskokiem+wyskok na skrzynie\n\n");
    if (wybor == 4)
    { fprintf(plik, "brzuszki -> brzuszki pelne -> unoszenie nog lezac -> unoszenie kolan na drazku -> unoszenie nog na drazku ->\n"
                    "-> brzuszki V-ki -> podciaganie nog do drazka\n\n"
                    "deska -> deska boczna -> deska hollow -> deska z dlugim podporem -> kolko ab-roller -> wiszenie L-sit\n\n"
                    "brzuszki rotacyjne -> obroty z guma -> wykroki rotacyjne");  }


    fclose(plik);

    printf("\nZapisano.\n\n");
}

void kettelebell()
{
    FILE * plik;
    int wybor;

    char C[6][3][50] = { {"Przysiad przedni", "Przysiad bulgarski (L/P)", "Przysiad goblet"},
                         {"Wyciskanie nad glowe", "Push-press", "Wyciskanie lezac na ziemi"},
                         {"Rwanie (L/P)", "Podrzuty", "Wymachy"},
                         {"Wioslowanie", "Wioslowanie goryla (L/P)", "Wioslowanie waskie (jednym KB)"},
                         {"Wstawanie Tureckie (L/P)", "Brzuszki rosyjskie", "Spacer farmera (L/P)"},
                         {"Uginanie rak", "Wyciskanie francuskie", "Obroty KB dookola glowy (L/P)"} };

    char S[6][3][4] = { {"3", "2*3", "3"},
                        {"3", "3", "3"},
                        {"2*3", "3", "3"},
                        {"3", "2*3", "3"},
                        {"2*3", "3", "2*3"},
                        {"5", "5", "2*5"} };

    char P[6][3][10] = { {"8-12", "8-12", "16-20"},
                         {"3-5", "4-6", "8-12"},
                         {"3-5", "3-5", "12-16"},
                         {"8-12", "6-10", "16-20"},
                         {"5-8", "16-20", "20-30m"},
                         {"8-12", "10-15", "8-12"} };

    int I[6][3] = { {8, 8, 7},
                    {9, 8, 8},
                    {8, 8, 7},
                    {8, 7, 7},
                    {8, 7, 7},
                    {9, 9, 7} };

    char C1[4][50] = {"Wyciskanie nad glowe", "Podrzuty", "Przysiad przedni", "Wioslowanie"};
    char S1[4][4] = {"5", "5", "5", "5"};
    char P1[4][10] = {"3-6", "6-10", "8-12", "6-10"};
    int I1[4] = {8, 7, 7, 8};

    char C2[2][4][50] = { {"Wyciskanie nad glowe", "Wioslowanie", "Wyciskanie lezac na ziemi", "Wioslowanie waskie (jednym KB)"},
                          {"Rwanie", "Przysiad przedni", "Wymachy KB", "Przysiad goblet"} };
    char S2[2][4][4] = { {"3", "3", "3", "3"},
                         {"3", "3", "3", "3"} };
    char P2[2][4][10] = { {"3-5", "8-12", "10-15", "16-20"},
                          {"3-5", "8-12", "16-20", "16-20"} };
    int I2[2][4] = { {9, 8, 8, 7},
                     {8, 8, 7, 7} };


    plik = fopen("0 Kettelebell.txt", "w");

    if ((plik=fopen("0 Kettelebell.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy Kettelebell\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc (1, 2, 4, 5, 6):  ");
        scanf("%d", &wybor);
    } while(wybor < 1 || wybor > 6 || wybor==3);

    switch(wybor)
    {
    case 1:
        zapis_dnia(4, C1, S1, P1, I1, plik);
        break;
    case 2:
        for(int i=0; i<2; i++)
        {
            fprintf(plik, "> DZIEN %d\n", i+1);
            zapis_dnia(4, C2[i], S2[i], P2[i], I2[i], plik);
        }
        break;
    case 4:
        for(int i=0; i<4; i++)
        {
            fprintf(plik, "> DZIEN %d\n", i+1);
            zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
        }
        break;
    case 5:
        for(int i=0; i<5; i++)
        {
            fprintf(plik, "> DZIEN %d\n", i+1);
            zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
        }
        break;
    case 6:
        for(int i=0; i<6; i++)
        {
            fprintf(plik, "> DZIEN %d\n", i+1);
            zapis_dnia(3, C[i], S[i], P[i], I[i], plik);
        }
        break;
    default:
        printf("Blad programu!\n\n");
    }

    fclose(plik);

    printf("\nZapisano.\n\n");
}

void planOlimpijski()
{
    FILE * plik;
    int wybor;

    char C[6][4][50] = { {"Podrzuty pelne", "Wyciskanie nad glowe", "Przysiad ze sztanga z przodu", "Martwy ciag rumunski"},
                         {"Rwanie pelne", "Wyciskanie rwaniowe", "Przysiady high-bar", "Wymachy Kettelebell"},
                         {"Cwierc-zarzut + Push-press", "Odgiecia na lawce rzymskiej", "Przysiady z wyskokiem", "Wyciskanie francuskie stojac"},
                         {"Cwierc-rwanie", "Przysiady ze sztanga nad glowa", "Wyskoki na skrzynie", "Wioslowanie sztangi nachwytem"},
                         {"Zarzuty pelne", "Wyrzuty sztangi", "Martwy ciag rwaniowy z deficytu", "Przysiad ze sztanga z przodu"},
                         {"Rwanie pelne", "Pompki glowa w dol", "Martwy ciag dynamiczny (Clean-pull)", "Przysiady na jednej nodze (pistoletowe) (L/P)"} };
    char S[6][4][4] = { {"3-8", "3", "3", "3"},
                        {"3-8", "3", "3", "3"},
                        {"3-5", "3", "5", "3"},
                        {"3-5", "3", "5", "3-5"},
                        {"3-5", "3-5", "3", "3"},
                        {"3-5", "3", "3", "2*3"} };
    char P[6][4][10] = { {"1-3", "4-8", "3-6", "10-15"},
                         {"1-3", "6-10", "3-6", "12-16"},
                         {"3-6", "16-20", "5-10", "12-16"},
                         {"3-6", "5-8", "5-8", "12-16"},
                         {"3-5", "1-3", "3-6", "8-12"},
                         {"3-5", "8-12", "2-5", "8-12"} };
    int I[6][4] = { {9, 8, 9, 8},
                    {9, 7, 9, 8},
                    {7, 8, 7, 8},
                    {7, 7, 7, 8},
                    {8, 9, 8, 8},
                    {8, 8, 9, 8} };

    plik = fopen("0 Plan Olimpijski.txt", "w");

    if ((plik=fopen("0 Plan Olimpijski.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy olimpijskiego podnoszenia ciezarow\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc(4, 6):  ");
        scanf("%d", &wybor);
    } while(wybor!=4 && wybor!=6);

    switch (wybor)
    {
    case 4:
        for(int i=0; i<4; i++)
        {
            fprintf(plik, ">DZIEN %d \n", i+1);
            zapis_dnia(4, C[i], S[i], P[i], I[i], plik);
        }
        break;
    case 6:
        for(int i=0; i<6; i++)
        {
            fprintf(plik, ">DZIEN %d\n", i+1);
            zapis_dnia(4, C[i], S[i], P[i], I[i], plik);
        }
        break;
    default:
        printf("blad programu.\n");
    }
    fprintf(plik, "\nProponowane progresje cwiczen\n\n");
    fprintf(plik, "Zarzut silowy -> Martwy ciag dynamiczny -> Cwierc-zarzut ->  Cwierc-zarzut z przysiadem ->\n"
                  "-> Zarzut wiszacy wysoki -> Zarzut wiszacy niski -> Pelny zarzut\n\n");
    fprintf(plik, "Rwanie hantla -> Martwy ciag rwaniowy dynamiczny -> Rwanie silowe -> Cwierc-rwanie ->\n"
                  "-> Cwierc-rwanie z przysiadem -> Rwanie wiszace wysokie -> Rwanie wiszace niskie ->\n"
                  "-> Pelne rwanie\n\n");
    fprintf(plik, "Wyciskanie hantli nad glowe -> Wyciskanie sztangi nad glowe -> Push-press -> Zejscia pod sztange ->\n"
                  "-> Wyrzuty sztangi do gory");

    fclose(plik);

    printf("\nZapisano.\n\n");
}

void grappling()
{
    FILE * plik;
    int wybor, wyborDodatkowy;

    char C2_1[2][4][50] = { {"Wymachy KB z guma", "Przysiad high-bar", "Wyciskanie na lawce", "Podciaganie na drazku"},
                            {"Przysiad ze sztanga z przodu", "Martwy ciag rumunski", "Wyciskanie hantli na siedzaco", "Wioslowanie sztanga"} };
    char S2_1[2][4][4] = { {"5", "5", "5", "5"},
                           {"3", "3", "3", "3"} };
    char P2_1[2][4][10] = { {"5-8", "3-6", "3-6", "5-8"},
                            {"8-12", "8-12", "10-15", "12-16"} };
    int I2_1[2][4] = { {7, 8, 8, 8},
                       {8, 8, 7, 7} };

    char C2_2[2][4][50] = { {"Martwy ciag", "Pompki plajometryczne", "Przysiad ze sztanga z przodu", "Wioslowanie goryla (L/P)"},
                            {"Wyciskanie na lawce", "Przysiady z wyskokiem na skrzynie", "Podciaganie na drazku", "Wymachy KB z guma"} };
    char S2_2[2][4][4] = { {"3-5", "5", "3-5", "2*5"},
                           {"3-5", "5", "3-5", "5"} };
    char P2_2[2][4][10] = { {"1-3", "3-6", "1-5", "6-10"},
                            {"1-3", "4-6", "4-8", "4-6"} };
    int I2_2[2][4] = { {9, 7, 8, 7},
                       {9, 7, 8, 7} };

    char C_Push[3][50] = {"Przysiad high-bar", "Wyciskanie hantli lezac na ziemi", "Wyciskanie na siedzaco"};
    char S_Push[3][4] = {"5", "5", "5"};
    char P_Push[3][10] = {"3-6", "4-8", "8-12"};
    int I_Push[3] = {9, 8, 8};

    char C_Pull[3][50] = {"Martwy ciag", "Podciaganie na drazku", "Wioslowanie hantlem (L/P)"};
    char S_Pull[3][4] = {"5", "5", "2*5"};
    char P_Pull[3][10] = {"3-6", "5-10", "8-12"};
    int I_Pull[3] = {9, 8, 8};

    char C_Kond[3][50] = {"Sprinty (interwalowo)", "Wykonywanie rzutow z gumami", "Drilowanie na manekinie/worku/Walka z cieniem"};
    char S_Kond[3][4] = {"<20", "3-5", "3-5"};
    char P_Kond[3][10] = {"30-50m", "5-8min", "5-8min"};
    int I_Kond[3] = {8, 7, 5};

    char C4_Kond[4][1][50] = { {"Sprinty (interwalowo)"}, {"Wykonywanie rzutow z gumami"},
                                {"Drilowanie na manekinie/worku/Walka z cieniem"}, {"Jazda na rowerze"} };
    char S4_Kond[4][1][4] = { {"<20"}, {"3-5"}, {"3-5"}, {"1"} };
    char P4_Kond[4][1][10] = { {"30-50m"}, {"5-8min"}, {"5-8min"}, {"5-10km"} };
    int I4_kond[4][1] = { {8}, {7}, {5}, {7} };

    char C5_1[5][3][50] = { {"Wyciskanie na lawce", "Wyciskanie hantli na siedzaco", "Wyciskanie hantli lezac na ziemi"},
                            {"Jazda na rowerze", "Drilowanie na manekinie/worku/Walka z cieniem", "Brzuszki (zwykle + rosyjskie)"},
                            {"Podciaganie na drazku", "Wioslowanie hantlem (L/P)", "Mostek zapasniczy"},
                            {"Sprint (interwalowo)", "Wykonywanie rzutow z gumami", "Delfinki (tabata)"},
                            {"Przysiad high-bar", "Martwy ciag rumunski", "Przysiady bulgarskie (L/P)"} };
    char S5_1[5][3][4] = { {"5", "3", "3"},
                           {"1", "3-5", "3"},
                           {"5", "2*5", "3"},
                           {"<20", "3-5", "<10"},
                           {"5", "5", "3"} };
    char P5_1[5][3][10] = { {"3-6", "8-12", "6-10"},
                            {"5-10km", "5-8min", "20-40"},
                            {"5-10", "8-12", "1-3min"},
                            {"30-50m", "5-8min", "1min"},
                            {"3-6", "8-12", "8-12"} };
    int I5_1[5][3] = { {9, 8, 8},
                       {7, 7, 8},
                       {9, 8, 8},
                       {8, 7, 7},
                       {9, 8, 8} };


    plik = fopen("0 Plan Grapplingowy.txt", "w");

    if ((plik=fopen("0 Plan Grapplingowy.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy Grappling\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc (2-5):  ");
        scanf("%d", &wybor);
    } while(wybor < 2 || wybor > 5);

    switch(wybor)
    {
    case 2:
        do {
            printf("Wybierz opcje programu dwudniowego\n"
                   " 1. Sila + hipertrofia\n 2. Condense Conjugate\n");
            scanf("%d", &wyborDodatkowy);
        } while(wyborDodatkowy!=1 && wyborDodatkowy!=2);

        if (wyborDodatkowy==1)
        {
            for(int i=0; i<2; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                zapis_dnia(4, C2_1[i], S2_1[i], P2_1[i], I2_1[i], plik);
            }
        }
        else if (wyborDodatkowy==2)
            {
                for(int i=0; i<2; i++)
                {
                    fprintf(plik, "> DZIEN %d\n", i+1);
                    zapis_dnia(4, C2_2[i], S2_2[i], P2_2[i], I2_2[i], plik);
                }
            }
            else
                printf("Blad programu.\n");
        break;

    case 3:
        fprintf(plik, "> DZIEN 1\n");
        zapis_dnia(3, C_Push, S_Push, P_Push, I_Push, plik);
        fprintf(plik, "> DZIEN 2\n");
        zapis_dnia(3, C_Pull, S_Pull, P_Pull, I_Pull, plik);
        fprintf(plik, "> DZIEN 3\n");
        zapis_dnia(3, C_Kond, S_Kond, P_Kond, I_Kond, plik);
        break;

    case 4:
        do {
            printf("Wybierz opcje programu czterodniowego\n"
                   " 1. Jedna sesja dziennie\n 2. Dwie sesje dziennie\n");
            scanf("%d", &wyborDodatkowy);
        } while(wyborDodatkowy!=1 && wyborDodatkowy!=2);

        if (wyborDodatkowy==1)
        {
            fprintf(plik, "> DZIEN 1\n");
            zapis_dnia(3, C_Push, S_Push, P_Push, I_Push, plik);
            fprintf(plik, "> DZIEN 2\n");
            zapis_dnia(3, C5_1[3], S5_1[3], P5_1[3], I5_1[3], plik);
            fprintf(plik, "> DZIEN 3\n");
            zapis_dnia(3, C_Pull, S_Pull, P_Pull, I_Pull, plik);
            fprintf(plik, "> DZIEN 4\n");
            zapis_dnia(3, C5_1[1], S5_1[1], P5_1[1], I5_1[1], plik);
        }
        else if (wyborDodatkowy==2)
            {
                for(int i=0; i<4; i++)
                {
                    fprintf(plik, "> DZIEN %d\n", i+1);
                    fprintf(plik, "RANO\n");
                    zapis_dnia(1, C4_Kond[i], S4_Kond[i], P4_Kond[i], I4_kond[i], plik);
                    fprintf(plik, "\nPOPOLUDNIE\n");
                    if(i%2==0)
                        zapis_dnia(3, C_Push, S_Push, P_Push, I_Push, plik);
                    else
                        zapis_dnia(3, C_Pull, S_Pull, P_Pull, I_Pull, plik);
                }
            }
            else
                printf("Blad programu.\n");
        break;

    case 5:
        do {
            printf("Wybierz opcje programu pieciodniowego\n"
                   " 1. raz w tygodniu kondycja\n 2. dwa razy w tygodniu kondycja\n");
            scanf("%d", &wyborDodatkowy);
        } while(wyborDodatkowy!=1 && wyborDodatkowy!=2);

        if(wyborDodatkowy==1)
        {
            fprintf(plik, "> DZIEN 1\n");
            zapis_dnia(3, C_Push, S_Push, P_Push, I_Push, plik);
            fprintf(plik, "> DZIEN 2\n");
            zapis_dnia(3, C_Pull, S_Pull, P_Pull, I_Pull, plik);
            fprintf(plik, "> DZIEN 3\n");
            zapis_dnia(3, C_Kond, S_Kond, P_Kond, I_Kond, plik);
            fprintf(plik, "> DZIEN 4\n");
            zapis_dnia(3, C_Push, S_Push, P_Push, I_Push, plik);
            fprintf(plik, "> DZIEN 5\n");
            zapis_dnia(3, C_Pull, S_Pull, P_Pull, I_Pull, plik);
        }
        else if(wyborDodatkowy==2)
            {
                for(int i=0; i<5; i++)
                {
                    fprintf(plik, "> DZIEN %d\n", i+1);
                    zapis_dnia(3, C5_1[i], S5_1[i], P5_1[i], I5_1[i], plik);
                }
            }
            else
                printf("Blad programu!\n");
        break;

    default:
        printf("Blad programu!\n");
    }

    fclose(plik);

    printf("\nZapisano.\n\n");
}

void mma()
{
    FILE * plik;
    int wybor, wyborDodatkowy;

    char C2[2][4][50] = { {"Martwy ciag", "Pompki plajometryczne", "Przysiad Zerchera", "Wioslowanie goryla (L+P)"},
                          {"Wyciskanie lezac na ziemi", "Przysiady z wyskokiem na skrzynie", "Podciaganie na drazku", "Wymachy KB z guma"} };
    char S2[2][4][4] = { {"3-5", "5", "3-5", "5"},
                         {"3-5", "5", "3-5", "5"} };
    char P2[2][4][10] = { {"1-3", "3-6", "1-5", "6-10"},
                          {"3-5", "4-6", "4-8", "4-6"} };
    int I2[2][4] = { {9, 7, 8, 7},
                     {9, 7, 8, 7} };

    char C3[3][4][50] = { {"Wyciskanie lezac na ziemi", "Wyciskanie hantli na siedzaco", "Pompki plajometryczne", "Deska boczna (L/P)"},
                          {"Podciaganie na drazku (z obciazeniem)", "Wioslowanie hantla (L/P)", "Wioslowanie goryla (L+P)(z gumami)", "Obroty z podparta sztanga - landmine (L+P)"},
                          {"Martwy ciag (z gumami)", "Przysiad Zerchera", "Przysiad bulgarski plajometryczny (L/P)", "Odgiecia na lawce rzymskiej"} };
    char S3[3][4][4] = { {"3-5", "3", "5", "2*3"},
                         {"3-5", "2*3", "5", "3"},
                         {"3-5", "3", "2*5", "3"} };
    char P3[3][4][10] = { {"3-6", "6-10", "4-6", "15-30s"},
                          {"5-8", "6-10", "6-10", "20-30"},
                          {"3-5", "5-8", "6-10", "15-20"} };
    int I3[3][4] = { {9, 8, 7, 7},
                     {9, 8, 7, 8},
                     {9, 8, 7, 8} };

    char C_kondycja[3][4][50] = { {"Sprinty (interwalowo)", "Delfinki (tabata)", "Wioslowanie guma", "Wyciskanie guma"},
                                  {"Bieg z ciezarem na linie", "Przyciaganie ciezaru na linie", "Bieg tylem z ciezarem na linie", "Pompki"},
                                  {"Bieg", "Liny treningowe", "Skoki w dal obunoz", "Rzuty manekinem/workiem treningowym"} };
    char S_kondycja[3][4][4] = { {"<20", "<10", "5", "5"},
                                 {"5", "5", "5", "5"},
                                 {"1", "3", "5", "5"} };
    char P_kondycja[3][4][10] = { {"40-100m", "1min", "3min", "3min"},
                                  {"20-40m", "20-40m", "20-40m", "25-50"},
                                  {"5-10km", "3min", "40-60m", "5min"} };
    int I_kondycja[3][4] = { {9, 8, 7, 7},
                             {8, 8, 8, 8},
                             {8, 7, 7, 8} };

    char C_push[4][50] = {"Przysiad Zerchera", "Wyciskanie lezac na ziemi", "Wyciskanie na siedzaco", "Pompki plajometryczne"};
    char S_push[4][4] = {"5", "5", "5", "5"};
    char P_push[4][10] = {"3-6", "4-8", "8-12", "4-8"};
    int I_push[4] = {9, 8, 8, 7};

    char C_pull[4][50] = {"Martwy ciag", "Podciaganie na drazku (z obciazeniem)", "Wioslowanie hantlem (L/P)", "Wioslowanie waskie"};
    char S_pull[4][4] = {"5", "5", "2*5", "5"};
    char P_pull[4][10] = {"3-6", "5-8", "8-12", "16-20"};
    int I_pull[4] = {9, 8, 8, 7};

    char C_hipertrofia[6][50] = {"Wymachy Kettelbell", "Pompki na poreczach", "Przysiad bulgarski (L/P)", "Wioslowanie sztangi", "Unoszenie nog na drazku", "Odgiecia na lawce rzymskiej"};
    char S_hipertrofia[6][4] = {"3", "3", "2*3", "3", "5", "5"};
    char P_hipertrofia[6][10] = {"16-20", "8-12", "8-12", "8-12", "20-25", "20-25"};
    int I_hipertrofia[6] = {8, 8, 8, 8, 7, 7};

    plik = fopen("0 MMA.txt", "w");

    if ((plik=fopen("0 MMA.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy MMA\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc (2-5):  ");
        scanf("%d", &wybor);
    } while(wybor < 2 || wybor > 5);

    switch (wybor)
    {
    case 2:
        for (int i=0; i<2; i++)
        {
            fprintf(plik, "> DZIEN %d:\n", i+1);
            zapis_dnia(4, C2[i], S2[i], P2[i], I2[i], plik);
        }
        break;

    case 3:
        for (int i=0; i<3; i++)
        {
            fprintf(plik, "> DZIEN %d:\n", i+1);
            zapis_dnia(4, C3[i], S3[i], P3[i], I3[i], plik);
        }
        break;

    case 4:
        fprintf(plik, "> DZIEN 1:\n");
        zapis_dnia(4, C2[0], S2[0], P2[0], I2[0], plik);
        fprintf(plik, "> DZIEN 2:\n");
        zapis_dnia(4, C_kondycja[0], S_kondycja[0], P_kondycja[0], I_kondycja[0], plik);
        fprintf(plik, "> DZIEN 3:\n");
        zapis_dnia(4, C2[1], S2[1], P2[1], I2[1], plik);
        fprintf(plik, "> DZIEN 4:\n");
        zapis_dnia(4, C_kondycja[1], S_kondycja[1], P_kondycja[1], I_kondycja[1], plik);
        break;

    case 5:
        do {
            printf("Wybierz schemat treningu pieciodniowego:\n");
            printf(" 1. Push/Pull/Nogi + 2*Kondycja\n");
            printf(" 2. Push/Pull + hipertrofia + 2*Kondycja\n");
            printf(" 3. Push/Pull + 3*Kondycja\n");
            printf(" 4. Condense Conjugate + 3*Kondycja\n");
            printf("Twoj wybor:  ");
            scanf("%d", &wyborDodatkowy);
        } while(wyborDodatkowy<1 || wyborDodatkowy>4);

        switch(wyborDodatkowy)
        {
        case 1:
            for(int i=0; i<5; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                if(i%2==0)
                    zapis_dnia(4, C3[i/2], S3[i/2], P3[i/2], I3[i/2], plik);
                else
                    zapis_dnia(4, C_kondycja[i/2], S_kondycja[i/2], P_kondycja[i/2], I_kondycja[i/2], plik);
            }
            break;

        case 2:
            fprintf(plik, "> DZIEN 1\n");
            zapis_dnia(4, C_push, S_push, P_push, I_push, plik);
            fprintf(plik, "> DZIEN 2\n");
            zapis_dnia(4, C_kondycja[0], S_kondycja[0], P_kondycja[0], I_kondycja[0], plik);
            fprintf(plik, "> DZIEN 3\n");
            zapis_dnia(4, C_pull, S_pull, P_pull, I_pull, plik);
            fprintf(plik, "> DZIEN 4\n");
            zapis_dnia(4, C_kondycja[1], S_kondycja[1], P_kondycja[1], I_kondycja[1], plik);
            fprintf(plik, "> DZIEN 5\n");
            zapis_dnia(6, C_hipertrofia, S_hipertrofia, P_hipertrofia, I_hipertrofia, plik);
            break;

        case 3:
            for(int i=0; i<5; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                if(i%2==0)
                    zapis_dnia(4, C_kondycja[i/2], S_kondycja[i/2], P_kondycja[i/2], I_kondycja[i/2], plik);
                else if(i==1)
                    zapis_dnia(4, C_push, S_push, P_push, I_push, plik);
                else if(i==3)
                    zapis_dnia(4, C_pull, S_pull, P_pull, I_pull, plik);
            }
            break;

        case 4:
            for(int i=0; i<5; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                if(i%2==0)
                    zapis_dnia(4, C_kondycja[i/2], S_kondycja[i/2], P_kondycja[i/2], I_kondycja[i/2], plik);
                else
                    zapis_dnia(4, C2[i/2], S2[i/2], P2[i/2], I2[i/2], plik);
            }
            break;
        default:
            printf("Error!\n");
        }
        break;

    default:
          printf("Blad programu!\n");
    }

    fclose(plik);

    printf("\nZapisano.\n\n");
}

void hipertrofia()
{
    FILE * plik;
    int wybor, wyborDodatkowy;

    char C_PPL[6][4][50] = { {"Wyciskanie na lawce", "Wyciskanie hantli na siedzaco", "Wyciskanie franc. hantla na lezaco (L/P)", "Rozpietki"},
                             {"Podciaganie na drazku nachwytem", "Wioslowanie hantlem (L/P)", "Uginanie sztangi na biceps", "Odwrotne rozpietki"},
                             {"Przysiady ze sztanga z przodu", "Wymachy Kettelebell", "Stawanie na palcach z obciazeniem", "Przysiad goblet"},
                             {"Pompki na poreczach", "Wyciskanie hantli na lawce skosnej", "Wyciskanie francuskie na stojaco", "Wznosy boczne"},
                             {"Wioslowanie sztangi podchwytem", "Wyciag pionowy", "Kaptury", "Uginanie hantli na biceps na lawce skosnej"},
                             {"Martwy ciag rumunski", "Przysiady bulgarskie (L/P)", "Podnoszenie ciezaru lydkami na siedzaco", "Uginanie nog (L/P)"} };
    char S_PPL[6][4][4] = { {"3", "3", "2*3", "3"},
                            {"3", "2*3", "3", "3"},
                            {"3", "3", "3", "3"},
                            {"3", "3", "3", "3"},
                            {"3", "3", "3", "3"},
                            {"3", "2*3", "3", "2*3"} };
    char P_PPL[6][4][10] = { {"5-8", "8-12", "16-20", "16-20"},
                             {"5-8", "8-12", "8-12", "16-20"},
                             {"5-8", "16-20", "20-30", "16-20"},
                             {"8-12", "8-12", "16-20", "12-16"},
                             {"8-12", "12-16", "16-20", "12-16"},
                             {"8-12", "8-12", "16-20", "16-20"} };
    int I_PPL[6][4] = { {9, 8, 7, 7},
                        {9, 8, 8, 7},
                        {9, 7, 7, 7},
                        {8, 8, 7, 7},
                        {8, 8, 8, 8},
                        {8, 8, 7, 7} };

    char C_split3[3][6][50] = { {"Podciaganie podchwytem", "Pompki na poreczach", "Uginanie mlotkowe przed tulowiem", "Wyciskanie francuskie lezac",
                                 "Uginanie hantli na lawce skosnej", "Wyciskanie francuskie na siedzaco"},
                                {"Przysiady ze sztanga z przodu", "Martwy ciag rumunski", "Przysiady bulgarskie (L/P)", "Odgiecia na lawce rzymskiej",
                                 "Prostowanie nog (L/P)", "Uginanie nog (L/P)"},
                                {"Wyciskanie na lawce", "Podciaganie nachwytem", "Wyciskanie hantli na lawce skosnej", "Wioslowanie sztangi",
                                 "Rozpietki", "Face-pull"} };
    char S_split3[3][6][4] = { {"3", "3", "3", "3", "3", "3"},
                               {"3", "3", "2*3", "3", "2*3", "2*3"},
                               {"3", "3", "3", "3", "3", "3"} };
    char P_split3[3][6][10] = { {"8-12", "8-12", "10-15", "12-16", "12-16", "16-20"},
                                {"8-12", "8-12", "8-12", "10-15", "16-20", "16-20"},
                                {"8-12", "8-12", "12-16", "12-16", "16-20", "20-25"} };
    int I_split3[3][6] = { {8, 8, 8, 8, 7, 7},
                           {8, 8, 8, 8, 7, 7},
                           {8, 8, 8, 8, 7, 7} };

    char C_split6[6][6][50] = { {"Wyciskanie na lawce", "Wyciskanie na lawce skosnej", "Wyciskanie neutralne hantli na lawce", "Wznosy przednie na lawce skosnej", "Rozpietki", "Pompki"},
                                {"Podciaganie na drazku", "Wioslowanie sztanga", "Wyciag pionowy", "Wioslowanie hantlem (L/P)", "Wyciag pionowy jednoracz (L/P)", "Pullover"},
                                {"Przysiady high-bar", "Martwy ciag rumunski", "Przysiady ze sztanga z przodu", "Uginanie nog (L/P)", "Przysiady bulgarskie (L/P)", "Wymachy Kettelebell"},
                                {"Wyciskanie hantli na siedzaco", "Wznosy boczne", "Wznosy narciarskie", "Face-pull", "Odwrotne rozpietki", "Obroty talerzem dookola glowy (L/P)"},
                                {"Podciaganie podchwytem", "Pompki na poreczach", "Uginanie rak ze sztanga", "Wyciskanie francuskie na lezaco", "Uginanie mlotkowe na lawce skosnej", "Wyciskanie francuskie na stojaco"},
                                {"Shrugsy", "Uginanie nadgarstkow", "Unoszenie nog na drazku", "Mostek zapasniczy", "Odginanie nadgarstkow", "Brzuszki rosyjskie"} };
    char S_split6[6][6][4] = { {"3", "3", "3", "3", "3", "3"},
                                {"3", "3", "3", "2*3", "2*3", "3"},
                                {"3", "3", "3", "2*3", "2*3", "3"},
                                {"3", "3", "3", "3", "3", "2*3"},
                                {"3", "3", "3", "3", "3", "3"},
                                {"3", "3", "3", "3", "3", "3"} };
    char P_split6[6][6][10] = { {"5-8", "8-12", "8-12", "16-20", "16-20", "15<"},
                                {"5-10", "8-12", "12-16", "8-12", "12-16", "16-20"},
                                {"5-8", "8-12", "8-12", "16-20", "12-16", "16-20"},
                                {"8-12", "12-16", "12-16", "16-20", "16-20", "12-16"},
                                {"8-12", "8-12", "8-12", "12-16", "12-16", "16-20"},
                                {"16-20", "12-16", "16-20", "1-3min", "12-16", "16-20"} };
    int I_split6[6][6] = { {9, 8, 8, 7, 7, 6},
                           {9, 8, 8, 8, 7, 7},
                           {9, 8, 8, 7, 7, 7},
                           {8, 8, 8, 7, 7, 6},
                           {8, 8, 8, 8, 7, 7},
                           {8, 8, 7, 8, 8, 7} };

    plik = fopen("0 Plan Kulturystyczny.txt", "w");

    if ((plik=fopen("0 Plan Kulturystyczny.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy kulturystyczny\n\n");

    do {
        printf("Ile dni w tygodniu chcesz cwiczyc (3, 6):  ");
        scanf("%d", &wybor);
    } while(wybor!=3 && wybor!=6);

    do {
        printf("Podaj w jakim stylu chcesz cwiczyc:\n 1. Push/Pull/Legs\n 2. Split\nTwoj wybor:  ");
        scanf("%d", &wyborDodatkowy);
    } while(wyborDodatkowy!=1 && wyborDodatkowy!=2);

    if(wyborDodatkowy==1)
    {
        switch(wybor)
        {
        case 3:
            for(int i=0; i<3; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i/2+1);
                zapis_dnia(4, C_PPL[i], S_PPL[i], P_PPL[i], I_PPL[i], plik);
            }
            break;
        case 6:
            for(int i=0; i<6; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                zapis_dnia(4, C_PPL[i], S_PPL[i], P_PPL[i], I_PPL[i], plik);
            }
            break;
        default:
            printf("Blad programu!\n\n");
        }
    }

    else if(wyborDodatkowy==2)
    {
        switch(wybor)
        {
        case 3:
            for(int i=0; i<3; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                zapis_dnia(6, C_split3[i], S_split3[i], P_split3[i], I_split3[i], plik);
            }
            break;
        case 6:
            for(int i=0; i<6; i++)
            {
                fprintf(plik, "> DZIEN %d\n", i+1);
                zapis_dnia(6, C_split6[i], S_split6[i], P_split6[i], I_split6[i], plik);
            }
            break;
        default:
            printf("Blad programu!\n\n");
        }
    }
    else
        printf("Blad programu!\n\n");

    fclose(plik);

    printf("\nZapisano.\n\n");
}

void total()
{
    FILE * plik;
    int wybor, wyborDodatkowy;

    char C5[5][5][50] = { {"Zarzuty", "Przysiady ze sztanga z przodu", "Martwy ciag rumunski", "Przysiady bulgarskie (L/P)", "Wymahy Kettelebell"},
                          {"Push-pressy", "Wyciskanie na lawce", "Podciaganie na drazku z obciazeniem", "Wyciskanie hantli na siedzaco", "Wioslowanie sztangi"},
                          {"Skoki z obciazeniem + na podwyzszenie", "Skok do przodu + do gory", "Skoki na podwyzszenie", "Przysiady bulgarskie plajometryczne (L/P)", "Wyskoki z kolan"},
                          {"Rwanie sztangi", "Zarzuty z wysokosci kolan", "Wyrzuty sztangi", "Przysiady z wyskokiem", "Rwanie hantla na jednej nodze (L/P)"},
                          {"Pompki na poreczach", "Podciaganie neutralne/podchwytem", "Wyciskanie francuskie na siedzaco", "Uginanie mlotkowe przed tulowiem", "Pullover z wycisnieciem francuskim"} };
    char S5[5][5][4] = { {"3", "3", "3", "2*3", "3"},
                         {"3", "3", "3", "3", "3"},
                         {"5", "5", "5", "2*3", "3"},
                         {"3", "3", "5", "3", "2*3"},
                         {"5", "5", "5", "5", "3"} };
    char P5[5][5][10] = { {"2-5", "3-6", "8-12", "8-12", "16-20"},
                          {"3-5", "3-5", "5-8", "8-12", "8-12"},
                          {"3-5 + 1", "3", "5", "8-10", "5"},
                          {"1-3", "2-5", "1-3", "3-5", "5-8"},
                          {"8-12", "8-12", "16-20", "12-16", "6-10"} };
    int I5[5][5] = { {8, 9, 8, 8, 7},
                     {8, 9, 8, 8, 8},
                     {8, 7, 7, 6, 6},
                     {9, 8, 8, 8, 7},
                     {8, 8, 7, 7, 8} };

    char C6_1[6][6][50] = { {"Wyrzuty", "Wyciskanie na lawce", "Podciaganie na drazku", "Wioslowanie hantlem (L/P)", "Uginanie mlotkowe przed cialem", "Odwrocone rozpietki"},
                            {"Zarzuty", "Przysiad", "Przysiady bulgarskie (L/P)", "Przysiady ze sztanga z przodu", "Stawanie na palcach (L/P)", "Prostowanie nog"},
                            {"Rwanie", "Wyciskanie na lawce", "Wyciskanie na siedzaco", "Wyciskanie francuskie hantlem (L/P)", "Rozpietki", "Wznosy boczne"},
                            {"Podrzuty", "Martwy ciag", "Martwy ciag rumunski", "Wymachy Kettelebell", "Uginanie nog", "Unoszenie ciezaru lydkami na siedzaco"},
                            {"Podciaganie podchwytem", "Wyciskanie na lawce skosnej", "Uginanie hantli na lawce skosnej", "Wyciskanie francuskie na siedzaco", "Face-pull", "Uginanie/odginanie nadgarstkow"},
                            {"Skoki z obciazeniem + na podwyzszenie", "Wyskok z kolan + w dal", "Skoki z boku na bok (L+P)", "Skoki na podwyzszenie", "Przysiady bulgarskie plajometryczne (L/P)", "Skok w dal + w bok (L/P)"} };
    char S6_1[6][6][4] = { {"5", "5", "3", "2*3", "3", "3"},
                           {"5", "5", "2*3", "3", "2*3", "3"},
                           {"5", "5", "3", "2*3", "3", "3"},
                           {"5", "5", "3", "3", "3", "3"},
                           {"3", "3", "3", "3", "3", "3"},
                           {"5", "5", "5", "5", "2*5", "2*5"} };
    char P6_1[6][6][10] = { {"1-3", "3-5", "5-8", "8-12", "8-12", "16-20"},
                            {"1-5", "3-5", "8-12", "8-12", "16-20", "12-16"},
                            {"1-5", "3-5", "8-12", "12-16", "16-20", "12-16"},
                            {"1-3", "3-5", "8-12", "16-20", "12-16", "16-20"},
                            {"10-15", "8-12", "12-16", "12-16", "16-20", "12-16"},
                            {"3-5 + 1", "5", "5", "5", "7", "3"} };
    int I6_1[6][6] = { {8, 9, 8, 8, 8, 7},
                       {8, 9, 8, 8, 7, 8},
                       {8, 9, 8, 8, 7, 8},
                       {8, 9, 8, 7, 8, 7},
                       {8, 8, 8, 8, 7, 8},
                       {8, 8, 7, 7, 6, 6} };

    char C6_2[6][5][50] = { {"Wyrzuty sztangi", "Wyciskanie na lawce", "Wyciskanie hantli na lawce skosnej", "Rozpietki", "Wyciskanie francuskie na siedzaco"},
                            {"Zarzuty", "Przysiad ze sztanga z przodu", "Przysiad z pauza", "Przysiad z wyskokiem", "Bieg tylem z ciezarem na linie"},
                            {"Rwanie", "Wyciskanie na lawce", "Podciaganie", "Wioslowanie sztangi", "Uginanie mlotkowe przed tulowiem"},
                            {"Zarzuty", "Martwy ciag", "Martwy ciag rumunski", "Wymachy kettelebell", "Wyskoki na podwyzszenie"},
                            {"Rwanie", "Wyciskanie na lawce", "Mostek zapasniczy", "Face-pull", "Unoszenie nog na drazku/na lezaco"},
                            {"Zarzuty", "Przysiad", "Przysiady bulgarskie (L/P)", "Odgiecia na lawce rzymskiej jednonoz. (L/P)", "Skoki boczne (L+P)"} };
    char S6_2[6][5][4] = { {"5", "5", "3", "3", "3"},
                           {"5", "5", "3", "3", "3"},
                           {"5", "5", "3", "3", "3"},
                           {"5", "5", "3", "3", "5"},
                           {"5", "5", "3", "5", "5"},
                           {"5", "5", "2*3", "2*3", "5"} };
    char P6_2[6][5][10] = { {"1-3", "3-5", "8-12", "16-20", "12-16"},
                            {"1-3", "3-6", "2-4", "3-5", "20-40m"},
                            {"1-3", "3-5", "8-12", "8-12", "12-16"},
                            {"3-5", "3-6", "8-12", "16-20", "5"},
                            {"3-5", "3-5", "1-3min", "20-30", "20-30"},
                            {"3-5", "3-6", "8-12", "8-12", "5"} };
    int I6_2[6][5] = { {8, 9, 8, 7, 7},
                       {8, 9, 8, 7, 7},
                       {8, 9, 8, 8, 7},
                       {7, 9, 8, 7, 7},
                       {7, 9, 7, 7, 7},
                       {7, 9, 8, 8, 7} };

    char C_kondycja[6][1][50] = { {"Sprinty (interwalowo)"},
                                  {"Przyciaganie ciezaru na linie"},
                                  {"Delfinki (tabata)"},
                                  {"Jazda na rowerze"},
                                  {"Bieg"},
                                  {"Skakanie na skakance"} };
    char S_kondycja[6][1][4] = { {"<20"},
                                 {"5"},
                                 {"<15"},
                                 {"1"},
                                 {"1"},
                                 {"5"} };
    char P_kondycja[6][1][10] = { {"20-60m"},
                                  {"40-60m"},
                                  {"1min"},
                                  {"15-20km"},
                                  {"5-10km"},
                                  {"1-3min"} };
    int I_kondycja[6][1] = { {8},
                             {7},
                             {8},
                             {7},
                             {7},
                             {8} };


    plik = fopen("0 Plan Total.txt", "w");

    if ((plik=fopen("0 Plan Total.txt","w")) == NULL)
    {
        printf("Blad programu.\n");
        system("PAUSE");
        abort();
    }

    fprintf(plik, "Plan treningowy TOTAL\n\n");

    do {
        printf("Podaj ile dni w tygodniu chcesz cwiczyc (5, 6):  ");
        scanf("%d", &wybor);
    } while(wybor!=5 && wybor!=6);

    switch(wybor)
    {
    case 5:
        for(int i=0; i<5; i++)
        {
            fprintf(plik, "> DZIEN %d:\n", i+1);
            zapis_dnia(5, C5[i], S5[i], P5[i], I5[i], plik);
        }
        break;
    case 6:
        do {
            printf("Ile sesji treningowych chcesz wykonywac w ciagu dnia (1/2):  ");
            scanf("%d", &wyborDodatkowy);
        } while(wyborDodatkowy!=1 && wyborDodatkowy!=2);

        if(wyborDodatkowy==1)
        {
            for(int i=0; i<6; i++)
            {
                fprintf(plik, "> DZIEN %d:\n", i+1);
                zapis_dnia(6, C6_1[i], S6_1[i], P6_1[i], I6_1[i], plik);
            }
        }
        else if(wyborDodatkowy==2)
        {
            for(int i=0; i<6; i++)
            {
                fprintf(plik, "> DZIEN %d:\n", i+1);
                fprintf(plik, "RANO:\n");
                zapis_dnia(1, C_kondycja[i], S_kondycja[i], P_kondycja[i], I_kondycja[i], plik);
                fprintf(plik, "WIECZOR:\n");
                zapis_dnia(5, C6_2[i], S6_2[i], P6_2[i], I6_2[i], plik);
            }
        }
        else
            printf("Blad programu!\n\n");
        break;
    default:
        printf("Blad programu!!!\n\n");
    }

    fclose(plik);

    printf("\nZapisano.\n\n");
}

//----------

void gotowy_plan()
{
    int wybor;

    printf("Tworzenie gotowego planu treningowego.\n\n");

    do {
        printf("Menu wyboru:\n");
        printf(" 1. Plan silowy\n 2. Kalistenika\n 3. Kettelebell\n 4. Olimpijskie Podnoszenie ciezarow\n");
        printf(" 5. Grappling\n 6. MMA\n 7. Hipertrofia\n 8. Total\n 0. Nic (Powrot do Menu glownego)\n");
        printf("Podaj swoj wybor:  ");
        scanf("%d", &wybor);
    } while (wybor < 0 || wybor > 8);

    switch (wybor)
    {
    case 0:
        printf("Powrot do menu glownego...\n\n");
        break;
    case 1:
        planSilowy();
        break;
    case 2:
        kalistenika();
        break;
    case 3:
        kettelebell();
        break;
    case 4:
        planOlimpijski();
        break;
    case 5:
        grappling();
        break;
    case 6:
        mma();
        break;
    case 7:
        hipertrofia();
        break;
    case 8:
        total();
        break;
    default:
        printf("Cos poszlo nie tak.\n\n");
    }
}
