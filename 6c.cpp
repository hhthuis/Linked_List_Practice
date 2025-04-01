#include <bits/stdc++.h>
using namespace std;


struct node 
{
    int data;
    node* next;
};

class linkedlist_notail 
{
    node* head; 

public:
    linkedlist_notail() : head(new node)
    {
        head->next = NULL;
    }

    void insert(int value) 
    {
        node* newnode = new node;
        newnode->data = value;
        newnode->next = NULL;

        node* temp = head; 
        while (temp->next && temp->next->data < value) 
            temp = temp->next; 

        newnode->next = temp->next; 
        temp->next = newnode;
    }


    void display() 
    {
        node* temp = head->next; 
        while (temp) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class linkedlist_tail 
{
    node* head; 
    node* tail; 

public:
    linkedlist_tail() : head(new node), tail(head)
    { 
        head->next = NULL;
    }
    void insert(int value) 
    {
        node* newnode = new node;
        newnode->data = value;
        newnode->next = NULL;

        node* temp = head; 
        while (temp->next && temp->next->data < value) 
            temp = temp->next; 

        newnode->next = temp->next; 
        temp->next = newnode;

        if (!newnode->next)  
            tail = newnode;
    }
    void display() 
    {
        node* temp = head->next; 
        while (temp) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() 
{
    linkedlist_notail list1;
    list1.insert(10);
    list1.insert(20);
    list1.insert(5);
    list1.insert(15);
    list1.display();

    /////////
    linkedlist_tail list2;
    list2.insert(1);
    list2.insert(3);
    list2.insert(2);
    list2.insert(4);
    list2.display();

    return 0;
}