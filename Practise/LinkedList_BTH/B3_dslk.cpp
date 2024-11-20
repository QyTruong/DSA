#include<iostream>

using namespace std;

struct Dathuc {
    int bac;
    double* heso;
};

void nhapDaThuc(Dathuc &dt){
    do {
        cout << "Nhap so bac cua da thuc: ";
        cin >> dt.bac;
        if (dt.bac <= 0)
            cout << "Vui long nhap lai!!\n";
    } while (dt.bac <= 0);

    dt.heso = new double[dt.bac+1];
    for (int i = 0; i <= dt.bac; i++){
        cout << "He so a" << i << ": ";
        cin >> dt.heso[i]; 
    }
}

void xuatDaThuc(Dathuc dt){
    for (int i = dt.bac; i >= 0; i--){
        if (dt.heso[i] > 0 && i < dt.bac) {
            cout << "+" << dt.heso[i];
        }
        else 
            cout << dt.heso[i];
        if (i > 1)
            cout << "x^" << i;
        else if (i == 1)
            cout << "x";   
    }
    cout << endl;
}

Dathuc congDaThuc(Dathuc dt1, Dathuc dt2){
    Dathuc dtTong;
    dtTong.bac = dt1.bac > dt2.bac ? dt1.bac : dt2.bac;
    dtTong.heso = new double[dtTong.bac+1];
    for (int i = 0; i <= dtTong.bac; i++){
        dtTong.heso[i] = dt1.heso[i] + dt2.heso[i];
    }
    return dtTong;
}

Dathuc truDaThuc(Dathuc dt1, Dathuc dt2){
    Dathuc dtTong;
    dtTong.bac = dt1.bac > dt2.bac ? dt1.bac : dt2.bac;
    dtTong.heso = new double[dtTong.bac+1];
    for (int i = 0; i <= dtTong.bac; i++){
        dtTong.heso[i] = dt1.heso[i] - dt2.heso[i];
    }
    return dtTong;
}

int main(){
    Dathuc dt1;
    Dathuc dt2;
    nhapDaThuc(dt1);
    nhapDaThuc(dt2);
    cout << "Da thuc 1: "; xuatDaThuc(dt1);
    cout << "Da thuc 2: "; xuatDaThuc(dt2);

    Dathuc tongDaThuc = congDaThuc(dt1,dt2);
    cout << "Tong da thuc: "; xuatDaThuc(tongDaThuc);

    Dathuc hieuDaThuc = truDaThuc(dt1, dt2);
    cout << "Hieu da thuc: "; xuatDaThuc(hieuDaThuc);


    delete dt1.heso;
    return 0;
}