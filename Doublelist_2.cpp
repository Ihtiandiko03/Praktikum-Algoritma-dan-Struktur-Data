// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 20 November 2020
// Deskripsi : P2 Doublelist

#include <iostream>
#include <stdlib.h>
#include <math.h>
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
#define Infinity 99999

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

void InsertLast(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
    if (NewElmt != NULL) {
        if(IsEmpty(*L)){
        	InsertFirst(L,x);
        } else{
        	Next(Last(*L)) = NewElmt;
        	Prev(NewElmt) = Last(*L);
        	Last(*L) = NewElmt;
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

void InsertLast (List *L, address P){
	if(IsEmpty(*L)){
       	InsertFirst(L,P);
    } else{
       	Next(Last(*L)) = P;
       	Prev(P) = Last(*L);
       	Last(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
	if(Next(Prec) == Nil){
		InsertLast(L,P);
	}else{
		Next(P) = Next(Prec);
		Prev(P) = Prec;
		Prev(Next(Prec))= P;
		Next(Prec) = P;
	}
}

void PrintForward (List L, address temp){
	int i=0;
	float sum=0;
	cout<<"[";
	if(!IsEmpty(L)){
		while(Next(temp)!=NULL){
			cout<<Info(temp) <<", ";
			sum = sum + (Info(temp));
			i++;
			temp = Next(temp);
		}
		cout<<Info(temp);
		sum = sum + (Info(temp));
		i++;
	}
	cout<<"] = "<<(sum/i)<<endl;
}

void PrintBackward (List L, address temp){
	int i=0;
	float sum=0;
	cout<<"[";
	if(!IsEmpty(L)){
		while(Prev(temp)!=NULL){
			cout<<Info(temp) <<", ";
			sum = sum + (Info(temp));
			i++;
			temp = Prev(temp);
		}
		cout<<Info(temp);
		sum = sum + (Info(temp));
		i++;
	}
	cout<<"] = "<< (sum/i) <<endl;
}

int main(){
    List Bilangan;
    createList (&Bilangan);
	int i=0,n,x,a;

	cin >> n;
	while (i<n){
		cin>>x;
		if( x %2 ==0){
			InsertLast(&Bilangan, x);
		}else{
			InsertFirst(&Bilangan, x);
		}
		i++;
	}
	cin>>a;

	address temp = First(Bilangan);
	while (temp != Nil){
		if (Info(temp)==a){
			PrintBackward(Bilangan, temp->prev);
			PrintForward(Bilangan, temp->next);
		}
		temp = Next(temp);
	}

}
