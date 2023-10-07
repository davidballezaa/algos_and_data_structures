#include <iostream>
using namespace std;

// Queue implemented with linked list
class Node {
    public:
        int value;
        Node* next;
        Node* prev;

    Node(int value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }

};

class QueueLinkedList {
    public:
        Node* front;
        Node* last;
        int size;

    QueueLinkedList() {
        this->front = NULL;
        this->last = NULL;
        this->size = 0;
    }

    bool isEmpty();
    int getSize();
    void show();
    void getTop();

    void enqueue(int value);
    int dequeue();
};

bool QueueLinkedList::isEmpty() {
    return this->size == 0;
}

int QueueLinkedList::getSize() {
    return this->size;
}

void QueueLinkedList::show() {
    Node *curr = this->front;
    int count = 0;
    while(curr != NULL){
        cout << "Element [" << count << "]: " << curr->value << '\n';
        curr = curr->next;
        count += 1;
    }
}

void QueueLinkedList::getTop() {
    cout << "Next element is: " << this->front->value << '\n';
}

void QueueLinkedList::enqueue(int value) {
    Node *new_node = new Node(value);
    if(this->size == 0){
        this->front = new_node;
        this->last = new_node;
    } else {
        this->last->next = new_node;
        new_node->prev = this->last;
        this->last = new_node;
    }
    this->size += 1;
}

int QueueLinkedList::dequeue() {
    if(this->size == 0){
        cout << "Queue is empty.\n";
        return -1;
    } else {
        Node *front_node = this->front;
        int value = front_node->value;
        front_node->next->prev = NULL;
        this->front = front_node->next;
        this->size -= 1;
        delete front_node;
        return value;
    }
}

// Queue implemented with arrays
class QueueArray {
private:
    int maxSize, size, first;
    int* arr;

public:
    QueueArray(int maxSize) {
        this->maxSize = maxSize;
        this->size = 0;
        this->first = 0;
        this->arr = new int[maxSize];
    }

    ~QueueArray() {
        delete[] this->arr;
    }

    bool isEmpty();
    bool isFull();
    int getSize();
    void show();

    void enqueue(int valor);
    int dequeue();
    void getTop();

};

bool QueueArray::isEmpty() {
    return this->size == 0;
}

bool QueueArray::isFull() {
    return this->size == this->maxSize;
}

int QueueArray::getSize() {
    return this->size;
}

void QueueArray::show() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    for (int i = this->first, count = 0; count < this->size; i = (i + 1) % this->maxSize, count++) {
        int index = i % this->maxSize;
        cout << "Element [" << count << "]: " << this->arr[index] << '\n';
    }
}

void QueueArray::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full of items." << endl;
        return;
    }

    int index = (this->first + this->size) % this->maxSize;
    this->arr[index] = value;
    this->size += 1;
}

int QueueArray::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    int dequeuedItem = this->arr[this->first];
    this->first = (this->first + 1) % this->maxSize;
    this->size--;

    return dequeuedItem;
}

void QueueArray::getTop() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Next element is: " << this->arr[this->first] << endl;
    }
}

int main() {
    cout << "Array implementation: \n";
    QueueArray *queue_array = new QueueArray(4);
    queue_array->enqueue(1);
    queue_array->enqueue(2);
    queue_array->enqueue(3);
    queue_array->enqueue(4);
    queue_array->show();
    cout << "Item dequeued: " << queue_array->dequeue() << '\n';
    queue_array->show();
    cout << '\n';
    queue_array->enqueue(5);
    queue_array->show();
    queue_array->getTop();

    cout << '\n';

    cout << "Linked List implementation: \n";
    QueueLinkedList *queue_linked = new QueueLinkedList();
    queue_linked->enqueue(1);
    queue_linked->enqueue(2);
    queue_linked->enqueue(3);
    queue_linked->enqueue(4);
    queue_linked->show();
    cout << "Item dequeued: " << queue_linked->dequeue() << '\n';
    queue_linked->show();
    cout << '\n';
    queue_linked->enqueue(5);
    queue_linked->show();
    queue_linked->getTop();
    return 0;
}