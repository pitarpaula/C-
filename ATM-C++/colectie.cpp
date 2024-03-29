#include <cstring>
#include "colectie.h"

Colectie::Colectie(int cap){
    //cout<<"&\n";
    this -> cap = cap;
    this -> nre = 0;
    this -> b = new bancnota[cap];
    //this -> elem[0] = 1, this -> elem[1] = 5, this -> elem[2] = 10, this -> elem[3] = 20;
    //this -> elem[4] = 50, this -> elem[5] = 100, this -> elem[6] = 200, this -> elem[7] = 500;
    //for(int i=0;i<this->cap;i++)
        //this -> fr[i] = 0;
}

int Colectie::getfrelem(int poz){ ///poz e valoarea bancnotei
    for(int i=0;i<this->nre;i++)
        if( poz == this->b[i].val )
            return this->b[i].frecv;
    return 0;
}

///***************modificare**************
void Colectie::setfrelem(int valb, int frecv){
    for(int i=0;i<this->nre;i++)
        if( valb == this->b[i].val )
            this->b[i].frecv = frecv;
}

Colectie::Colectie(const Colectie &c){
    b = new bancnota[c.cap];
    nre = c.nre;
    for(int i=0; i < c.nre; i++)
        this -> b[i].frecv = c.b[i].frecv, this -> b[i].val = c.b[i].val;
}

int Colectie::getcap(){
    return this->nre;
}

int Colectie::getelem(int poz){
    return this->b[poz].val;
}

void Colectie::adauga(int elem){
    int poz=-1,i=0;
    while(poz==-1 && i<this->cap){
        if(this->b[i].val==elem)
            poz=i;
        i++;
    }
    //cout<<poz<<endl;
    if(poz!=-1)
        this->b[poz].frecv++;
    else{
        //if(nre == cap) resize();
        this->b[nre].val = elem;
        this->b[nre].frecv = 1;
        this->nre++;
    }
}

bool Colectie::sterge(int elem){
    int poz=-1,i=0;
    while(poz==-1 && i<this->cap){
        if(this->b[i].val==elem)
            poz=i;
        i++;
    }
    if(poz!=-1)
        if(this->b[poz].frecv>0){
            this->b[poz].frecv--;
            return true;
        }
        else{
            for(int i=poz;i<nre-1;i++)
                this->b[i].frecv=this->b[i+1].frecv,this->b[i].val=this->b[i+1].val;
            nre--;
        }
    //else exceptie 2 cazuri
          // cazul 1. nu exista tipul bancnota
          // cazul 2. bancnota a fost deja stearsa din vector
  return false;
}

Colectie& Colectie::operator=(const Colectie &c){
    if(this->nre>0)
        delete[] b, b=new bancnota[c.cap];
    nre = c.nre;
    for(int i=0; i < this->nre; i++)
        this -> b[i].frecv = c.b[i].frecv, this -> b[i].val = c.b[i].val;
    return *this;
}

ostream& operator<<(ostream &os, const Colectie &c){
    //os << "Exista un numar de " << c.cap << " bancnote.\n";
    for(int i=0;i<c.cap;i++)
        if(c.b[i].frecv>0 && c.b[i].val>0)
            os << "pentru bancnota " << c.b[i].val << " exista " << c.b[i].frecv << " exemplare\n";
    return os;
}

