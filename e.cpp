#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int MSSV;
};
struct node
{
    student data;
    node* next;
    node* prev;
};
struct doubly_circular_linked_list
{
    node* head;
};
doubly_circular_linked_list array_to_linked_list(student* students,int n)
{
    doubly_circular_linked_list list;
    list.head=NULL;
    node* temp=NULL;
    for (int i=0;i<n;i++)
    {
        node* newnode= new node;
        newnode->data=students[i];
        newnode->next=NULL;
        newnode->prev=NULL;

        if (!list.head) list.head=newnode;
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
        }
        temp=newnode;
    }
    if (temp!=NULL&&list.head!=NULL)
    { 
        temp->next=list.head;
        list.head->prev=temp;
    }
    return list;
};
student* linked_list_to_array(doubly_circular_linked_list& list,int n)
{
    node* temp= list.head;
    student* newstudents=new student[n];
    int i=0;
    do 
    {
        newstudents[i]=temp->data;
        temp-temp->next;
        i++;
    }
    while (temp!=list.head);
    return newstudents;

}
void print_linked_list(doubly_circular_linked_list& list)
{
    
    node* temp=list.head;
    while (temp->next!=list.head)
    {
        cout << temp->data.name << " - " << temp->data.MSSV << endl;
        temp=temp->next;
    }
}
int main()
{
    cout << "Nhap so sinh vien: " << endl;
    int n;cin >> n;
    ////////////
    student* students=new student[n];
    for (int i=0;i<n;i++)
    {
        cout << "Nhap ten sinh vien thu " << i+1 << " : "<<endl;
        cin.ignore();
        getline(cin,students[i].name);
        cout << "Nhap MSSV: "<<endl;
        cin >> students[i].MSSV;
    }
    cout << "Danh sach sinh vien trong mang dong: " << endl;
    for (int i=0;i<n;i++) 
        cout << "Sinh vien " << i+1 << " co ten la: " << students[i].name << " va MSSV la: " << students[i].MSSV<<endl;
    cout << endl;
    ///////////Chuyen mang dong vao DSLK
    cout << "Danh sach sinh vien chuyen thanh DSLK: " << endl;
    doubly_circular_linked_list list=array_to_linked_list(students,n);
    print_linked_list(list);
    ///////////
    delete[] students;
    cout << endl;
    //////////Chuyen DSLK thanh mang dong
    cout << "Danh sach sinh vien chuyen thanh mang dong: " << endl;
    student* newstudents=linked_list_to_array(list,n);
    for (int i=0;i<n;i++)
        cout << "Sinh vien " << i+1 << " co ten la: " << newstudents[i].name << " va MSSV la: " << newstudents[i].MSSV<<endl;

}
