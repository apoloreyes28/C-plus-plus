/*
Exercise: Make a program in C++, using Queues that contains the following
menu:

1. Insert a character into a queue
2. Show all items in the queue
3. Exit
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	char data;
	Node *next;	
};

//Prototipos de Funciones
void menu();
void insertQueue(Node *&,Node *&,char);
bool queue_empty(Node *);
void deleteQueue(Node *&,Node *&,char &);

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	int opt;
	char data;
	
	Node *front = NULL;
	Node *end = NULL;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Insert a character into a queue"<<endl;
		cout<<"2. Show all items in the queue"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Option: ";
		cin>>opt; 
		
		switch(opt){
			case 1: cout<<"\nEnter the character to add to the queue: ";
					cin>>data;
					insertQueue(front,end,data);
					break;
			case 2: cout<<"\nShowing queue items: ";
					while(front != NULL){
						deleteQueue(front,end,data);
						if(front != NULL){
							cout<<data<<" , ";
						}
						else{
							cout<<data<<".";
						}
					}
					cout<<"\n";
					system("pause");
					break;
			case 3: break;
		}
		system("cls");
	}while(opt != 3);
}

//Función para insertar elementos en la cola
void insertQueue(Node *&front,Node *&end,char n){
	Node *new_node = new Node();
	
	new_node->data = n;
	new_node->next = NULL;
	
	if(queue_empty(front)){
		front = new_node;
	}
	else{
		end->next = new_node;
	}
	
	end = new_node;
}

//Función para determinar si la cola está vacia
bool queue_empty(Node *front){
	return (front == NULL)? true : false; 
}

//Función para eliminar elementos de la cola
void deleteQueue(Node *&front,Node *&end,char &n){
	n = front->data;
	Node *aux = front;
	
	if(front == end){
		front = NULL;
		end = NULL;
	}
	else{
		front = front->next;
	}
	delete aux;
}
