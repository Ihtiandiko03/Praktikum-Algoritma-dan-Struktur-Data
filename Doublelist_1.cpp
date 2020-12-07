// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 20 November 2020
// Deskripsi : P1 Doublelist

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
 infotype info;
 address next;
 address prev;
} ElmtList;

typedef struct {
 address first;
 address last;
}List ;


#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).first)
#define Last(L) ((L).last)
#define Nil NULL


bool IsEmpty(List L) {
 return (First(L) == NULL && Last(L) == NULL);
}

void createList(List *L) {
 First(*L) = NULL;
 Last(*L) = NULL;
}

address Allocation(infotype x) {
 address NewElmt;
 NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
 Info(NewElmt) = x;
 Next(NewElmt) = Nil;
 Prev(NewElmt) = Nil;
 return NewElmt;
}

void Deallocation(address hapus) {
 free(hapus);
}

address Search (List L, infotype X){
	address P = First(L);
	while (P != Nil){
		if (Info(P) == X){
			return P;
		}
		P = Next(P);
	}
	return Nil;
}

void InsertFirst(List *L, infotype x) {
 address NewElmt;
 NewElmt = Allocation(x);
 if (NewElmt != NULL) {
 if(IsEmpty(*L)){
    First(*L) = NewElmt;
    Last(*L) = NewElmt;
 } else{
    Next(NewElmt) = First(*L);
    Prev(First(*L)) = NewElmt;
    First(*L) = NewElmt;
    }
 }
}

void InsertFirst (List *L, address P){
 if(IsEmpty(*L)){
    First(*L) = P;
    Last(*L) = P;
 } else{
    Next(P) = First(*L);
    Prev(First(*L)) = P;
    First(*L) = P;
 }
}

int main(){
string input_biner;
	List data;
	createList(&data);

	for(int i = 0; i < 8; i++){
		InsertFirst(&data, pow(2, i));
	}

	cin >> input_biner;

	address temp;
	temp = data.first;
	int i = 0, jml = 0;
	while(temp != NULL){
		temp->info = (int(input_biner[i])-48) * temp->info;

		jml = jml + temp->info;

		i++;
		temp = temp->next;
	}

	i=7;
	temp = data.first;
	while(i>0){
		cout << "2^" << i << " = " << temp->info << endl;
		i = i - 2;
		temp = temp->next->next;
	}

	i = 0;
	temp = data.last;
	while(i<7){
		cout << "2^" << i << " = " << temp->info << endl;
		i = i + 2;
		temp = temp->prev->prev;
	}

	cout << "Total = " << jml;
}
