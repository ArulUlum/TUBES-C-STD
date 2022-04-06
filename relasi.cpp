#include "relasi.h"

void createListR(ListR &L){
    first(L) = NULL;
    last(L) = NULL;
}
adrrel createElmrel(ListR &L, int rat, adrcos C, adrpro P){
    adrrel R = new elmrel;
    info(R).cos = C;
    info(R).pro = P;
    info(R).rating = rat;
    next(R) = NULL;
    prev(R) = NULL;
    return R;
}
void insertFirstR(ListR &L, adrrel P){
    if(first(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
    }else{
        last(L) = P;
    }
    first(L) = P;
}
void insertRating(ListR &L, adrcos C, adrpro P){
    int rat;
    adrrel R;
    cout<<"Masukkan Rating yang anda inginkan"<<endl;
    cout<<"(Tulis 1 - 5)"<<endl;
    cin>>rat;
    while(rat < 1 || rat > 5){
        cout<<"Masukan rating dengan benar"<<endl;
        cin>>rat;
    }
    R = createElmrel(L, rat, C, P);
    insertFirstR(L, R);
    cout<<"Rating telah ditambahkan"<<endl;
}
void viewRatingCustomer(ListR L, string nama){
    adrrel P = first(L);
    cout<<"Nama: "<<nama<<endl;
    cout<<"Produk yang di rate:"<<endl;
    while(P != NULL){
        if(info(info(P).cos).nama == nama){
            cout<<"Produk: "<<info(info(P).pro).barang<<" Rating: "<<info(P).rating<<" Bintang"<<endl;
        }
        P = next(P);
    }
}
void viewRatingProduk(ListR L, string produk){
    adrrel P = first(L);
    int i = 0;
    float temp = 0;
    cout<<"Produk: "<<produk<<endl;
    while(P != NULL){
        if(info(info(P).pro).barang == produk){
            cout<<"Customer: "<<info(info(P).cos).nama<<" Memberikan Rating: "<<info(P).rating<<" Bintang"<<endl;
            temp = temp + info(P).rating;
            i++;
        }
        P = next(P);
    }
    if(i == 0){
        i = 1;
    }
    cout<<"Rata-rata Rating: "<<temp/i<<endl;
}
void belumRate(ListR Lr, ListP Lp, adrcos C){
    adrpro P = first(Lp);
    adrrel R;
    bool counter;
    cout<<"Nama: "<<info(C).nama<<endl;
    cout<<"Produk yang belum di rate:"<<endl;
    while(next(P) != first(Lp)){
        R = first(Lr);
        counter = false;
        while(R != NULL){
            if(info(R).cos == C && info(R).pro == P){
                counter = true;
            }
            R = next(R);
        }
        if(!counter){
            cout<<"Produk: "<<info(P).barang<<endl;
        }
        P = next(P);
    }
    R = first(Lr);
    counter = false;
    while(R != NULL){
        if(info(R).cos == C && info(R).pro == P){
            counter = true;
        }
        R = next(R);
    }
    if(!counter){
        cout<<"Produk: "<<info(P).barang<<endl;
    }
}
float ratarataRating(ListR &L, string produk){
    adrrel P = first(L);
    int i = 0;
    float temp = 0;
    while(P != NULL){
        if(info(info(P).pro).barang == produk){
            temp = temp + info(P).rating;
            i++;
        }
        P = next(P);
    }
    if(i == 0){
        i = 1;
    }
    return temp/i;
}
void insertRatarata(ListR Lr, ListP &Lp){
    adrpro P = first(Lp);
    if(first(Lp) != NULL){
        while(next(P) != first(Lp)){
            info(P).rata2 = ratarataRating(Lr, info(P).barang);
            P = next(P);
        }
        info(P).rata2 = ratarataRating(Lr, info(P).barang);
    }
}
void deleteFirstR(ListR &L, adrrel &P){
    P = first(L);
    if(next(P) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}
void deleteAfterLast(ListR &L, adrrel Q, adrrel &P){
    P = next(Q);
    if(P == last(L)){
        last(L) = Q;
        prev(P) = NULL;
        next(Q) = NULL;
    }else{
        next(Q) = next(P);
        prev(next(Q)) = Q;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteRatingOne(ListR &L, adrcos C, adrpro P){
    adrrel Q = first(L);
    adrrel R;
    if(info(Q).cos == C && info(Q).pro == P){
        deleteFirstR(L, R);
    }else{
        while(info(next(Q)).cos != C || info(next(Q)).pro != P && next(Q) != NULL){
            Q = next(Q);
        }
        deleteAfterLast(L, Q, R);
    }
    cout<<"Rating telah dihapus"<<endl;
}
void deleteRelasiProduk(ListR &L, adrpro P){
    adrrel Q, R;
    adrrel C = first(L);
    while(C != NULL){
        Q = first(L);
        if(info(Q).pro == P){
            deleteFirstR(L, R);
        }else{
            while(info(next(Q)).pro != P && next(Q) != NULL){
                Q = next(Q);
            }
            deleteAfterLast(L, Q, R);
        }
        C = next(C);
    }
}
void deleteRelasiCustomer(ListR &L, adrcos P){
    adrrel Q, R;
    adrrel C = first(L);
    while(C != NULL){
        Q = first(L);
        if(info(Q).cos == P){
            deleteFirstR(L, R);
        }else{
            while(info(next(Q)).cos != P && next(Q) != NULL){
                Q = next(Q);
            }
            deleteAfterLast(L, Q, R);
        }
        C = next(C);
    }
}
void mainMenu(string &menu){
    cout<<"Selamat datang di Program Rating Produk"<<endl;
    cout<<"1. Login Admin"<<endl;
    cout<<"2. Login Customer"<<endl;
    cout<<"3. Non Login User"<<endl;
    cout<<endl;
    cout<<"0. Exit"<<endl;
    cout<<endl;
    cout<<"Masukkan pilihan disini:"<<endl;
    cin>>menu;
}
void backexit(string &menu){
    cout<<"\nany key for Back"<<endl;
    cin>>menu;
}
void menuNonUser(string &menu, bool &counter){
    cout<<"1. Sign Up Customer"<<endl;
    cout<<"2. View Produk"<<endl;
    cout<<endl;
    cout<<"9. Back"<<endl;
    cout<<endl;
    cout<<"Masukkan pilihan disini:"<<endl;
    cin>>menu;
    if(menu == "9"){
        counter = true;
    }
}
