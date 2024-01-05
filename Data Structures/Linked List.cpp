#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Node{
	int data;
	Node *next;	
};

//Prototipos de funcion
void menu();
void insertList(Node *&lista, int n);
void showList(Node *lista);
void searchList(Node *lista, int n);
void deleteNode(Node *&lista, int n);
void deleteList(Node *&lista, int &n);

Node *lista = NULL;// variable global

int main(){
   menu();

   getch();
   return 0;
} 

void menu(){
   int data, option;
   
   do{
      cout<<"\tMENU\n";
      cout<<"1. Insert items into list\n";
      cout<<"2. Show list items\n";
      cout<<"3. Find a list item\n";
      cout<<"4. Remove a Node from the list\n";
      cout<<"5. Leave the list empty\n";
      cout<<"6. Exit\n";
      cout<<"Option: ";
      cin>>option;
      
      switch(option){
	     case 1: cout<<"\nEnter a number: ";
	             cin>>data;
	             insertList(lista,data);// llamamos a la funcion
	             cout<<"\n";
	             system("pause");
	             break;
	     
	     case 2: showList(lista);// llamamos a la funcion
	             cout<<"\n";
	             system("pause");
	             break;
	     
	     case 3: cout<<"\nEnter the number to search: ";
         	     cin>>data;
         	     searchList(lista,data);// llamamos a la funcion
	     	     cout<<"\n";
	      	     system("pause");
	      	     break;
	     
	     case 4: cout<<"\nEnter the number to delete: ";
          	     cin>>data;
          	     deleteNode(lista, data);// llamamos a la funcion
	      	     cout<<"\n";
	      	     system("pause");
	     	     break;
	     
	     case 5: while(lista != NULL){//mientras no sea el final de la lista
         	     deleteList(lista,data);// llamamos a la funcion
         	     cout<<data<<" -> ";
         	     } 
		 	     cout<<"\n";
	     	     system("pause");
	     	     break;  
	  } 
      system("cls");
   }while(option != 6);
} 

//Definicion de la funcion: insertList()
void insertList(Node *&lista, int n){
    Node *new_node = new Node();
	new_node->data = n;
	
	Node *aux1 = lista;
	Node *aux2;
	
	while((aux1 != NULL) && (aux1->data < n)){ 

    aux2 = aux1;
    aux1 = aux1->next;
    }

    if(lista == aux1){ 
      lista = new_node;
   }
    else{
      aux2->next = new_node;
   } 

   new_node->next = aux1;

   cout<<"\tElement: "<<n<<", added to list\n";
} 

//Definicion de la funcion: showList();
void showList(Node *lista){
   Node *current = new Node();
   current = lista;
   
	while(current != NULL){ //mientras no sea final de la lista
		cout<<current->data<<" -> "; //mostramos el dato
		current = current->next; //avanzamos a la siguiente posicion de la lista
	}
} 

//Definimos la funcion: searchList()
void searchList(Node *lista, int n){
   bool bandera = false;
   
   Node *current = new Node();
   current = lista;
   
   while((current != NULL) && (current->data <= n)){
      if(current->data == n){
	     bandera = true;
	  } 
      current = current -> next;
   } 
   
   if(bandera == true){
      cout<<"\tElement found: "<<n<<" successfully"<<endl;
   }else{
      cout<<"\Element: "<<n<< " not found"<<endl;
   } 
} 

//Definicion de la funcion: deleteNode()
void deleteNode(Node *&lista, int n){

//Preguntar si la lista no esta vacia
   if(lista != NULL){
      Node *aux_delete;
      Node *previous = NULL;
      
      aux_delete = lista;
//Recorrer la lista
      while((aux_delete==NULL) && (aux_delete->data != n)){
	  previous = aux_delete;
	  aux_delete = aux_delete -> next;
	  }
	  if(aux_delete == NULL){
	  	cout<<"Element not found!"<<endl; 
	  }else if(previous == NULL){
	    lista = lista -> next;
	    delete aux_delete;
	  }else{
	    previous -> next = aux_delete -> next;
	    delete aux_delete;
	  }  
   } 
} 

//Definicion de la funcion: deleteList()
void deleteList(Node *&lista, int &n){
   Node *aux = lista;
   n = aux -> data;
   lista = aux -> next;
   delete aux;
} 
