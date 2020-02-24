#include<bits/stdc++.h>
using namespace std;
int pArtition(int a[],int s,int e)
{
    int pivot=a[e],pIndex=s,i;
    for(i=s; i<e; i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex],a[i]);
    return pIndex;
}
void quicksort(int a[],int s,int e)
{
    if(s<e)
    {
        int pIndex=pArtition(a,s,e);
        quicksort(a,s,pIndex-1);
        quicksort(a,pIndex+1,e);
    }
}
int main()
{
    int n=10,a[10]= {7,3,9,12,2,8,13,6,11,5};
    printf("Given list : ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    quicksort(a,0,n-1);
    printf("\nSorted list : ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;

}
