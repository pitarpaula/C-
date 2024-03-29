#include "entitate.h"
#include <iostream>
#include <string.h>


// constructor
Entitate::Entitate(){
    this->parteReala = 0;
    this->parteImag = 0;
}

// constructor cu parametrii
Entitate::Entitate(float r, float i){
    this->parteReala = r;
    this->parteImag = i;
}

// constructor de copiere
Entitate::Entitate(const Entitate &n){
    this->parteReala = n.parteReala;
    this->parteImag = n.parteImag;
}



//getter
int Entitate::getParteReala(){
    return this->parteReala;
}

int Entitate::getParteImag(){
    return this->parteImag;
}

//setter
void Entitate::setParteReala(float r){
    this->parteReala = r;
}

void Entitate::setParteImag(float i){
    this->parteImag = i;
}

ostream& operator<<(ostream& os, Entitate& en)
{
    os<<en.getParteReala()<<"+"<<en.getParteImag()<<"*i"<<endl;
}
