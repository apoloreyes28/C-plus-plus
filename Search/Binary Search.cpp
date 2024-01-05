//Busqueda Binaria:
//para poder utilizarla necesitamos que el arreglo
//de numbers este ordenado en orden ascendente.

#include<iostream>  
#include<conio.h> 

using namespace std;

int main(){   
   int numbers[] = {1,2,3,4,5};
   int lower, upper, middle, data;
   char flag = 'F';
   data = 3;

// Algoritmo de la Busqueda Binaria
   lower = 0;// lo inicializamos en 0
   upper = 5;
// lo incialiazamos con el # de elementos que va tener el arreglo
   
   while(lower <= upper){
      middle = (lower + upper)/2;
      
// middle, va ser exactamente la posicion en la que vamos del arreglo
      if(numbers[middle] == data){//esto significa que hemos encontrado el numero
//esto nos sirve para saber si vamos a encontrar el dato o no
	    flag = 'T';
	    break;//esto hace que al encontrar el dato, el ciclo se detenga
	  } 
      if(numbers[middle] > data){
	    upper = middle;// cambiamos la variable upper
	    middle = (lower + upper)/2;
	  } 
	  if(numbers[middle] < data){
	    lower = middle;// cambiamos la variable lower
	    middle = (lower + upper)/2;
	  }     
   } 

// Imprimiendo la informacion
   if(flag == 'T'){
     cout<<"The number has been found in the position: "<<middle<<endl;
   }// la posicion se guarda dentro de lo que es: middle = mitad
   else{
     cout<<"The number has not been found!"<<endl;
   } 

getch();
return 0;
} 
