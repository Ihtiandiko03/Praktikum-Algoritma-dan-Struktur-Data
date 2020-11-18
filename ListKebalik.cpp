// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 13 November 2020
// Deskripsi : Masuk Aneh

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

    void pembalik()
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
        cout<<"[";
        while (temp != NULL) {
                if(temp->next==NULL){
                    cout << temp->data;
                }
                else{
                    cout << temp->data << ", ";
                }
            temp = temp->next;
        }
        cout<<"]";
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
    int i=0,n,A;
    cin>>n;
    while(i<n){
        cin>>A;
        ll.Allocation(A);
        i++;
    }
    ll.cetakangka();

    return 0;
}
