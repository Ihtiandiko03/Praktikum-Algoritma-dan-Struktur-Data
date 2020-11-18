// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 13 November 2020
// Deskripsi : List Kebalik

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    void penukaran()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void cetakangka()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            if(temp->next==NULL){
                cout << temp->data;
            }
            else{
                cout << temp->data << ", ";
            }
            temp = temp->next;
        }
    }

    void Allocation(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList ll;

    int i=0,A,n;
    cin>>n;
    while(i<n){
        cin>>A;
        ll.Allocation(A);
        i++;
    }
    cout<<"[";
    ll.cetakangka();
    cout<<", ";
    ll.penukaran();
    ll.cetakangka();
    cout<<"]";

    return 0;
}
