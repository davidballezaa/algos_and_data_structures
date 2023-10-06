#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *start;
    int size;

    LinkedList()
    {
        this->start = NULL;
        this->size = 0;
    }

    int getSize();

    void showList();

    void insertFirst(int value);

    void insertLast(int value);

    void insertAtIndex(int value, int index);

    void update(int value, int index);

    void deleteFirst();

    void deleteLast();

    void deleteAtIndex(int index);

    Node *find(int value, int *index);
};

int LinkedList::getSize() { return this->size; }

void LinkedList::showList()
{
    cout << "List size: " << this->size << '\n';
    Node *curr = this->start;
    for (int i = 0; i < this->size; i++)
    {
        cout << "Element [" << i << "]: " << curr->value << '\n';
        curr = curr->next;
    }
}

void LinkedList::insertFirst(int value)
{
    Node *new_node = new Node(value);
    new_node->next = this->start;
    this->start = new_node;
    this->size += 1;
}

void LinkedList::insertLast(int value)
{
    Node *new_node = new Node(value);
    if (this->size == 0)
    {
        this->start = new_node;
    }
    else
    {
        Node *curr = this->start;
        // at the end of the loop, curr will be the last item
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    this->size += 1;
}

void LinkedList::insertAtIndex(int value, int index)
{
    if (index == 0)
    {
        LinkedList::insertFirst(value);
    }
    else if (index == this->size)
    {
        LinkedList::insertLast(value);
    }
    else
    {
        Node *new_node = new Node(value);
        int index_counter = 0;
        Node *curr = this->start;
        // Loop through whole list
        // Stop loop when reaching one element before index
        while (curr->next != NULL)
        {
            if (index_counter == index - 1)
            {
                new_node->next = curr->next;
                curr->next = new_node;
                break;
            }
            index_counter += 1;
            curr = curr->next;
        }
        this->size += 1;
    }
}

void LinkedList::update(int value, int index)
{
    Node *curr = this->start;
    int curr_index = 0;
    // Loop through all list
    // Curr will finish at NULL
    while (curr != NULL)
    {
        if (curr_index == index)
        {
            curr->value = value;
            break;
        }
        curr = curr->next;
        curr_index += 1;
    }
}

void LinkedList::deleteFirst()
{
    Node *temp = this->start;
    this->start = temp->next;
    this->size -= 1;
    delete temp;
}

void LinkedList::deleteLast()
{
    if (this->size == 1)
    {
        LinkedList::deleteFirst();
    }
    else
    {
        Node *curr = this->start;
        // loop until we reach the prev from last element
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }

        delete curr->next;
        curr->next = NULL;
        this->size -= 1;
    }
}

void LinkedList::deleteAtIndex(int index)
{
    if (index == 0)
    {
        LinkedList::deleteFirst();
    }
    else if (index == this->size - 1)
    {
        LinkedList::deleteLast();
    }
    else
    {
        Node *prev = NULL;
        Node *curr = this->start;
        int curr_index = 0;
        // Loop through all list.
        // Curr will finish at NULL.
        // Stop on the node to delete
        while (curr != NULL)
        {
            if (curr_index == index)
            {
                prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
            curr_index += 1;
        }
        this->size -= 1;
    }
}

Node *LinkedList::find(int value, int *index)
{
    Node *curr = this->start;
    int curr_index = 0;
    // Loop through all list
    // Curr will finish at NULL.
    while (curr != NULL)
    {
        if (curr->value == value)
        {
            *index = curr_index;
            break;
        }
        curr = curr->next;
        curr_index += 1;
    }
    return curr;
}

int main()
{
    LinkedList list;
    list.insertFirst(5);
    list.insertFirst(6);
    list.insertLast(3);
    list.insertAtIndex(4, 2);
    list.insertLast(2);
    list.insertLast(1);
    list.showList();
    list.deleteFirst();
    list.deleteLast();
    list.showList();
    list.deleteAtIndex(2);
    list.showList();
    int found_index;
    Node *found_node = list.find(4, &found_index);
    cout << "Found: " << found_node->value << " at [" << found_index << "] index \n";
    list.update(3, 2);
    list.showList();

    return 0;
}