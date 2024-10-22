#include <iostream>
#include "Tklasa.h"
#include <time.h>
#include <cstdlib>

using namespace std;

void cocktailShakerSort(int *tab, int n)
{
    int lewy=0, prawy=n-1, i, j;

    while(lewy < prawy)
    {
        i = lewy;
        j = prawy-1;
        while(i < prawy)
        {
            if(tab[i]>tab[i+1])
                swap(tab[i], tab[i+1]);
            i++;
        }
        while(j > lewy)
        {
            if(tab[j-1]>tab[j])
                swap(tab[j], tab[j-1]);
            j--;
        }
        lewy++;
        prawy--;
    }
}

int main()
{
    Tklasa Obiekt;
    string napis;
    int x, n, *tablica;

    cout<<sizeof(napis)<<endl<<sizeof(x)<<endl<<sizeof(Obiekt)<<endl<<endl;
    cout<<"---------------------------------------"<<endl<<endl;

    do{
        cout<<"Podaj ilosc elementow w tablicy:  ";
        cin>>n;
    } while(n <= 0);

    tablica = new int[n];

    srand(time(NULL));

    for(int i=0; i<n; i++)
        tablica[i] = rand()%50 + 1;

    cout<<endl<<"Tablica przed sortowaniem"<<endl<<"[ ";
    for(int i=0; i<n; i++)
        cout<<tablica[i]<<" ";
    cout<<"]"<<endl<<endl<<"Tablica po posortowaniu"<<endl<<"[ ";

    cocktailShakerSort(tablica, n);

    for(int i=0; i<n; i++)
        cout<<tablica[i]<<" ";
    cout<<"]"<<endl<<endl;

    delete [] tablica;
    return 0;
}
