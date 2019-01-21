#include<bits/stdc++.h>
using namespace std;
int dp[100][100],n,c,cost[100],weight[100];
int f(int i,int w)
{
    if(i==n+1)
        return 0;
    else if(dp[i][w]!=-1)
        return dp[i][w];
    else
    {
        int p1,p2;
        p1=p2=0;
        if(w+weight[i]<=c)
            p1=cost[i]+f(i+1,w+weight[i]);
        else
            p1=0;
        p2=f(i+1,w);
        dp[i][w]=max(p1,p2);
        return dp[i][w];
    }
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        dp[i][j]=-1;
    for(int i=0;i<n;i++)
        scanf("%d%d",&weight[i],&cost[i]);
    printf("%d\n",f(1,0));
    return 0;
}

