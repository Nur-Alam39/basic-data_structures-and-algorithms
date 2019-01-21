#include<bits/stdc++.h>
#define Max 1000
using namespace std;
int w[Max],c[Max],res[Max][Max],n,W;
char vis[Max][Max];
int knapsack(int i,int W)
{
    if(W<0)return -10000000;
    if(i==n)return 0;
    if(vis[i][W]==1)return res[i][W];
    vis[i][W]=1;
    int res1,res2;
    res1=knapsack(i+1,W-w[i])+c[i];
    res2=knapsack(i+1,W);
    res[i][W]=max(res1,res2);
    return res[i][W];
}
int main()
{
    scanf("%d%d",&n,&W);
    for(int i=0; i<n; i++)
        scanf("%d%d",&w[i],&c[i]);
    memset(vis,-1,sizeof(vis));
    printf("%d",knapsack(0,W));
    return 0;
}
