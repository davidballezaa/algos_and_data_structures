#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        int priority;
        Node* next;

    Node(int value, int priority) {
        this->value = value;
        this->priority = priority;
        this->next = NULL;
    }
};

class PriorityQueueLinkedList {
    public:
        Node* head;
        int size;

    PriorityQueueLinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    int getSize();
    bool isEmpty();
    void show();

    void enqueue(int value, int priority);
    int dequeue();
    void getTop();
};

int PriorityQueueLinkedList::getSize() {
    return this->size;
}

bool PriorityQueueLinkedList::isEmpty() {
    return this->size == 0;
}

void PriorityQueueLinkedList::show() {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        Node* curr = head;
        for(int i = 0; i < this->size; i++){
            cout << "Element [" << i << "]: " << curr->value << '\n';
            curr = curr->next;
        }
    }
}

void PriorityQueueLinkedList::enqueue(int value, int priority) {
    Node* newNode = new Node(value, priority);

    if (this->head == NULL || priority > head->priority) {
        newNode->next = this->head;
        this->head = newNode;
    } else {
        Node* curr = this->head;
        while (curr->next != NULL && curr->next->priority >= priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    this->size += 1;
}

int PriorityQueueLinkedList::dequeue() {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        Node* temp = this->head;
        int value = temp->value;
        this->head = temp->next;
        this->size -= 1;
        delete temp;
        return value;
    }
}

void PriorityQueueLinkedList::getTop() {
    if (this->isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Next element is: " << this->head->value << endl;
    }
}


class PriorityQueueArray {
private:
    int* arr;
    int maxSize;
    int size;

public:
    PriorityQueueArray(int maxSize) {
        this->maxSize = maxSize;
        this->arr = new int[maxSize];
        this->size = 0;
    }

    int getSize();
    bool isEmpty();
    void show();


    void enqueue(int value, int priority);
    int dequeue();
    void getTop();
};

int PriorityQueueArray::getSize() {
    return this->size;
}

bool PriorityQueueArray::isEmpty() {
    return this->size == 0;
}

void PriorityQueueArray::show() {
    if (this->size == 0) {
        cout << "Queue is empty" << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << "Element [" << i << "]: " << this->arr[i] << '\n';
        }
        cout << endl;
    }
}
void PriorityQueueArray::enqueue(int value, int priority) {
    if (this->size == this->maxSize) {
        cout << "Queue is full" << endl;
    } else {
        int i;
        for (i = size - 1; i >= 0; i--) {
            if (priority > this->arr[i]) {
                this->arr[i + 1] = this->arr[i];
            }
            else {
                break;
            }
        }
        this->arr[i + 1] = value;
        this->size += 1;
    }
}

int PriorityQueueArray::dequeue() {
    if (this->size == 0) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else {
        int value = arr[0];
        for (int i = 0; i < size - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->size -= 1;
        return value;
    }
}

void PriorityQueueArray::getTop() {
    if (this->isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Next element is: " << this->arr[0] << endl;
    }
}

int main() {
    cout << "Array implementation: \n";
    PriorityQueueArray *queue_array = new PriorityQueueArray(4);
    queue_array->enqueue(1, 1);
    queue_array->enqueue(2, 2);
    queue_array->enqueue(3, 3);
    queue_array->enqueue(4, 4);
    queue_array->show();
    cout << "Item dequeued: " << queue_array->dequeue() << '\n';
    queue_array->show();
    cout << '\n';
    queue_array->enqueue(5, 5);
    queue_array->show();
    queue_array->getTop();

    cout << '\n';

    cout << "Linked List implementation: \n";
    PriorityQueueLinkedList *queue_linked = new PriorityQueueLinkedList();
    queue_linked->enqueue(1, 1);
    queue_linked->enqueue(2, 2);
    queue_linked->enqueue(3, 3);
    queue_linked->enqueue(4, 4);
    queue_linked->show();
    cout << "Item dequeued: " << queue_linked->dequeue() << '\n';
    queue_linked->show();
    cout << '\n';
    queue_linked->enqueue(5, 5);
    queue_linked->show();
    queue_linked->getTop();
    return 0;
}