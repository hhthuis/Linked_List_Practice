#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node* next;
};

class linkedlist 
{
    node* header; 
public:
    linkedlist() 
    {
        header = new node;
        header->next = NULL;
    }

    void insert(int value) 
    {
        node* newnode = new node;
        newnode->data = value;
        newnode->next = NULL;

        if (!header->next) 
        {
            header->next = newnode; 
            *((node**)(&header->data)) = newnode; // Cập nhật byte đầu (địa chỉ node cuối)
            return;
        }

        node* temp = header->next;
        node* prev = header; 
        while (temp && temp->data < value) 
        {
            prev = temp;
            temp = temp->next;
        }

        newnode->next = temp;
        prev->next = newnode;

        if (!newnode->next) 
            *((node**)(&header->data)) = newnode;
    }
    void display() 
    {
        node* temp = header->next; 
        while (temp) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    //Hiển thị địa chỉ node cuối
    void display_tail_address() 
    {
        node* tail = *((node**)(&header->data)); // Lấy địa chỉ node cuối từ Header node
        if (tail) 
            cout << tail << endl;
    }
};

int main() {
    linkedlist list;

    cout << "Them vao danh sach:" << endl;
    list.insert(10);
    list.insert(20);
    list.insert(5);
    list.insert(15);
    list.display();

    cout << "Hien thi dia chi node cuoi:" << endl;
    list.display_tail_address();
    return 0;
}