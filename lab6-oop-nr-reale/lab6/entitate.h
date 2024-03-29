#ifndef NRC_H_INCLUDED
#define NRC_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Entitate{
private:
    float parteReala;
    float parteImag;
public:
    Entitate();
    Entitate(float r, float i);
    Entitate(const Entitate &en);
    int getParteReala();
    int getParteImag();
    void setParteReala(float r);
    void setParteImag(float i);
    friend ostream& operator<<(ostream& os, Entitate& en);
};

#endif
