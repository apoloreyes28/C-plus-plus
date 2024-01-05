/*
Exercise: Make a program to add integers to a stack, until the
user decides, then display all the numbers entered in the stack.
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

//Prototipos de Función
void addStack(Node *&,int); 
void removeStack(Node *&,int &);

int main(){
	Node *stack = NULL;
	int data;
	char response;
	
	do{ //Pedimos todos los elementos de la pila
		cout<<"Enter a number: ";
		cin>>data;
		addStack(stack,data);
	
		cout<<"\nYou want to add another number to stack(y/n): ";
		cin>>response;
	}while((response == 'y')||(response=='Y'));
	
	
	cout<<"\nShowing stack elements: ";
	while(stack != NULL){
		removeStack(stack,data);
		
		if(stack != NULL){
			cout<<data<<" , ";
		}
		else{
			cout<<data<<".";
		}
	}
	
	getch();
	return 0;
}

void addStack(Node *&stack,int n){
	Node *new_node = new Node();
	new_node->data = n;
	new_node->next = stack;
	stack = new_node;
	
	cout<<"\nElement "<<n<<"  added to stack successfully";
}

void removeStack(Node *&stack,int &n){
	Node *aux = stack;
	n = aux->data;
	stack = aux->next;
	delete aux;
}
