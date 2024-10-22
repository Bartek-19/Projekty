#ifndef TKLASA_H
#define TKLASA_H
#include <string>

using namespace std;

class Tklasa
{
    public:
        Tklasa();
        void wyswietl();
        virtual ~Tklasa();

    protected:

    private:
        string napis;
        int x;
};

#endif // TKLASA_H
