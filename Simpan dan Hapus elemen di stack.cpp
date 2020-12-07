//NIM : 119140118
//NAMA: Ihtiandiko Wicaksono
//TANGGAL : 27-11-2020
//DESKRIPSI: Simpan dan Hapus elemen di stack

#include<iostream>
using namespace std;

#define Nil 0
#define MaxEl 1000

typedef int infotype;
typedef int address;
typedef struct {
infotype Data[MaxEl+1];
address TOP;
} stack;

#define TOP(S) (S).TOP
#define InfoTop(S) (S).Data[(S).TOP]

void CreateEmpty(stack *S) {
	TOP(*S) = Nil;
}
bool IsEmpty(stack S) {
	return (TOP(S) == Nil);
}
bool IsFull(stack S) {
	return (TOP(S) == MaxEl);
}

void Push(stack *S, infotype X) {
	if (!IsFull(*S)) {
		TOP(*S)++;
		InfoTop(*S) = X;
	} else {
		cout << "Stack Penuh";
	}
}

void Pop(stack *S, infotype *X) {
	if (!IsEmpty(*S)) {
		*X = InfoTop(*S);
		TOP(*S)--;
	} else {
		cout << "Stack Kosong";
	}
}



int main(){
	stack DataTest;
	infotype DataHapus;
	CreateEmpty(&DataTest);
	int x,a=1,b=0,c;

	cin>>x;
	string k[x],l;

	for(int i=0;i<x;i++){
		cin>>k[i];
	}

	for(int i=0;i<x;i++){
		l=k[i];
		c=a-b;
		for(int j=0;l[j];j++){
			if(l[j]=='0'){
				Push(&DataTest,0);
				a++;
			}else if(l[j]=='1'){
				Push(&DataTest,1);
				a++;
			}else if(l[j]=='2'){
				Push(&DataTest,2);
				a++;
			}else if(l[j]=='3'){
				Push(&DataTest,3);
				a++;
			}else if(l[j]=='4'){
				Push(&DataTest,4);
				a++;
			}else if(l[j]=='5'){
				Push(&DataTest,5);
				a++;
			}else if(l[j]=='6'){
				Push(&DataTest,6);
				a++;
			}else if(l[j]=='7'){
				Push(&DataTest,7);
				a++;
			}else if(l[j]=='8'){
				Push(&DataTest,8);
				a++;
			}else if(l[j]=='9'){
				Push(&DataTest,9);
				a++;
			}else if(l[j]=='_'){
				Pop(&DataTest, &DataHapus);
				b++;
			}
		}

	for(int i=c;i<a-b;i++){
		cout<<DataTest.Data[i]<<" ";
	}
	cout<<endl;
}

}
