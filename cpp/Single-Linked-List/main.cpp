#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr)
    {
    }

 

    void insertNode(int value)
    {
        Node *newNode = new Node(value);
        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = nullptr;
        }
        else
        {
            Node *lastNode = head;
            while (lastNode->next != nullptr)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
            newNode->next = nullptr;
        }
    }

    void drop(int value)
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty";
            return;
        }
        Node *current = head;
        Node *previous = head;
        if (current->data == value)
        {
            head = current->next;
            free(current);
            return;
        }
        else
        {
            while (current->data != value)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            free(current);
        }
    }

    void length()
    {
        Node *nodex = head;
        int counter = 0;
        if (head == nullptr)
        {

            cout << "Linked List Is empty";
            return;
        }
        else
        {
            while (nodex != nullptr)
            {
                counter++;
                nodex = nodex->next;
            }
            cout << counter;
        }
    }
    void dropFront()
    {
        Node *header = head;
        if (head == nullptr)
        {
            return;
        }
        if (header->next == nullptr)
        {
            head = nullptr;
            return;
        }
        head = header->next;
        free(header);
    }

    void print()
    {
        Node *currentNode = head;
        if (head == nullptr)
        {
            cout << " Linked List is empty";
            return;
        }
        else
        {
            while (currentNode != nullptr)
            {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
        }
    }

    void dropBack()
    {
        Node *currentNode = head;
        Node *prevouis = nullptr;
        if (head == nullptr)
        {
            cout << "Linked List is Empty";
            return;
        }
        if (currentNode->next == nullptr)
        {
            head = nullptr;
            return;
        }
        while (currentNode->next != nullptr)
        {
            prevouis = currentNode;
            currentNode = currentNode->next;
        }
        prevouis->next = nullptr;
        free(currentNode);
    }
       ~LinkedList()
    {
        while (head)
        {
            Node *cur(head->next);
            delete head;
            head = cur;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
   /*  
            More Method 
    list.drop(5);
    list.dropBack();
    list.dropFront();
    list.length();
   
   */ 

  
    list.print();


}