#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

class Node {	
	public:
		int value;		
		Node *next;		
	
		Node(int value)
		{	this->value = value;
			this->next = NULL;
		}

};

class List {
	Node *first;   
	int size;

	public:
		List() 
		{	this->first = NULL; 
			this->size = 0;
		}
		
		int getSize(){ return size; }
		void showList();

		Node* find(int, int*);
		void update(int, int);		
		
		void insertLast(int);
		void insertFirst(int);
		bool insertAtIndex(int, int);

		void deleteFirst();
		void deleteLast();			
		void deleteAtIndex(int);	


};

Node* List::find (int value, int *index)
{	//	Comenzamos en el primer nodo (first)
	//	aux servira como iterador 
	Node *aux = this->first;				
	
	*index = -1;							
	int i = 0;

	//	Como sabes que llegaste al final de la lista?
	//	Si aux se vuelve null

	while ( aux != NULL ) 			
	{	
		if ( aux->value == value )		//	comparamos valores
		{	*index = i;				
			return aux;	//	regresamos la direccion de memoria donde esta el
						//	nodo con el valor buscado
		}
		aux = aux->next;		//	que valor deberia tomar aux??
		i++;			//	i cuenta para encontrar el indice
	}
	return NULL;

}


// 	Elimina el primer elemento de la lista
void List::deleteFirst () {	
	Node *aux = this->first;		//	aux comienza siendo el primer elemento

	//	que valor deberia tomar first? Quien sera el nuevo primer elelemento?
	this->first = aux->next;  
	
	delete aux; // que nodo se elimina? 
	this->size--;
}

void List::deleteLast() {
	if(this->size == 1) deleteFirst();
	else {
		Node *aux = this->first;
		while(aux->next->next != NULL){
			aux = aux->next;
		}
		delete aux->next;
		aux->next = NULL;
		this->size--;
	}
}

void List::deleteAtIndex(int index){
	if(index == 0) deleteFirst();
	else if(index == this->size - 1) deleteLast();
	else {
		int i = 0;
		Node *prev = NULL;
		Node *aux = this->first;
		while(aux != NULL){
			if(i == index){
				prev->next = aux->next;
				delete aux;
				break;
			}
			prev = aux;
			aux = aux->next;
			i++;
		}
	}
}

/*Inserta nodo nuevo al inicio de la lista*/
void List::insertFirst(int newValue){	
	Node *node = new Node(newValue);  // Creamos un nodo nuevo

	node->next = this->first; 	//	El siguiente del nuevo es el primero
	this->first = node;			//	El nuevo primero es el nuevo nodo
	this->size += 1;				//	Aumentamos tamaño de la lista de elementos
}


// Insertar nuevo nodo al final 
void List::insertLast(int newValue)
{	Node *node = new Node(newValue);  // Creamos un nodo nuevo

	if (this->first == NULL)					//	Si la lista esta vacia, insertamos nuevo al inicio
	{ this->first = node; this->size += 1;	}
	else
	{	//	Si no, nos desplazamos al ultimo
		Node *aux = this->first;

		while ( aux->next != NULL)	//	Encontramos el ultimo i.e. el que 
		{	aux = aux->next;	}	//	tiene un next que es es null
		
		aux->next = node;	//	El ultimo apuntara al nodo nuevo
		this->size += 1;				//	Actualizamos el tamaño de la lista 
	}
}

// Inserta en un indice especifico
bool List::insertAtIndex(int index, int newValue )
{	Node *aux = this->first;					//	Comenzamos en el primer nodo
	Node *node = new Node(newValue);    // Creamos un nodo nuevo

	if ( index == 0)					//	Nuevo al inicio
	{	insertFirst(newValue);	
		return true;
	}
	else if ( index == this->size )		//	Nuevo al final
	{	insertLast(newValue);	
		return true;
	}
	else
	{	//	Insertar nuevo enmedio
		int i = 0;		//	contador para cuando en	
		while ( aux->next != NULL )		
		{	if (i == index - 1)		//	Encontramos el indice donde ira el nuevo
			{	
				//	el nodo nuevo debe quedar entre aux y aux->next
			
				node->next = aux->next;
				aux->next = node;        
				this->size += 1; 		//	Actualizamos el tamaño de la lista 
				return true;
			}
			aux = aux->next;	
			i++;
		}
	}	

	cout << "Indice no valido" << endl;
	return false; 

}

void List::showList()
{	Node *aux = this->first;		//	Comenzamos en el primer link
	int i = 0;

	cout << "List size: " << this->size << endl;

	while ( aux != NULL)
	{	cout << "\tvalor " << i <<": "<< aux->value << endl;
		aux = aux->next;		//	aux debe ser el siguiente nodo
		i++;
	}
}



int main(int argc, char* argv[]) {	
	List list;

	list.insertFirst(1); 	list.showList();
	list.insertFirst(0); 	list.showList();

	list.insertLast(2); 	list.showList();
	list.insertLast(4); 	list.showList();

	list.insertAtIndex(3, 3); 	list.showList();

    list.deleteFirst(); 	list.showList();

	list.deleteLast(); 	list.showList();

	list.deleteAtIndex(1); 	list.showList();

	int index;
	Node *a = list.find(2, &index);
	cout << "Encontrado en memoria: " <<a << " index: " << index << endl;
}