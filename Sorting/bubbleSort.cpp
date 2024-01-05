#include<iostream>
#include<conio.h>
using namespace std;

int main(){
   int numbers[] = {5,3,4,1,2};
   int i, j , aux;
     
   for(i=0; i<5; i++){
      for(j=0; j<5; j++){ 
	     if(numbers[j] > numbers[j+1]){
           aux = numbers[j]; //#_actual
           numbers[j] = numbers[j+1]; //#_siguiente
           numbers[j+1] = aux;
		 } 
	  } 
   } 

//Imprimiendo el arreglo(lista) ordenado:
   cout<<"Ascending Order: ";
   for(i=0; i<5; i++){
      cout<<numbers[i]<<" ";
   } 
   
   cout<<"\nDescending Order: ";
   for(i=4; i>=0; i--){
      cout<<numbers[i]<<" ";
   } 
   
   getch();
   return 0;
} 
