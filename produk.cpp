#include "produk.h"

void createListP(ListP &L){
    first(L) = NULL;
}
adrpro createElmpro(ListP &L, string produk, float rata2){
    adrpro P = new elmpro;
    info(P).barang = produk;
    info(P).rata2 = rata2;
    next(P) = P;
    return P;
}
void insertLastP(ListP &L, adrpro P){
    adrpro akhir = first(L);
    while(next(akhir) != first(L)){
        akhir = next(akhir);
    }
    next(akhir) = P;
    next(P) = first(L);
}
void createProduk(ListP &L){
    string barang;
    float rata2 = 0;
    adrpro P;
    cout<<"Masukkan nama prooduk: ";
    cin>>barang;
    P = createElmpro(L, barang, rata2);
    if(first(L) == NULL){
        first(L) = P;
    } else {
        insertLastP(L, P);
    }
    cout<<"Produk Telah Dibuat"<<endl;
}
void viewProduk(ListP L){
    if(first(L) == NULL){
        cout<<"Maaf Produk belum tersedia"<<endl;
    } else {
        adrpro P = first(L);
        cout<<"Daftar Produk: "<<endl;
        while(next(P) != first(L)){
            cout<<info(P).barang<<endl;
            P = next(P);
        }
        cout<<info(P).barang<<endl;
    }
}
void viewProdukA(ListP L){
    if(first(L) == NULL){
        cout<<"Maaf Produk belum tersedia"<<endl;
    } else {
        adrpro P = first(L);
        cout<<"Daftar Produk: "<<endl;
        while(next(P) != first(L)){
            cout<<info(P).barang<<"         Rata-rata Rating: "<<info(P).rata2<<endl;
            P = next(P);
        }
        cout<<info(P).barang<<"         Rata-rata Rating: "<<info(P).rata2<<endl;
    }
}
adrpro searchProduk(ListP &L, string produk){
    if(first(L) != NULL){
        adrpro P = next(first(L));
        while(info(P).barang != produk && P != first(L)){
            P = next(P);
        }
        if(info(P).barang == produk){
            return P;
        } else {
            return NULL;
        }
    }
}
adrpro pilihProduk(ListP L){
    adrpro P;
    string produk;
    cout<<"\nTulis nama produk yang ingin di rating"<<endl;
    cin>>produk;
    while(searchProduk(L, produk) == NULL){
        cout<<"Tulis nama produk dengan benar"<<endl;
        cin>>produk;
    }
    P = searchProduk(L, produk);
    return P;
}
void pilihProdukN(ListP L, string &produk, string menu){
    if(menu == "3"){
        cout<<"\nTulis nama produk yang ingin diedit"<<endl;
    }else if(menu == "7"){
        cout<<"\nTulis nama produk yang ingin dilihat"<<endl;
    }
    cin>>produk;
    while(searchProduk(L, produk) == NULL){
        cout<<"Tulis nama produk dengan benar"<<endl;
        cin>>produk;
    }
}
void deleteAfterP(ListP &L, adrpro Q, adrpro &P){
    P = next(Q);
    next(Q) = next(P);
    if(P == first(L)){
        first(L) = next(P);
    }
    next(P) = NULL;
}
adrpro cariQproduk(ListP L, string cari){
    adrpro Q = first(L);
    while(info(next(Q)).barang != cari && next(Q) != first(L)){
        Q = next(Q);
    }
    if(info(next(Q)).barang == cari){
        return Q;
    } else {
        return NULL;
    }
}
void deleteproduk(ListP &L, adrpro &P){
    adrpro Q;
    string cari;
    if(first(L) != NULL){
        cout<<"\nCari produk yang ingin di hapus"<<endl;
        cin>>cari;
        while(cariQproduk(L, cari) == NULL){
            cout<<"Nama produk tidak ada, silahkan coba lagi"<<endl;
            cin>>cari;
        }
        Q = cariQproduk(L, cari);
        if(next(Q) == Q){
            P = Q;
            first(L) = NULL;
        } else {
            deleteAfterP(L, Q, P);
        }
        cout<<"Produk telah dihapus"<<endl;
    }
}
void editProduk(ListP &L, string produk){
    adrpro P;
    P = searchProduk(L, produk);
    cout<<"Nama lama produk: "<<info(P).barang<<endl;
    cout<<"Masukkan nama baru produk: ";
    cin>>info(P).barang;
    cout<<"\nProduk telah diperbaharui"<<endl;
}
void sortingProduk(ListP &L){
    infopro temp;
    adrpro P1, P2, big;
    if(first(L) != NULL){
        P1 = first(L);
        while(next(P1) != first(L)){
            P2 = P1;
            big = P1;
            while(next(P2) != first(L)){
                if(info(P2).rata2 > info(big).rata2){
                    big = P2;
                }
                P2 = next(P2);
            }
            if(info(P2).rata2 > info(big).rata2){
                big = P2;
            }
            if(info(P1).rata2 < info(big).rata2){
                temp = info(P1);
                info(P1) = info(big);
                info(big) = temp;
            }
            P1 = next(P1);
        }
    }
}
void menuAdmin(string &menu, bool &counter){
    cout<<"Selamat datang di menu Admin\n"<<endl;
    cout<<"1. Tambah data Produk"<<endl;
    cout<<"2. Lihat data Produk"<<endl;
    cout<<"3. Edit data Produk"<<endl;
    cout<<"4. Hapus data Produk"<<endl;
    cout<<"5. Lihat data Customer"<<endl;
    cout<<"6. Hapus data Customer"<<endl;
    cout<<"7. Lihat Rating Produk"<<endl;
    cout<<"8. Lihat Rating Customer\n"<<endl;
    cout<<"9. Back\n"<<endl;
    cout<<"Masukkan pilihan disini:"<<endl;
    cin>>menu;
    if(menu == "9"){
        counter = true;
    }
}
