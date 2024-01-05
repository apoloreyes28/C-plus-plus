//Busqueda Lineal (Secuencial)
  
#include<iostream>  
#include<conio.h> 

using namespace std;

int main(){
   int a[] = {3,4,1,5,2};
   int data = 1; // dato que vamos a buscar 
   int i; // iterador del bucle
   char flag = 'F'; 
//False, sirve para ver si el numero esta o no en el arreglo

// Busqueda Secuencial
   i = 0;
   while((flag == 'F') && (i<5)){
//mientras no encontremos el dato, porque al encontrarlo, flag cambiara a True
     if(a[i] == data){
//este condicional nos va servir para darnos cuenta si un determinado elemento
//es igual al dato que estamos buscando.
        flag = 'T';
     } 
     i++;
   } 

   if(flag == 'F'){
      cout<<"The number to search has not been found!"<<endl;
   }else if(flag == 'T'){
      cout<<"The number has been found in the position: "<<i-1<<endl;
   } // este i-1 esta quitando el ultimo iterador que acabo de aumentar
    // para que solamente me salga la posicion exacta en donde se encuentra.    

getch();
return 0;
} 
