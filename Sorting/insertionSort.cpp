#include<iostream>
#include<conio.h>
using namespace std;

int main(){
   int numbers[] = {3,4,2,1,5};
   int i,pos,aux;// aux, para el cambio
//pos, variable para almacenar la posicion

//Algoritmo del Ordenamiento por Insercion:
   for(i=0;i<5;i++){
   pos = i;
   aux = numbers[i];
//va guardar el #exacto en el que vamos del arreglo
  
//                     #izquierda > #actual = cambio
   while((pos>0) && (numbers[pos-1] > aux)){
			numbers[pos] = numbers[pos-1];
			pos--;
//para comprobar si los #anteriores(a la izquierda) son menores al #actual 
		}
        numbers[pos] = aux;
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
