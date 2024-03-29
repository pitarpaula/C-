#include "repo.h"
#include <cmath>

Repo::Repo()
{
    this->e.reserve(10);
}

Repo::~Repo()
{
    this->e.clear();
}

int Repo::get_size()
{
    return (int)this->e.size();
}

void Repo::addItem(Entitate &en)
{
    this->e.push_back(en);
}

void Repo::afis_repo()
{
    int x=get_size();
    for(int i=0;i<x;i++)
        cout<<e[i];
}

void Repo::afis_pb(int k)
{
    cout<<e[k];
}

void Repo::maxim()
{
    float maxim=0,modul;
    int k;
    int x=get_size();
    for(int i=0;i<x;i++)
    {
        modul=sqrt(e[i].getParteReala()*e[i].getParteReala()+e[i].getParteImag()*e[i].getParteImag());
        if(modul>maxim)
        {
            maxim=modul;
            k=i;
        }
    }
    if(maxim!=0) afis_pb(k);
}

void Repo::cadr1()
{
    int k=0;
    int x=get_size();
    for(int i=0;i<x;i++)
    {
        if(e[i].getParteReala()>=0 && e[i].getParteImag()>=0)
        {
            afis_pb(i);
            k++;
        }
    }
}

void Repo::afis_sec(int p, int d)
{
    for(int i=p;i<=d;i++)
        cout<<e[i];
}

void Repo::secLung()
{
    int p=0,d=0,maxim=0,nr=1,k,l;
    int x=get_size();
    for(int i=0;i<x;i++)
    {
        if(i==0)
        {
            if(e[i].getParteReala()==e[i+1].getParteReala() && e[i].getParteImag()==e[i+1].getParteImag())
            {
                nr++;
                p=i;
                d=i+1;
            }
            else
            {
                p=i+1;
                nr=1;
            }
        }
        else
        {
            if(e[i].getParteReala()==e[i+1].getParteReala() && e[i].getParteImag()==e[i+1].getParteImag())
            {
                nr++;
                d=i+1;
            }
            else
            {
                if(nr>maxim)
                {
                    maxim=nr;
                    k=p;
                    l=d;
                    p=i+1;
                    nr=1;
                }
                else
                {
                    p=i+1;
                    nr=1;
                }
            }
        }
    }
    if(maxim!=0) afis_sec(k,l);
}

void print_meniu()
{
    cout<<"1. Adauga un nr complex."<<endl;
    cout<<"2. Afiseaza nr-le complexe."<<endl;
    cout<<"3. Afisarea celui mai mare nr complex."<<endl;
    cout<<"4. Afisarea nr-lor complexe care se afla in cadranul 1."<<endl;
    cout<<"5. Afisarea celei mai lungi secvente de nr complexe egale."<<endl;
    cout<<"   Inchiderea aplicatiei."<<endl<<endl;
}

void Repo::meniu()
{
    float a,b;
    bool ok=1;
    while(ok==1)
    {
        print_meniu();
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<"Dati partea reala a numarului complex: "<<endl;
            cin>>a;
            cout<<"Dati partea imaginara a numarului complex: "<<endl;
            cin>>b;
            cout<<endl;
            Entitate en(a,b);
            addItem(en);
        }
        else
        {
            if(op==2)
            {
                cout<<endl<<"Numerele complexe sunt: "<<endl;
                afis_repo();
                cout<<endl;
            }
            else
            {
                if(op==3)
                {
                    cout<<endl<<"Numarul complex este: "<<endl;
                    maxim();
                    cout<<endl;
                }
                else
                {
                    if(op==4)
                    {
                        cout<<endl<<"Numerele complexe sunt: "<<endl;
                        cadr1();
                        cout<<endl;
                    }
                    else
                    {
                        if(op==5)
                        {
                            cout<<endl<<"Numerele complexe sunt: "<<endl;
                            secLung();
                            cout<<endl;
                        }
                        else
                        {
                            ok=0;
                            cout<<"Aplicatie inchisa.";
                        }
                    }
                }
            }
        }
    }
}
