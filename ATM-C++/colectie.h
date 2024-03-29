#include <fstream>
#include <iostream>

using namespace std;

struct bancnota{
    int frecv,val;
};

class Colectie{
private:

    bancnota* b;
    int cap,nre;
public:
    Colectie(int cap = 10);
    Colectie(const Colectie &c);
    //~Colectie();
    int getcap();
    int getelem(int poz);
    int getfrelem(int poz);
    void setfrelem(int poz, int val);
    void adauga(int elem);
    bool sterge(int elem);
    int nrval();
    int suma();
    Colectie& operator=(const Colectie &c);
    friend ostream& operator<<(ostream &os, const Colectie &c);
};

