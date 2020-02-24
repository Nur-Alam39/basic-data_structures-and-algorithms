#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[15]= {6,3,8,11,3,4,6,9,2,11,13,2,4,0,3},n=15,i,m,j,sm;
    m=a[0];
    printf("Given list : ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=1; i<n; i++)
        if(a[i]>m)
            m=a[i];
    int b[m+1];
    for(i=0; i<=m; i++)
        b[i]=0;
    for(i=0; i<15; i++)
        b[a[i]]++;
    for(i=1; i<=m; i++)
        b[i]=b[i-1]+b[i];
    sm=b[m];
    int c[16];
    for(i=0; i<15; i++)
    {
        c[b[a[i]]]=a[i];
        b[a[i]]--;
    }
    printf("\nSorted list : ");
    for(i=1; i<=sm; i++)
        printf("%d ",c[i]);
    printf("\n");
    return 0;
}
