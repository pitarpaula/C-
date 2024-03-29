#ifndef REPO_H_INCLUDED
#define REPO_H_INCLUDED

#include "entitate.h"
#include <vector>
using namespace std;

class Repo{
private:
    vector<Entitate> e;
public:
    Repo();
    ~Repo();
    int get_size();
    void addItem(Entitate &en);
    void afis_repo();
    void afis_pb(int k);
    void maxim();
    void cadr1();
    void afis_sec(int p, int d);
    void secLung();
    void meniu();
};

#endif // REPO_H_INCLUDED
