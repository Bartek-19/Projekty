#include <iostream>

using namespace std;

int main()
{
    int liczba, n=50;

    do {
        cout<<"Podaj cyfre dodatnia: ";
        cin>>liczba;
    } while(liczba<=0);

    cout<<endl<<"Krok 0:"<<liczba<<endl;
    for(int i=1; i<=n; i++)
    {
        if(liczba%2)
            liczba = liczba*3 + 1;
        else
            liczba /= 2;

        cout<<"Krok "<<i<<":"<<liczba<<endl;
    }

    cout<<endl;
    return 0;
}
