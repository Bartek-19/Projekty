#include <iostream>
#define N 15
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void quicksort(int *tab, int pocz, int kon)
{
    if (pocz < kon)
    {
        int piwot = tab[(pocz + kon) / 2];
        int i = pocz - 1;
        int j = kon + 1;

        while (true)
        {
            do
            {
                i++;
            } while (tab[i] < piwot);

            do
            {
                j--;
            } while (tab[j] > piwot);

            if (i >= j)
                break;

            std::swap(tab[i], tab[j]);
        }

        quicksort(tab, pocz, j);
        quicksort(tab, j + 1, kon);
    }
}

void quicksortNS(int *x, int lewy, int prawy)
{
    int srodek = (lewy+prawy)/2, piwot = x[srodek], granica = lewy, i = lewy;

    x[srodek] = x[prawy];

    while(i<prawy)
    {
        if(x[i]<piwot)
        {
            swap(x[granica], x[i]);
            granica++;
        }
        i++;
    }
    x[prawy] = x[granica];
    x[granica] = piwot;

    if(lewy<granica-1)
        quicksortNS(x, lewy, granica-1);
    if(granica+1<prawy)
        quicksortNS(x, granica+1, prawy);
}

void tablicaINT()
{
    int *tablica = new int[N];

    srand(time(NULL));

    for(int i=0; i<N; i++)
        tablica[i] = rand()%50 + 1;

    cout<<"> Tablica przed posortowaniem:"<<endl<<"[ ";
    for(int i=0; i<N; i++)
        cout<<tablica[i]<<" ";
    cout<<"]"<<endl<<endl;

    //quicksort(tablica, 0, N-1);
    quicksortNS(tablica, 0, N-1);

    cout<<"> Tablica po posortowaniu:"<<endl<<"[ ";
    for(int i=0; i<N; i++)
        cout<<tablica[i]<<" ";
    cout<<"]"<<endl<<endl;

    delete [] tablica;
}

struct Tpracownik{
    string imie;
    string nazwisko;
    int godziny;
    float stawka;
    int premia;
    float wyplata;
};

Tpracownik wczytywanie()
{
    Tpracownik P;

    cout<<"Podaj imie:  ";
    cin>>P.imie;
    cout<<"Podaj nazwisko:  ";
    cin>>P.nazwisko;
    cout<<"Podaj ilosc przepracownaych godzin:  ";
    cin>>P.godziny;
    cout<<"Podaj stawke:  ";
    cin>>P.stawka;
    cout<<"Podaj premie (w %):  ";
    cin>>P.premia;
    P.wyplata = P.godziny*P.stawka*(1+P.premia/100.0);

    return P;
}

void quicksortSTRUCT(Tpracownik* T, int lewy, int prawy)
{
    int srodek = (lewy+prawy)/2, granica = lewy, i = lewy;
    Tpracownik piwot = T[srodek];

    T[srodek] = T[prawy];

    while(i<prawy)
    {
        if(T[i].wyplata < piwot.wyplata)
        {
            swap(T[granica], T[i]);
            granica++;
        }
        i++;
    }
    T[prawy] = T[granica];
    T[granica] = piwot;

    if(lewy<granica-1)
        quicksortSTRUCT(T, lewy, granica-1);
    if(granica+1<prawy)
        quicksortSTRUCT(T, granica+1, prawy);
}

void wyswietlanie(Tpracownik* tab, int n)
{
    for(int i=0; i<n; i++)
        cout<<setw(10)<<tab[i].imie<<setw(10)<<tab[i].nazwisko<<fixed<<setprecision(2)<<setw(10)<<tab[i].wyplata<<endl;
}

void tablicaSTRUCT()
{
    int n;
    do{
        cout<<"Podaj ilosc pracownikow:  ";
        cin>>n;
    } while(n<=0);

    Tpracownik *tablica = new Tpracownik[n];

    for(int i=0; i<n; i++)
        tablica[i] = wczytywanie();

    cout<<"Lista pracowników przed sortowaniem:"<<endl;
    wyswietlanie(tablica, n);

    quicksortSTRUCT(tablica, 0, n-1);

    cout<<endl<<"Lista pracownikow po sortowaniu:"<<endl;
    wyswietlanie(tablica, n);
}

int main()
{
    int wybor;
    do{
        cout<<"0. Wyjscie"<<endl;
        cout<<"1. Quicksort int"<<endl;
        cout<<"2. Quicksort struct"<<endl;
        cout<<"> Wybor:  ";
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
        case 0:
            cout<<"Koniec programu"<<endl;
            break;
        case 1:
            tablicaINT();
            break;
        case 2:
            tablicaSTRUCT();
            break;
        default:
            cout<<"Sweep sweep sweep"<<endl;
        }
        cout<<endl;
    }while(wybor!=0);

    return 0;
}
