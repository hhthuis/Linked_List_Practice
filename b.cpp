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
};
struct linked_list
{
    node* head;
    node* tail;
};
linked_list array_to_linked_list(student* students,int n)
{
    linked_list list_with_tail;
    list_with_tail.head=NULL;
    list_with_tail.tail=NULL;
    for (int i=0;i<n;i++)
    {
        node* newnode= new node;
        newnode->data=students[i];
        newnode->next=NULL;
        if (!list_with_tail.head) 
        {
            list_with_tail.head=newnode;
            list_with_tail.tail=newnode;
        }
        else
        {
            list_with_tail.tail->next=newnode;
            list_with_tail.tail=newnode;
        }
    }
    return list_with_tail;
};
student* linked_list_to_array(linked_list& list_with_tail,int& n)
{
    node* temp= list_with_tail.head;
    student* newstudents=new student[n];
    int i=0;
    while (temp!=NULL)
    {
        newstudents[i]=temp->data;
        temp=temp->next;
        i++;
    }
    return newstudents;

}
void print_linked_list(linked_list& list_with_tail)
{
    
    node* temp=list_with_tail.head;
    while (temp!=NULL)
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
    linked_list list_with_tail=array_to_linked_list(students,n);
    print_linked_list(list_with_tail);
    ///////////
    delete[] students;
    cout << endl;
    //////////Chuyen DSLK thanh mang dong
    cout << "Danh sach sinh vien chuyen thanh mang dong: " << endl;
    student* newstudents=linked_list_to_array(list_with_tail,n);
    for (int i=0;i<n;i++)
        cout << "Sinh vien " << i+1 << " co ten la: " << newstudents[i].name << " va MSSV la: " << newstudents[i].MSSV<<endl;

}
