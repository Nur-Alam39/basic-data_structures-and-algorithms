#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=10,m,index,j,d_n,i,k;
    int a[10]= {710,195,437,3,812,715,582,340,385,34};
    vector<int>d;
    m=a[0];
    for(i=1; i<n; i++)
        if(a[i]>m)
            m=a[i];
    cout<<setw(40)<<"Radix sort"<<"\n\nGiven list :\n";
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    while(m!=0)
    {
        d.push_back(m%10);
        m/=10;
    }
    d_n=d.size();
    printf("\n\n");
    for(i=1; i<=d_n; i++)
    {
        vector<int>c[11];
        for(j=0; j<n; j++)
        {
            int p=1,f,q=a[j];
            while(p<=i)
            {
                f=q%10;
                q/=10;
                p++;
            }
            c[f].push_back(a[j]);
        }
        k=0;
        for(int x=0; x<11; x++)
            for(j=0; j<c[x].size(); j++)
                a[k++]=c[x][j];
    }
    printf("Sorted list :\n");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
