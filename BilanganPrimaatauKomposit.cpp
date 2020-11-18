// NIM: 119140118
// Nama : Ihtiandiko Wicaksono
// Tanggal : 6 November 2020
// Deskripsi : Soal ke 3

#include <iostream>
using namespace std;

int main(){
	int n,cek=0;
	cin>>n;
	int A[n];
	
	for(int i=0; i<n; i++ ){
		cin>>A[i];
		
		cek=0;
		 for(int j=2; j<=A[i]; j++){
          if(A[i] % j == 0){         
               cek++; 
          }
		     }
		     if(cek==1){
		          cout<<"prima"<<endl;
		     }else{
		          cout<<"komposit"<<endl;
		     }
			}
}
