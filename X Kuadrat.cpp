// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 6 November 2020
// Deskripsi : Soal ke 1

#include<iostream>
using namespace std;

int pangkat(int *a,int b){
    if(b>0){
        return (*a * pangkat(a,b-1));
    }else{
        return 1;
    }
}

int main() {
    int x,y;
    cin>>x>>y;
    cout<<pangkat(&x,y);
    return 0;
}
