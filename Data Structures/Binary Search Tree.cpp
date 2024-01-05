#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node{
   int data;
   Node *right;
   Node *left;
   Node *father;
};

//Prototipo de funcion
void menu();
Node *createNode(int, Node *);
void insertNode(Node *&, int, Node *);
void showTree(Node *, int);
bool search(Node *, int);
void preOrder(Node *);
void inOrder(Node *);
void postOrder(Node *);
void eliminate(Node *, int);
void deleteNode(Node *);
Node *minimum(Node *);

void replace(Node *, Node *);
void destroyNode(Node *);

Node *tree = NULL;

int main(){
	menu();
	
getch();
return 0;	
}

//Definicion de la funcion: menu()
void menu(){
   int data, option, counter=0;
   
   do{
   	    cout<<"\t--MENU--"<<endl;
   	    cout<<"1. Insert a new node"<<endl;
   	    cout<<"2. Show the full tree: "<<endl;
   	    cout<<"3. Search for an element in the tree: "<<endl;
   	    cout<<"4. Go through the tree in preOrder: "<<endl;
   	    cout<<"5. Go through the tree in inOrder: "<<endl;
   	    cout<<"6. Go through the tree in postOrder: "<<endl;
   	    cout<<"7. Delete an item from the tree: "<<endl;
   	    cout<<"8. Exit"<<endl;
   	    cout<<"Option: ";
   	    cin>>option;
   	   
   	    switch(option){
		    case 1: cout<<"\nEnter a number: ";
		            cin>>data;
		            insertNode(tree,data,NULL);// insertamos un nuevo nodo
// al momento que hemos insertado un nuevo elemento en el arbol, tambien hay 
// que referenciar quien es el padre de este elemento(nodo), 
// como no lo sabemos por eso le ponemos NULL
		            cout<<"\n";
					system("pause");
		            break;
		    case 2: cout<<"Showing the full tree:\n\n";
	                showTree(tree, counter);
	                cout<<"\n";
		            system("pause");
		            break;
		    case 3: cout<<"Enter the item to search: ";
					cin>>data;
					if(search(tree,data) == true){
	   				cout<<"Item: "<<data<<" found!"<<endl;
					}
					else{
	   				cout<<"Item not found!"<<endl;
					} 
					cout<<"\n";
		            system("pause");
		            break;
		    case 4: cout<<"\nGo through in preOrder: ";
		   		    preOrder(tree);
					cout<<"\n\n";
		            system("pause");
		            break;
		    case 5: cout<<"\nGo through in inOrder: ";
			   		inOrder(tree);
					cout<<"\n\n";
		            system("pause");
		            break;
			case 6: cout<<"\nGo through in postOrder: ";
			        postOrder(tree);
					cout<<"\n\n";
		            system("pause");
		            break;
		    case 7: cout<<"\nEnter the node to eliminate: ";
		            cin>>data;
		            eliminate(tree,data);
		            cout<<"\n";
		            system("pause");
		            break;
	   }
   	   system("cls");
   }while(option != 8);
}

//Definicion de la funcion: createNode()
Node *createNode(int n, Node *father){
//con cada nodo que vayamos creando vamos a indicarle quien es el nodo padre	
   Node *new_node = new Node();
   
   new_node -> data = n;
   new_node -> right = NULL;
   new_node -> left = NULL;
   new_node -> father = father;
   
   return new_node;
}

//Definicion de la funcion: insertNode()
void insertNode(Node *&tree, int n, Node *father){
   if(tree == NULL){//Si el arbol esta vac�o
   	  Node *new_node = createNode(n, father);
//aqui indicamos el dato que tendra el nodo y quien sera el padre del nuevo_nodo
   	  tree = new_node;
   }
   else{//Si el arbol tiene uno o mas nodos
   	  int rootValue = tree -> data;//obtenemos el valor de la raiz
   	  
	  if(n < rootValue){//Si el elemento es menor a la raiz, insertamos en el lado izquierdo
	  	 insertNode(tree->left,n,tree);//el nodo padre estara referenciado por el arbol
	  }
	  else{//Si el elemento es mayor a la raiz, insertamos en el lado derecho
	  	 insertNode(tree->right,n,tree);
	  }
   }                
}

//Definimos la funcion: showTree()
void showTree(Node *tree, int count){
   if(tree == NULL){//Si el arbol esta vac�o
   	 return;
   }
   else{
   	 showTree(tree -> right, count+1);
   	 for(int i=0; i<count; i++){
	    cout<<"   ";	
	 }
	 cout<<tree -> data<<endl;
	 showTree(tree -> left, count+1);
   }
}

//Definimos la funcion: search()
bool search(Node *tree, int n){
   if(tree == NULL){//Si el arbol esta vac�o
   	 return false;
   }
   else if(tree -> data == n){//Si el nodo es igual al elemento que estamos buscando
   	 return true;
   }
   else if(n < tree -> data){//Si el nodo es menor al elemento que estamos buscando
   	 return search(tree -> left,n);
   }
   else{//Si el nodo es mayor al elemento que estamos buscando
   	 return search(tree -> right,n);
   }
}

//Definimos la funcion: preOrder()
void preOrder(Node *tree){
   if(tree == NULL){
   	 return;
   }
   else{
   	 cout<<tree->data<<" - ";
   	 preOrder(tree->left);
   	 preOrder(tree->right);
   }
}

//Definimos la funcion: inOrder()
void inOrder(Node *tree){
   if(tree == NULL){
   	 return;
   } 
   else{
   	 inOrder(tree->left);
   	 cout<<tree->data<<" - ";
   	 inOrder(tree->right);
   }
}

//Definimos la funcion: postOrder()
void postOrder(Node *tree){
   if(tree == NULL){
   	 return;
   } 
   else{
   	 postOrder(tree->left);
   	 postOrder(tree->right);
	 cout<<tree->data<<" - ";
   }
}

//Definimos la funcion: eliminate()
void eliminate(Node *tree, int n){
   if(tree == NULL){
   	 return;
   } 
   else if(n < tree->data){//si el elemento es menor
     eliminate(tree->left, n);//Busca por la izquierda
   }
   else if(n > tree->data){//si el elemento es mayor
   	 eliminate(tree->right, n);//Busca por la derecha
   }
   else{//si encontramos el elemento(valor del nodo)
   	 deleteNode(tree);
   }
}

//Definimos la funcion: minimum()
Node *minimum(Node *tree){
   if(tree == NULL){
   	 return NULL;
   } 
   if(tree->left){//si tiene hijo izq
   	 return minimum(tree->left);//busca la parte mas izq posible
   }
   else{//si no tiene hijo izq
   	 return tree;//retornamos el mismo nodo
   }
}

//Definimos la funcion: replace()
void replace(Node *tree, Node *newNode){
   if(tree->father){
   	
//arbol->padre hay que asignarle su nuevo hijo 

     if(tree->data == tree->father->left->data){//hijo izq
     	tree->father->left = newNode;
	 }
	 else if(tree->data == tree->father->right->data){//hijo der
	    tree->father->right = newNode;
	 } 	 
   }
   if(newNode){
//procedemos a asignarle su nuevo hijo  
     newNode->father = tree->father;	 
   }
}

//Definimos la funcion: destroyNode()
void destroyNode(Node *node){
   node->left = NULL;
   node->right = NULL;
   
   delete node;
}

//Definimos la funcion: deleteNode()
void deleteNode(Node *nodeRemove){

   if(nodeRemove->left && nodeRemove->right){
//si el nodo tiene dos hijos, tanto a la izq como a la der  	
   
   Node *smaller = minimum(nodeRemove->right);
   nodeRemove->data = smaller->data;
   deleteNode(smaller);
   }
   else if(nodeRemove->left){//si el nodo tiene hijo izq
   	 replace(nodeRemove, nodeRemove->left);
   	 destroyNode(nodeRemove);
   }
   else if(nodeRemove->right){//si el nodo tiene hijo der
   	 replace(nodeRemove, nodeRemove->right);
   	 destroyNode(nodeRemove);
   }
   else{//si el nodo no tiene hijos(nodo hoja)
   	 replace(nodeRemove, NULL);
   	 destroyNode(nodeRemove);
   }  
}
