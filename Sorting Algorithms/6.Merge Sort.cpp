#include<bits/stdc++.h>
using namespace std;
void merge_all(int a[],int l,int m,int r)
{
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];
    for(int i=0; i<n1; i++)
        L[i]=a[l+i],cout<<L[i]<<" ";
    cout<<"\n";
    for(int i=0; i<n2; i++)
        R[i]=a[m+i+1],cout<<R[i]<<" ";
    cout<<"\n";
    i=j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
            a[k++]=L[i++];
        else
            a[k++]=R[j++];
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n1)
        a[k++]=R[j++];
}
void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        printf("l = %d m = %d r = %d\n",l,m,r);
        merge_sort(a,l,m);
        printf("l = %d m = %d r = %d\n",l,m,r);
        merge_sort(a,m+1,r);
        merge_all(a,l,m,r);
    }
}
int main()
{
    int a[10] = {12, 11, 13, 5, 6, 7,3,8,4,9};
    cout<<setw(40)<<"Merge sort"<<"\n\nGiven list :\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    merge_sort(a,0,10-1);
    cout<<"\n\nSorted list :\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}

