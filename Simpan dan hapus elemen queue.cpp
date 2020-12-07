// NIM : 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 27-11-2020
// Deskripsi : Simpan dan hapus elemen queue

#include<iostream>
using namespace std;

#define Nil 0
#define MaxEl 5

typedef int infotype;
typedef int address;
typedef struct {
    infotype T[MaxEl+1];
    address HEAD;
    address TAIL;
} Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]

bool isEmpty(Queue Q) {
    return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}

void CreateEmpty(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

int NbElmt(Queue Q) {
    if (isEmpty(Q)) {
        return 0;
    }
    else {
        if (Head(Q)<=Tail(Q)) {
            return (Tail(Q)-Head(Q)+1);
        }
        else {
            return (MaxEl-Head(Q)+Tail(Q)+1);
        }
    }
}

bool isFull(Queue Q) {
    return (NbElmt(Q)==MaxEl);
}

void Add(Queue *Q, infotype x) {
    if (!isFull(*Q)) {
        if(isEmpty(*Q)) {
            Head(*Q) = 1;
            Tail(*Q) = 1;
        }
        else {
            if (Tail(*Q)==MaxEl) {
                Tail(*Q)=1;
            }
            else {
                Tail(*Q)++;
            }
        }
        InfoTail(*Q) = x;
    }
}

void Del(Queue *Q, infotype *hapus) {
    *hapus = InfoHead(*Q);
    if (Tail(*Q)==Head(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        if (Head(*Q)==MaxEl) {
            Head(*Q)=1;
        }
        else {
            Head(*Q)++;
        }
    }
}

int main(){
    Queue DataTest;
    infotype DataHapus;
    CreateEmpty(&DataTest);
    int n,x,y;

    cin >> n;
    string a[n],b;

    for(x=0;x<n;x++){
        cin >> a[x];
    }
    for(x=0;x<n;x++){
        b=a[x];
        for(y=0;b[y];y++){
            if(b[y]=='0'){
                Add(&DataTest,0);
            }
            else if(b[y]=='1'){
                Add(&DataTest,1);
            }
            else if(b[y]=='2'){
                Add(&DataTest,2);
            }
            else if(b[y]=='3'){
                Add(&DataTest,3);
            }
            else if(b[y]=='4'){
                Add(&DataTest,4);
            }
            else if(b[y]=='5'){
                Add(&DataTest,5);
            }
            else if(b[y]=='6'){
                Add(&DataTest,6);
            }
            else if(b[y]=='7'){
                Add(&DataTest,7);
            }
            else if(b[y]=='8'){
                Add(&DataTest,8);
            }
            else if(b[y]=='9'){
                Add(&DataTest,9);
            }
            else if(b[y]=='_'){
                Del(&DataTest, &DataHapus);
            }
        }
        while (Head(DataTest) != Nil) {
            cout << InfoHead(DataTest)<<" ";
            Del(&DataTest, &DataHapus);
        }
        cout<<endl;
    }
}
