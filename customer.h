#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;    //cirkular single
struct infocos{
    string username;
    string nama;
};
typedef struct elmcos *adrcos;
struct elmcos {
    infocos info;
    adrcos next;
};
struct ListC {
    adrcos first;
};

void createListC(ListC &L);
void insertFirstC(ListC &L, adrcos P);
void insertAfterC(adrcos Q, adrcos P);
void insertCustomer(ListC &L, adrcos P);
void unik(string &username);
adrcos createElmcos(ListC &L, string nama, string username);
void createCustomer(ListC &L);
void viewcustomer(ListC L);
void viewcustomerA(ListC L);
void deleteAfterC(ListC &L, adrcos Q, adrcos &P);
adrcos cariQcustomer(ListC L, string cari);
void deletecustomer(ListC &L, adrcos P);
adrcos searchUsername(ListC L, string username);
void loginCustomer(ListC L, string &username, bool &counter, adrcos &P);
adrcos searchNama(ListC L, string nama);
void pilihCustomer(ListC L, string &nama);
void editCustomer(ListC &L, adrcos &P);
void menuCustomer(adrcos P, string &menu, bool &counter);

#endif // CUSTOMER_H_INCLUDED
