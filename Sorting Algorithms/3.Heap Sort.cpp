#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest=i,l,r;
    l=2*i+1;
    r=2*i+2;
    printf("before n=%d largest=%d l=%d r=%d\n",n,largest,l,r);
    if(l<n&&arr[l]>arr[largest])
    {
        printf("F:");
        largest=l;
    }
    if(r<n&&arr[r]>arr[largest])
    {
        printf("S:");
        largest=r;
    }
    printf("after n=%d largest=%d l=%d r=%d\n",n,largest,l,r);
    printf("arr[l]=%d arr[r]=%d arr[largest]=%d\n\n",arr[l],arr[r],arr[largest]);
    if(largest!=i)
    {
                printf("fast Here\n");
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    int c=1;
    for(int i=n/2-1; i>=0; i--)
    {
        printf("[n/2]=%d\n\n",c++);
        heapify(arr,n,i);
    }
    for(int i=n-1; i>=0; i--)
    {
        printf("last Here\n");
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main()
{
    int arr[6]= {12,11,13,5,6,7},n=6;
    heapSort(arr,n);
    cout<<"Sorted array is \n";
    for(int i=0; i<6; ++i)
        cout<<arr[i]<<" ";
    return 0;
}
