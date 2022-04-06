#include "customer.h"

void createListC(ListC &L){
    first(L) = NULL;
}
void insertFirstC(ListC &L, adrcos P){
    adrcos akhir = first(L);
    while(next(akhir) != first(L)){
        akhir = next(akhir);
    }
    next(P) = first(L);
    first(L) = P;
    next(akhir) = first(L);
}
void insertAfterC(adrcos Q, adrcos P){
    next(P) = next(Q);
    next(Q) = P;
}
void insertCustomer(ListC &L, adrcos P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrcos Q = first(L);
        if(info(P).username < info(Q).username){
            insertFirstC(L, P);
        } else {
            if(next(Q) != Q){
                while(info(P).username > info(next(Q)).username){
                    Q = next(Q);
                }
            }
            insertAfterC(Q, P);
        }
    }
}
void unik(string &username){
    int angka = 0;
    int hurufk = 0;
    int hurufb = 0;
    int panjang = 0;
    int counter;
    cout<<"Masukan Username anda (username harus unik)"<<endl;
    cout<<"(Minimal 6 karakter    Memiliki angka     Memilikii huruf kecil     Meminiki huruf besar)"<<endl;
    while(angka == 0 || hurufk == 0 || hurufb == 0 || panjang < 6){
        cout<<"Username: ";
        cin>>username;
        panjang = username.length();
        counter = 0;
        angka = 0;
		hurufk = 0;
		hurufb = 0;
		while(counter < panjang){
            if(username[counter] == '1' || username[counter] == '2' || username[counter] == '3' || username[counter] == '4' ||
               username[counter] == '5' || username[counter] == '6' || username[counter] == '7' || username[counter] == '8' ||
               username[counter] == '9' || username[counter] == '0'){
                angka++;
            }
            if(username[counter] == 'a' || username[counter] == 'b' || username[counter] == 'c' || username[counter] == 'd' ||
               username[counter] == 'e' || username[counter] == 'f' || username[counter] == 'g' || username[counter] == 'h' ||
               username[counter] == 'i' || username[counter] == 'j' || username[counter] == 'k' || username[counter] == 'l' ||
               username[counter] == 'm' || username[counter] == 'n' || username[counter] == 'o' || username[counter] == 'p' ||
               username[counter] == 'q' || username[counter] == 'r' || username[counter] == 's' || username[counter] == 't' ||
               username[counter] == 'u' || username[counter] == 'v' || username[counter] == 'w' || username[counter] == 'x' ||
               username[counter] == 'y' || username[counter] == 'z'){
                hurufk++;
            }
            if(username[counter] == 'A' || username[counter] == 'B' || username[counter] == 'C' || username[counter] == 'D' ||
               username[counter] == 'E' || username[counter] == 'F' || username[counter] == 'G' || username[counter] == 'H' ||
               username[counter] == 'I' || username[counter] == 'J' || username[counter] == 'K' || username[counter] == 'L' ||
               username[counter] == 'M' || username[counter] == 'N' || username[counter] == 'O' || username[counter] == 'P' ||
               username[counter] == 'Q' || username[counter] == 'R' || username[counter] == 'S' || username[counter] == 'T' ||
               username[counter] == 'U' || username[counter] == 'V' || username[counter] == 'W' || username[counter] == 'X' ||
               username[counter] == 'Y' || username[counter] == 'Z'){
                hurufb++;
            }
            counter++;
		}
		if(panjang < 6){
            cout<<"Username minimal 6 karakter"<<endl;
		} else if(hurufb == 0){
            cout<<"Username harus ada huruf besar"<<endl;
		} else if(angka == 0){
            cout<<"Username harus angka"<<endl;
		} else if(hurufk == 0){
            cout<<"Username harus ada huruf kecil"<<endl;
		}
    }
}
adrcos createElmcos(ListC &L, string nama, string username){
    adrcos P = new elmcos;
    info(P).nama = nama;
    info(P).username = username;
    next(P) = P;
    return P;
}
void createCustomer(ListC &L){
    string nama, username;
    adrcos P;
    cout<<"Buat akun costumer"<<endl;
    cout<<"Masukkan nama anda: ";
    cin>>nama;
    unik(username);
    P = createElmcos(L, nama, username);
    insertCustomer(L, P);
    cout<<"Akun anda telah dibuat"<<endl;
}
void viewcustomer(ListC L){
    if(first(L) == NULL){
        cout<<"Maaf belum ada Customer yang terdaftar"<<endl;
    } else {
        adrcos P = first(L);
        cout<<"Daftar Customer: "<<endl;
        while(next(P) != first(L)){
            cout<<info(P).nama<<endl;
            P = next(P);
        }
        cout<<info(P).nama<<endl;
    }
}
void viewcustomerA(ListC L){
    if(first(L) == NULL){
        cout<<"Maaf belum ada Customer yang terdaftar"<<endl;
    } else {
        adrcos P = first(L);
        cout<<"Daftar Customer: "<<endl;
        while(next(P) != first(L)){
            cout<<"Nama: "<<info(P).nama<<" Username: "<<info(P).username<<endl;
            P = next(P);
        }
        cout<<"Nama: "<<info(P).nama<<" Username: "<<info(P).username<<endl;
    }
}
void deleteAfterC(ListC &L, adrcos Q, adrcos &P){
    P = next(Q);
    next(Q) = next(P);
    if(P == first(L)){
        first(L) = next(P);
    }
    next(P) = NULL;
}
adrcos cariQcustomer(ListC L, string cari){
    adrcos Q = first(L);
    while(info(next(Q)).nama != cari && next(Q) != first(L)){
        Q = next(Q);
    }
    if(info(next(Q)).nama == cari){
        return Q;
    } else {
        return NULL;
    }
}
void deletecustomer(ListC &L, adrcos P){
    adrcos Q;
    string cari;
    if(first(L) != NULL){
        cout<<"\nCari nama yang ingin di hapus"<<endl;
        cin>>cari;
        while(cariQcustomer(L, cari) == NULL){
            cout<<"Nama customer tidak ada, silahkan coba lagi"<<endl;
            cin>>cari;
        }
        Q = cariQcustomer(L, cari);
        if(next(Q) == Q){
            P = Q;
            first(L) = NULL;
        } else {
            deleteAfterC(L, Q, P);
        }
        cout<<"Customer telah dihapus"<<endl;
    }
}
adrcos searchUsername(ListC L, string username){
    if(first(L) != NULL){
        adrcos P = next(first(L));
        while(info(P).username != username && P != first(L)){
            P = next(P);
        }
        if(info(P).username == username){
            return P;
        } else {
            return NULL;
        }
    }
}
void loginCustomer(ListC L, string &username, bool &counter, adrcos &P){
    P = NULL;
    cout<<"Silahkan Login terlebih dahulu"<<endl;
    cout<<"(Jika belum punya akun silahkan kembali ke menu dan daftar di menu ke-3)\n"<<endl;
    cout<<"Ketik '9' untuk kembali ke manu awal\n"<<endl;
    cout<<"Masukkan Username: ";
    cin>>username;
    while(searchUsername(L, username) == NULL && username != "9"){
        cout<<"Username salah silahkan coba lagi:"<<endl;
        cin>>username;
    }
    P = searchUsername(L, username);
    if(username == "9"){
        counter = true;
    }
}
adrcos searchNama(ListC L, string nama){
    if(first(L) != NULL){
        adrcos P = next(first(L));
        while(info(P).nama != nama && P != first(L)){
            P = next(P);
        }
        if(info(P).nama == nama){
            return P;
        } else {
            return NULL;
        }
    }
}
void pilihCustomer(ListC L, string &nama){
    adrcos C;
    cout<<"\nTulis nama Customer yang ingin dilihat"<<endl;
    cin>>nama;
    while(searchNama(L, nama) == NULL){
        cout<<"Masukkan nama Customer dengan benar"<<endl;
        cin>>nama;
    }
}
void editCustomer(ListC &L, adrcos &P){
    string edit;
    cout<<"Apakah anda ingin mengganti nama?(ketik 'iya' untuk mengganti nama)"<<endl;
    cin>>edit;
    if(edit == "iya"){
        cout<<"Nama lama anda: "<<info(P).nama<<endl;
        cout<<"Masukkan nama baru anda: ";
        cin>>info(P).nama;
        cout<<"\nNama telah diperbaharui"<<endl;
    }
    cout<<"\nApakah anda ingin mengganti Username?(ketik 'iya' untuk mengganti Username)"<<endl;
    cin>>edit;
    if(edit == "iya"){
        cout<<"Username lama anda: "<<info(P).username<<endl;
        cout<<"Masukkan Username baru anda"<<endl;
        unik(info(P).username);
        cout<<"\nUsername telah diperbaharui"<<endl;
    }
}
void menuCustomer(adrcos P, string &menu, bool &counter){
    if(P != NULL){
        cout<<"Selamat anda berhasil Login"<<endl;
        cout<<"Nama: "<<info(P).nama<<"\n"<<endl;
        cout<<"1. Beri Rating ke Produk"<<endl;
        cout<<"2. Hapus Rating"<<endl;
        cout<<"3. Daftar Produk yang pernah dirating"<<endl;
        cout<<"4. Daftar Produk yang belum dirating     (belum tersedia)"<<endl;
        cout<<"5. Edit akun\n"<<endl;
        cout<<"9. Log Out\n"<<endl;
        cout<<"Masukkan pilihan disini:"<<endl;
        cin>>menu;
        if(menu == "9"){
            counter = true;
        }
    }
}
