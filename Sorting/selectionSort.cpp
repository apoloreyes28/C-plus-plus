#include<iostream>
#include<conio.h>

using namespace std;

int main(){
   int numbers[] = {3,4,5,2,1};
   int i,j,aux,min;

   for(i=0;i<5;i++){

	for(j=i+1;j<5;j++){

	  if(numbers[j] < numbers[min]){
       min = j;
	  }	   
	} 
//hacemos el intercambio correspondiente
    aux = numbers[i];
	numbers[i] = numbers[min];
	numbers[min] = aux;
   } 

// Imprimiendo
   cout<<"Ascending Order: ";
	for(i=0;i<5;i++){
		cout<<numbers[i]<<" ";
	}
	
   cout<<"\nDescending Order: ";
	for(i=4;i>=0;i--){
		cout<<numbers[i]<<" ";
	}

getch();
return 0;
} 
