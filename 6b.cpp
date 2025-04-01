#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};
class list_no_tail
{
    node* head;
public:
    list_no_tail(): head(NULL){};
    void insert(int value)
    {
        node* newnode=new node;
        newnode->data=value;
        if (!head || head->data > value)
        {
            newnode->next=head;
            head=newnode;
            return;
        }
        node* temp=head;
        while (temp->next && temp->next->data < value) 
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display()
    {
        node* temp=head;
        while (temp->next)
        {
            cout << temp->data << " -> ";
            temp=temp->next;
        }
        cout << temp->data << " -> NULL" << endl;
    }
};
class list_with_tail
{
    node* head;
    node* tail;
public:
    list_with_tail(): head(NULL), tail(NULL) {}
    void insert(int value)
    {
        node* newnode= new node;
        newnode->data=value;
        if (!head || head->data > value)
        {
            newnode->next=head;
            head=newnode;
            if (!tail) tail=head;
            return;
        }
        node* temp=head;
        while (temp->next && temp->next->data < value)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
        if (!newnode->next)
            tail=newnode;
    }
    void display()
    {
        node* temp=head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    list_no_tail list1;
    list1.insert(1);
    list1.insert(5);
    list1.insert(3);
    list1.insert(4);
    list1.display();
    //////////
    list_with_tail list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(9);
    list2.insert(7);
    list2.display();
    
}