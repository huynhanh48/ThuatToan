#include<iostream>
using namespace std;
void insertsort(int a[], int n)
{
    //int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n-1; i++)
    {
        int temp = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[temp])
            {
                temp=j;
            }
        }
        swap(a[i],a[temp]);
    }
    
}
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>a[i];
    }
    insertsort(a,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
}
