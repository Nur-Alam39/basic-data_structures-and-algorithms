#include<bits/stdc++.h>
#define Max 1000
using namespace std;
int w[Max],c[Max],dp[Max][Max],n,W;
int knapsack(int i,int W)
{
    if(i==n)return 0;
    if(dp[i][W]!=0)return dp[i][W];
    if(W-w[i]>=0)
        dp[i][W]=max(c[i]+knapsack(i+1,W-w[i]),knapsack(i+1,W));
    return dp[i][W];
}
int main()
{
    scanf("%d%d",&n,&W);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&c[i],&w[i]);
    memset(dp,0,sizeof(dp));
    printf("%d\n",knapsack(1,W));
    return 0;
}
