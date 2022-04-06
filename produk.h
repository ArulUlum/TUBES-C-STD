#ifndef PRODUK_H_INCLUDED
#define PRODUK_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;      //cirkular single
struct infopro{
    string barang;
    float rata2;
};
typedef struct elmpro *adrpro;
struct elmpro {
    infopro info;
    adrpro next;
};
struct ListP {
    adrpro first;
};

void createListP(ListP &L);
adrpro createElmpro(ListP &L, string produk, float rata2);
void insertLastP(ListP &L, adrpro P);
void createProduk(ListP &L);
void viewProduk(ListP L);
void viewProdukA(ListP L);
adrpro searchProduk(ListP &L, string produk);
adrpro pilihProduk(ListP L);
void pilihProdukN(ListP L, string &produk, string menu);
void deleteAfterP(ListP &L, adrpro Q, adrpro &P);
adrpro cariQproduk(ListP L, string cari);
void deleteproduk(ListP &L, adrpro &P);
void editProduk(ListP &L, string produk);
void sortingProduk(ListP &L);
void menuAdmin(string &menu, bool &counter);

#endif // PRODUK_H_INCLUDED
