#include<bits/stdc++.h>
using namespace std;
int dp[200][200];
long long nCr(int n,int r)
{
    if(r==1)return n;
    if(n==r)return 1;
    if(dp[n][r]!=-1)return dp[n][r];
    return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    memset(dp,-1,sizeof(dp));
    printf("%d",nCr(n,r));
    return 0;
}
