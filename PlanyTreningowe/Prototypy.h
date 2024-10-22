#ifndef PROTOTYPY_H_INCLUDED
#define PROTOTYPY_H_INCLUDED

//----------

// Wlasny plan treningowy

struct tCwiczenie {
    char nazwa[50];
    char serie[4];
    char powtorzenia[10];
    int intensywnosc;
};

struct tCwiczenie zapis();

void planJednaSesja(FILE *plik, int n);

void planDwieSesje(FILE *plik, int n);

void customowy_plan();

//----------

// Plan treningowy progresyjny

double zaokraglenie(double ciezar);

void zapis_progresji(FILE *plik, int n);

void Progresja();

//----------

// Plan treningowy rehabilitacyjny

struct tRehab {
    char nazwa[50];
    char serie[4];
    char powtorzenia[10];
};

void Baza(FILE *plik, int wybor);

void Rehabilitacja();

//----------

// Plan treningowy gotowy

void zapis_dnia(int n, char cwiczenia[][50], char serie[][4], char powtorzenia[][10], int rpe[], FILE * plik);

void planSilowy();

void kalistenika();

void kettelebell();

void planOlimpijski();

void grappling();

void mma();

void hipertrofia();

void total();

void gotowy_plan();

//----------

#endif // PROTOTYPY_H_INCLUDED
