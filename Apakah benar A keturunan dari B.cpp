// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 4 Desember 2020
// Deskripsi : Problem 2

#include<iostream>
#include<cstdlib>
using namespace std;

typedef char infotype;
typedef struct TElmt *address;
typedef struct TElmt{
    infotype data;
    address kanan;
    address kiri;
} Elmt;

address allocation(infotype x){
    address newElmt = new Elmt();
    newElmt->data = x;
    newElmt->kiri=newElmt->kanan=NULL;

    return newElmt;
}
bool cari(address akar, infotype data){
    if (akar==NULL)
        return false;
    else if(akar->data==data)
        return true;
    else if(data>=akar->data)
        return cari(akar->kanan,data);
    else
        return cari(akar->kiri,data);
}
address masuk(address akar,infotype data){
    if(akar==NULL){
        akar=allocation(data);
    } else if(data<=akar->data){
        akar->kiri=masuk(akar->kiri,data);
    } else{
        akar->kanan=masuk(akar->kanan,data);
    }
    return akar;
}
int main(){
    address akar = NULL;
    char x,y,a,b,i;
    int n;
    cin>>n;

    for(i=0; i<n; i++){
        cin>>x>>y;
        if(cari(akar,x)!=1){
        	akar=masuk(akar,x);
		}
        if(cari(akar,y)!=1){
        	akar=masuk(akar,y);
		}
    }
    cin>>a>>b;
    if(cari(akar,a) == 1){
    	if(cari(akar,b) == 1){
        		cout <<"true";
			}
		}else if(cari(akar,b) == 1){
        	if(cari(akar,a) == 0){
        		cout <<"false";
			}
    	}

    }
