#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertNode(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            newNode->next = nullptr;
        }
    }
    void print()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *current(head);
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void drop (int value) {
             if(head->data == value && head->next != nullptr)
             {
                    head = head->next;
                    return;
             }
             if(head->data == value && head->next == nullptr)
             {
                head  = nullptr;
                return;
             }
             // else
              Node * current = head;
              while (current->data != value )    
              {
                current = current->next;    
              }
               Node * previous  = current->prev;
              if(current->next == nullptr)
              {
                previous = current->prev;
                previous->next = nullptr;
                return;
              }
             
              previous->next = current->next;
              current->next->prev = previous->next;
              delete current;
    }


    ~LinkedList()
    {
        Node *cur(head->next);
        delete[] head;
        head = cur;
    }
};

int main()
{

    LinkedList list;

    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.insertNode(40);

    list.drop(20);
    list.print();
}