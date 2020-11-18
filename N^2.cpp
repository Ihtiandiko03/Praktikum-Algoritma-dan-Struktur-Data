// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 6 November 2020
// Deskripsi : Soal ke 2

#include<iostream>
#include<math.h>
using namespace std;

int rekursif (int a, int b){
    if(a>0){
        return b + rekursif(a-1, b+2);
    }
    else{
        return 0;
    }
}

int main(){
    int z,hehe,x,y=1;
    cin>>x;
    int akar=sqrt(x);
    hehe=rekursif(akar,y);
    z=pow((akar-1),2);
    hehe-=z;

    for(int i=0; i<akar; i++){
        if(y==hehe){
            cout<<y<<" = "<<akar<<"^"<<2;
        }
        else{
            cout<<y<<"+";
        }
        y+=2;
    }

}
