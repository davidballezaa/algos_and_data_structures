#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *start;
    Node *end;
    int size;

    DoublyLinkedList()
    {
        this->start = NULL;
        this->end = NULL;
        this->size = 0;
    }

    int getSize();

    void showList();

    void showListReverse();

    void insertFirst(int value);

    void insertLast(int value);

    void insertAtIndex(int value, int index);

    void update(int value, int index);

    void deleteFirst();

    void deleteLast();

    void deleteAtIndex(int index);

    Node *find(int value, int *index);
};

int DoublyLinkedList::getSize() { return this->size; }

void DoublyLinkedList::showList()
{
    cout << "List size: " << this->size << '\n';
    Node *curr = this->start;
    for (int i = 0; i < this->size; i++)
    {
        cout << "Element [" << i << "]: " << curr->value << '\n';
        curr = curr->next;
    }
}

void DoublyLinkedList::showListReverse()
{
    cout << "List size: " << this->size << '\n';
    Node *curr = this->end;
    for (int i = this->size - 1; i >= 0; i--)
    {
        cout << "Element [" << i << "]: " << curr->value << '\n';
        curr = curr->prev;
    }
}

void DoublyLinkedList::insertFirst(int value)
{
    Node *new_node = new Node(value);
    if (this->size == 0)
    {
        this->start = new_node;
        this->end = new_node;
        new_node->prev = this->end;
        new_node->next = this->start;
    }
    else
    {
        new_node->next = this->start;
        new_node->prev = this->end;
        this->start->prev = new_node;
        this->start = new_node;
    }
    this->size += 1;
}

void DoublyLinkedList::insertLast(int value)
{
    if (this->size == 0)
    {
        DoublyLinkedList::insertFirst(value);
    }
    else
    {
        Node *new_node = new Node(value);
        this->end->next = new_node;
        new_node->prev = this->end;
        new_node->next = this->start;
        this->end = new_node;
        this->size += 1;
    }
}

void DoublyLinkedList::insertAtIndex(int value, int index)
{
    if (index == 0)
    {
        DoublyLinkedList::insertFirst(value);
    }
    else if (index == this->size)
    {
        DoublyLinkedList::insertLast(value);
    }
    else
    {
        Node *new_node = new Node(value);
        Node *curr;
        // we loop based on whats computationally cheaper
        // curr will end on node at insert index
        if (index < this->size / 2)
        {
            curr = this->start;
            for (int curr_index = 0; curr_index < this->size; curr_index++)
            {
                if (curr_index == index)
                {
                    break;
                }
                curr = curr->next;
            }
        }
        else
        {
            curr = this->end;
            for (int curr_index = this->size - 1; curr_index >= 0; curr_index--)
            {
                if (curr_index == index)
                {
                    break;
                }
                curr = curr->prev;
            }
        }
        new_node->next = curr;
        new_node->prev = curr->prev;
        curr->prev->next = new_node;
        curr->prev = new_node;
        this->size += 1;
    }
}

void DoublyLinkedList::update(int value, int index)
{
    Node *curr;
    // we loop based on whats computationally cheaper
    // curr will end on node at update index
    if (index < this->size / 2)
    {
        curr = this->start;
        for (int curr_index = 0; curr_index < this->size; curr_index++)
        {
            if (curr_index == index)
            {
                break;
            }
            curr = curr->next;
        }
    }
    else
    {
        curr = this->end;
        for (int curr_index = this->size - 1; curr_index >= 0; curr_index--)
        {
            if (curr_index == index)
            {
                break;
            }
            curr = curr->prev;
        }
    }
    curr->value = value;
}

void DoublyLinkedList::deleteFirst()
{
    if (this->size == 0)
        return; // if no elements in list, cannot delete
    Node *curr = this->start;
    if (this->size == 1)
    {
        delete curr;
        this->start = NULL;
        this->end = NULL;
    }
    else
    {
        this->end->next = curr->next;
        curr->next->prev = this->end;
        this->start = curr->next;
        delete curr;
    }
    this->size -= 1;
}

void DoublyLinkedList::deleteLast()
{
    if (this->size == 1 || this->size == 0)
    {
        DoublyLinkedList::deleteFirst();
    }
    else
    {
        Node *curr = this->end;
        curr->prev->next = this->start;
        this->start->prev = curr->prev;
        this->end = this->end->prev;
        this->size -= 1;
        delete curr;
    }
}

void DoublyLinkedList::deleteAtIndex(int index)
{
    if (index == 0)
    {
        DoublyLinkedList::deleteFirst();
    }
    else if (index == this->size - 1)
    {
        DoublyLinkedList::deleteLast();
    }
    else
    {
        Node *curr;
        // we loop based on whats computationally cheaper
        // curr will end on node at delete index
        if (index < this->size / 2)
        {
            curr = this->start;
            for (int curr_index = 0; curr_index < this->size; curr_index++)
            {
                if (curr_index == index)
                {
                    break;
                }
                curr = curr->next;
            }
        }
        else
        {
            curr = this->end;
            for (int curr_index = this->size - 1; curr_index >= 0; curr_index--)
            {
                if (curr_index == index)
                {
                    break;
                }
                curr = curr->prev;
            }
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        this->size -= 1;
        delete curr;
    }
}

Node *DoublyLinkedList::find(int value, int *index)
{
    Node *left_curr = this->start;
    int left_index = 0;
    Node *right_curr = this->end;
    int right_index = this->size - 1;
    while (left_index <= right_index)
    {
        if (left_curr->value == value)
        {
            *index = left_index;
            return left_curr;
        }
        if (right_curr->value == value)
        {
            *index = right_index;
            return right_curr;
        }
        left_curr = left_curr->next;
        right_curr = right_curr->prev;
        left_index += 1;
        right_index -= 1;
    }
    return NULL;
}

int main()
{
    DoublyLinkedList list;
    list.insertFirst(5);
    list.insertFirst(6);
    list.insertLast(3);
    list.showList();
    list.showListReverse();
    list.insertAtIndex(4, 2);
    list.insertLast(2);
    list.insertLast(1);
    list.insertAtIndex(0, 6);
    list.insertAtIndex(7, 0);
    list.showList();
    list.showListReverse();
    list.deleteFirst();
    list.showList();
    list.showListReverse();
    list.deleteLast();
    list.showList();
    list.showListReverse();
    list.deleteAtIndex(3);
    list.showList();
    list.showListReverse();
    int found_index = -1;
    Node *found_node = list.find(4, &found_index);
    if (found_index == -1)
    {
        cout << "Not found. \n";
    }
    else
    {
        cout << "Found: " << found_node->value << " at [" << found_index
             << "] index \n";
    }
    list.update(3, 2);
    list.showList();
    list.showListReverse();

    return 0;
}