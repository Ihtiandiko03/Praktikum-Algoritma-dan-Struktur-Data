// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 13 November 2020
// Deskripsi : Besar Kecil

#include<iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    struct Node* next;
};

int Maksimal(struct Node* head)
{
    int max = INT_MIN;
    while (head != NULL) {

        if (max < head->data)
            max = head->data;
        head = head->next;
    }
    return max;
}

int Minimal(struct Node* head)
{
    int min = INT_MAX;

    while (head != NULL) {

        if (min > head->data)
            min = head->data;

        head = head->next;
    }
    return min;
}

void Allocation(struct Node** head, int data)
{
    struct Node* newNode =
         (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->next = (*head);
    (*head) = newNode;
}



// Drier program to test the functions
int main()
{
    struct Node* head = NULL;

    int i=0,A,n;
    cin>>n;
    while(i<n){
        cin>>A;
        Allocation(&head, A);

        i++;
    }
    cout << Maksimal(head) << endl;
    cout << Minimal(head) << endl;

    return 0;
}
