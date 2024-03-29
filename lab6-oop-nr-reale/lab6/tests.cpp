#include "tests.h"
#include "assert.h"
#include "repo.h"
#include <iostream>
using namespace std;

void testMaximRepo()
{
    Entitate e1(2,3);
    Entitate e2(-1,-2);
    Entitate e3(4,1);
    Entitate e4(-4,3);
    Repo repo;
    repo.addItem(e1);
    repo.addItem(e2);
    repo.addItem(e3);
    repo.addItem(e4);
    Entitate en[4];
    int maxim=0;
    repo.maxim();
    assert(maxim==5);
}

void testCadr1Repo()
{
    Entitate e1(2,3);
    Entitate e2(-1,-2);
    Entitate e3(4,1);
    Entitate e4(-4,3);
    Repo repo;
    repo.addItem(e1);
    repo.addItem(e2);
    repo.addItem(e3);
    repo.addItem(e4);
    Entitate en[4];
    int nr=0;
    repo.cadr1();
    assert(nr==2);
}

void testSecLungRepo()
{
    Entitate e1(2,2);
    Entitate e2(2,2);
    Entitate e3(-1,1);
    Entitate e4(3,3);
    Entitate e5(3,3);
    Entitate e6(3,3);
    Repo repo;
    repo.addItem(e1);
    repo.addItem(e2);
    repo.addItem(e3);
    repo.addItem(e4);
    repo.addItem(e5);
    repo.addItem(e6);
    Entitate en[6];
    int maxim=0;
    repo.secLung();
    assert(maxim==3);
}

void myTests()
{
    void testMaximRepo();
    void testCadr1Repo();
    void testSecLungRepo();
}
