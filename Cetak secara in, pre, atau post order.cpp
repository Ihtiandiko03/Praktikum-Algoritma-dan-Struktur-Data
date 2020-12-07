// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 4 Desember 2020
// Deskripsi : Problem 1

#include<iostream>
#include<cstdlib>
using namespace std;

typedef int infotype;
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


void InOrder(address akar){
	if (akar == NULL) return;
		InOrder(akar->kiri);
		cout<<akar->data<<" ";
		InOrder(akar->kanan);
}

void PreOrder(address akar){
	if (akar == NULL) return;
		cout<<akar->data<<" ";
		PreOrder(akar->kiri);
		PreOrder(akar->kanan);
}

void PostOrder(address akar){
	if (akar == NULL) return;
		PostOrder(akar->kiri);
		PostOrder(akar->kanan);
		cout<<akar->data<<" ";
}

bool cari(address akar, infotype data){
	if (akar==NULL) {
		return false;
	}else if(akar->data==data){
		return true;
	}else if(data>=akar->data){
		return cari(akar->kanan, data);
	}else{
		return cari(akar->kiri, data);
	}
}

address insert(address akar, infotype data){
	if(akar==NULL){
		akar=allocation(data);
	} else if(data <= akar->data ){
		akar->kiri = insert(akar->kiri, data);
	} else{
		akar->kanan = insert(akar->kanan, data);
	}
	return akar;
}


int main(){
	address akar = NULL;
	int n, x, i, j;
	cin >> n;

	for(i=0; i<n; i++){
        cin >> x;
        if(cari(akar,x)!= 1)
        akar=insert(akar,x);
    }
    cin >> j;
    if(j == 1){
    	PreOrder(akar);
	}else if(j == 2){
		InOrder(akar);
	}else if(j == 3){
		PostOrder(akar);
	}
}
