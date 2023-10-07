#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node *prev;

    Node(int value) {
        this->value = value;
        this->prev = NULL;
    }
};

class StackLinkedList {
    public:
        int size;
        Node *last;

    StackLinkedList() {
        this->size = 0;
        this->last = NULL;
    }

    int getSize();
    bool isEmpty();
    void show();

    void push(int valor);
    int getTop();
    int pop();


};

int StackLinkedList::getSize() {
    return this->size;
}

bool StackLinkedList::isEmpty() {
    return this->size == 0;
}

void StackLinkedList::show() {
    Node *curr = this->last;
    for(int i=this->size - 1; i>=0; i--){
        cout << "lista ["<< i <<"] " << curr->value << endl;
        curr = curr->prev;
    }
}

void StackLinkedList::push(int valor) {
    Node *new_node = new Node(valor);
    new_node->prev = this->last;
    this->last = new_node;
    this->size += 1;
}

int StackLinkedList::getTop() {
    if(this->size > 0){
        return this->last->value;
    } else {
	    cout << "Esta vacia" << endl;	
        return -1;
    }
}

int StackLinkedList::pop() {
    if(this->size > 0){
        Node* last = this->last;
        int last_value = last->value;
        if(this->size > 1){
            this->last = this->last->prev;
        }
        this->size -= 1;
        delete last;
        return last_value;
    } else {
	    cout << "Esta vacia" << endl;	
        return -1;
    }
}

class StackArray{
	private:
		int top = -1; 
		int *array;
		int size  = 0;
		int maxSize; 

	public:
		// Constructor
		StackArray (int maxSize)
		{	this->maxSize = maxSize; 
			array = (int *) malloc( maxSize * sizeof(int) );
		}

		//	Destructor de la clase
		~StackArray()
		{	delete[] this->array; }

		int getSize();		
        int getTop();
		bool isEmpty();
		bool isFull();
		bool push ( int valor );
		int pop ();

		void show();
};

int StackArray::getSize() {
    return this->size;
}

bool StackArray::isEmpty() {
    return this->size == 0;
}

int StackArray::getTop() {
    if(this->size > 0){
        return this->array[top];
    } else {
        cout << "Esta vacia" << endl;
        return -1;
    }
}

bool StackArray::isFull() {
    return this->size == this->maxSize;
}

bool StackArray::push (int valor)
{	if (this->size + 1 < maxSize )
	{	array[top + 1] = valor;
		size++;
		top++;
		return true;
	}
	else
	{	cout << "StackArray llena\n"<< endl;
		return false;
	}
}

int StackArray::pop() 
{	if (this->size > 0)
	{	int valor = array[top];
		top--;
		size--;
		return valor;
	}	
	else
	{	cout << "Esta vacia" << endl;	
		return -1; 
	}

}

void StackArray::show()
{	int i;
	for (i = 0; i < this->size; i++ )
	{	cout << "array["<< i <<"] " << array[i] << endl;	}

}

int main(int argc, char  *argv[])
{	int i;
	int maxSize = 10;

	StackArray *stack_arr = new StackArray(maxSize);
    cout << "Array implementation: " << endl;
	
	stack_arr->push(4);
	stack_arr->push(5);
	stack_arr->push(9);

	stack_arr->show();
    cout << "Top is: " << stack_arr->getTop() << endl;

	int val = stack_arr->pop();
	cout << "Out: " << val << endl;

	stack_arr->show();
    cout << "Top is: " << stack_arr->getTop() << endl;

    cout << '\n';
    cout << "Linked List implementation: " << endl;

	StackLinkedList *stack_linked = new StackLinkedList();
	
	stack_linked->push(4);
	stack_linked->push(5);
	stack_linked->push(9);
    stack_linked->show();

    cout << "Top is: " << stack_linked->getTop() << endl;

	int val_2 = stack_linked->pop();
	cout << "Out: " << val_2 << endl;

	stack_linked->show();
    cout << "Top is: " << stack_linked->getTop() << endl;


	return 0;
}