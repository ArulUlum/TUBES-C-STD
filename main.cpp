#include "customer.h"
#include "produk.h"
#include "relasi.h"

int main()
{
    ListC Lc;
    ListP Lp;
    ListR Lr;
    adrcos C;
    adrpro P;
    adrrel R;
    string username, nama, produk, menu, menu1, menu2;
    bool finish = false;
    bool counter;
    createListC(Lc);
    createListP(Lp);
    createListR(Lr);
    while(!finish){
        counter = false;
        mainMenu(menu);
        if(menu == "1"){
            while(!counter){
                if (system("CLS")) system("clear");
                menuAdmin(menu1, counter);
                if(menu1 == "1"){
                    if (system("CLS")) system("clear");
                    createProduk(Lp);
                    backexit(menu2);
                }
                if(menu1 == "2"){
                    if (system("CLS")) system("clear");
                    insertRatarata(Lr, Lp);
                    viewProdukA(Lp);
                    backexit(menu2);
                }
                if(menu1 == "3"){
                    if (system("CLS")) system("clear");
                    viewProduk(Lp);
                    if(first(Lp) != NULL){
                        pilihProdukN(Lp, produk, menu1);
                        if (system("CLS")) system("clear");
                        editProduk(Lp, produk);
                    }
                    backexit(menu2);
                }
                if(menu1 == "4"){
                    if (system("CLS")) system("clear");
                    viewProduk(Lp);
                    deleteproduk(Lp, P);
                    deleteRelasiProduk(Lr, P);
                    backexit(menu2);
                }
                if(menu1 == "5"){
                    if (system("CLS")) system("clear");
                    viewcustomerA(Lc);
                    backexit(menu2);
                }
                if(menu1 == "6"){
                    if (system("CLS")) system("clear");
                    viewcustomer(Lc);
                    deletecustomer(Lc, C);
                    deleteRelasiCustomer(Lr, C);
                    backexit(menu2);
                }
                if(menu1 == "7"){
                    if (system("CLS")) system("clear");
                    viewProduk(Lp);
                    if(first(Lp) != NULL){
                        pilihProdukN(Lp, produk, menu1);
                        if (system("CLS")) system("clear");
                        viewRatingProduk(Lr, produk);
                    }
                    backexit(menu2);
                }
                if(menu1 == "8"){
                    if (system("CLS")) system("clear");
                    viewcustomer(Lc);
                    if(first(Lc) != NULL){
                        pilihCustomer(Lc, nama);
                        if (system("CLS")) system("clear");
                        viewRatingCustomer(Lr, nama);
                    }
                    backexit(menu2);
                }
            }
        }
        if(menu == "2"){
            if (system("CLS")) system("clear");
            loginCustomer(Lc, username, counter, C);
            while(!counter){
                if (system("CLS")) system("clear");
                menuCustomer(C, menu1, counter);
                if(menu1 == "1"){
                    if (system("CLS")) system("clear");
                    viewProduk(Lp);
                    if(first(Lp) != NULL){
                        P = pilihProduk(Lp);
                        insertRating(Lr, C, P);
                    }
                    backexit(menu2);
                }
                if(menu1 == "2"){
                    if (system("CLS")) system("clear");
                    viewProduk(Lp);
                    if(first(Lp) != NULL){
                        P = pilihProduk(Lp);
                        deleteRatingOne(Lr, C, P);
                    }
                    backexit(menu2);
                }
                if(menu1 == "3"){
                    if (system("CLS")) system("clear");
                    viewRatingCustomer(Lr, info(C).nama);
                    backexit(menu2);
                }
                if(menu1 == "4"){
                    if (system("CLS")) system("clear");
                    belumRate(Lr, Lp, C);
                    backexit(menu2);
                }
                if(menu1 == "5"){
                    if (system("CLS")) system("clear");
                    editCustomer(Lc, C);
                    backexit(menu2);
                }
            }
        }
        if(menu == "3"){
            while(!counter){
                if (system("CLS")) system("clear");
                menuNonUser(menu1, counter);
                if(menu1 == "1"){
                    if (system("CLS")) system("clear");
                    createCustomer(Lc);
                    backexit(menu2);
                    counter = true;
                }
                if(menu1 == "2"){
                    if (system("CLS")) system("clear");
                    insertRatarata(Lr, Lp);
                    sortingProduk(Lp);
                    viewProdukA(Lp);
                    backexit(menu2);
                    counter = true;
                }
            }
        }
        if(menu == "0"){
            finish = true;
        }
        if (system("CLS")) system("clear");
    }
    return 0;
}
