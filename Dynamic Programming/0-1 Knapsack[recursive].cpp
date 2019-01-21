#include<bits/stdc++.h>
#define Max 1000
using namespace std;
int w[Max],c[Max],W,n;
int knapsack(int W,int n)
{
    printf("%d:\n",n);
    if(n==0||W==0)return 0;
    if(w[n-1]>W)return knapsack(W,n-1);
    else
    {
        int res1=c[n-1]+knapsack(W-w[n-1],n-1);
        int res2=knapsack(W,n-1);
        return max(res1,res2);
    }
}
int main()
{
    scanf("%d%d",&n,&W);
    for(int i=0; i<n; i++)
        scanf("%d%d",&w[i],&c[i]);
    printf("%d\n",knapsack(W,n));
    return 0;
}
