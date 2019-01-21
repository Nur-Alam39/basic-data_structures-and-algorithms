#include<bits/stdc++.h>
using namespace std;
#define M 10000
#define Int input_int()
int input_int()
{
    int a;
    scanf("%d",&a);
    return a;
}
int a[M];
int lookup[M][M];
void preprocess(int n)
{
    for(int i=0; i<n; i++)lookup[i][i]=i;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            if(a[lookup[i][j-1]]<a[j])
                lookup[i][j]=lookup[i][j-1];
            else  lookup[i][j]=j;
    }
}
int main()
{
    int n=Int;
    for(int i=0; i<n; i++)a[i]=Int;
    preprocess(n);
    int l,r,m=Int;
    for(int i=0; i<m; i++)
    {
        l=Int,r=Int;
        printf("%d\n",a[lookup[l][r]]);
    }
    return 0;
}
