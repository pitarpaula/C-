#include <iostream>

using namespace std;

#include "atm.h"

ATM::ATM()
{
    this -> nrtranzactii = 0;
}

ATM::ATM(Colectie &c)
{
    this -> bani = c;
    this -> nrtranzactii = 0;
}

ostream& operator<<(ostream &os, ATM &a)
{
    os << "in atm exista urmatoarea colectie de bani: \n";
    os<<a.bani;
    os<<"\n";
    os << "s-a efectuat un numar de "<<a.nrtranzactii<<" tranzactii.";
    if(a.nrtranzactii>0)
    {
        os<<" acestea sunt: \n";
        for(int i=0; i<a.nrtranzactii; i++)
            os<<"\n"<<a.tranzactii[i];
    }
    os<<"\n";
    return os;
}

int n=4;

int x[11]; ///frecventa bacnotelor
int a[11]; ///pozitia bancnotelor in colectie

int cont=0;
Colectie c[10]; ///vectorul care va contine solutiile

void afisare(int k)
{
    for(int i = 0 ; i <= k  ; i++){
        int fr = x[i];
        while(fr>0) c[cont].adauga(a[i]),fr--;
    }
    cout<<c[cont];
    cont++;
}

void ATM::greedy(int ches)
{
    int rez=0, ok=0;
    int cap=this->bani.getcap();
    int k=-1;
    for(int i=cap-1; i>=0 && ok==0; i--)
    {
        int c=(ches-rez)/this->bani.getelem(i);
        if( c <= this->bani.getfrelem(this->bani.getelem(i)) && c > 0)
        {
            rez=rez+c*this->bani.getelem(i);
            k++;
            x[k]=c;
            a[k]=this->bani.getelem(i);
        }

        if(rez==ches) ok=1;
    }
    if(ok==1) afisare(k);
    else cout<<"nu s a gasit solutie\n";
}

void ATM::update(int ches)
{
    int op=cont-1,cap=c[op].getcap();
    Tranzactie t(this->nrtranzactii,ches,c[op]);
    this->tranzactii[this->nrtranzactii] = t;
    this->nrtranzactii++;
    for(int i=0; i<cap; i++){
        int dif=this->bani.getfrelem(c[op].getelem(i))-c[op].getfrelem(c[op].getelem(i));
        this->bani.setfrelem(c[op].getelem(i),dif);
    }
}
