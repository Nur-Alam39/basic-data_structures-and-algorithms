#include<bits/stdc++.h>
using namespace std;
#define M 500
#define Int input_int()
int input_int()
{
    int a;
    scanf("%d",&a);
    return a;
}
int sparse[M][M];
int rmq(int low,int high,int a[])
{
    int l=low+high-1;
    int k=log(l);
    return min(a[sparse[low][k]],a[sparse[low+l-(int)pow(2,k)][k]]);
}
void preprocess(int n,int a[])
{
    for(int i=0; i<n; i++)sparse[i][0]=i;
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=0; (i+(1<<j)-1)<n; i++)
        {
            if(a[sparse[i][j-1]]<a[sparse[i+(1<<(j-1))][j-1]])
                sparse[i][j]=sparse[i][j-1];
            else
                sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }
}
int main()
{
    int n=Int;
    int a[n];
    for(int i=0; i<n; i++)a[i]=Int;
    preprocess(n,a);
    int l,r,m=Int;
    for(int i=0; i<m; i++)
    {
        l=Int,r=Int;
        printf("%d\n",rmq(l,r,a));
    }
    return 0;
}


