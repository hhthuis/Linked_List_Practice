#include <bits/stdc++.h>
using namespace std;

void insert(int* &a,int x,int n)
{
    if (x<=a[0])
    {
        for (int i=n-1;i>=0;i--) a[i+1]=a[i];
        a[0]=x;
        return;
    }
    if (a[n-1]<=x) 
    {
        a[n]=x;
        return;
    } 
    for (int i=1;i<n;i++)
        if (a[i-1]<=x && a[i]>=x)
        {
            for (int j=n;j>=i;j--) a[j+1]=a[j];
            a[i]=x;
            return;
        }
}
int main()
{
    int n;
    int* a=new int[n+1];
    cout << "So phan tu: " << endl;
    cin >> n;
    cout << "Mang da sap xep: " << endl;
    for (int i=0;i<n;i++)
        cin >> a[i];
    cout << "Phan tu can them: ";
    int x;cin >> x;
    insert(a,x,n);
    cout << "Mang sau khi chen: " << endl;
    cout << n << endl;
    for (int i=0;i<=n;i++) cout << a[i] << " ";
}

