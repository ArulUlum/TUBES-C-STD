#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include "customer.h"
#include "produk.h"
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
using namespace std;    //double link list

typedef struct elmrel *adrrel;
struct inforel{
    int rating;
    adrcos cos;
    adrpro pro;
};
struct elmrel {
    inforel info;
    adrrel next;
    adrrel prev;
};
struct ListR {
    adrrel first;
    adrrel last;
};

void createListR(ListR &L);
adrrel createElmrel(ListR &L, int rat, adrcos C, adrpro P);
void insertFirstR(ListR &L, adrrel P);
void insertRating(ListR &L, adrcos C, adrpro P);
void viewRatingCustomer(ListR L, string nama);
void viewRatingProduk(ListR L, string produk);
void belumRate(ListR Lr, ListP Lp, adrcos C);
float ratarataRating(ListR &L, string produk);
void insertRatarata(ListR Lr, ListP &Lp);
void deleteFirstR(ListR &L, adrrel &P);
void deleteAfterLast(ListR &L, adrrel Q, adrrel &P);
void deleteRatingOne(ListR &L, adrcos C, adrpro P);
void deleteRelasiProduk(ListR &L, adrpro P);
void deleteRelasiCustomer(ListR &L, adrcos P);
void mainMenu(string &menu);
void backexit(string &menu);
void menuNonUser(string &menu, bool &counter);

#endif // RELASI_H_INCLUDED
