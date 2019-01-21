#include<bits/stdc++.h>
using namespace std;
int dp[2000],c=0;
int fib(int n)
{
    printf("n=%d ",n);
    if(n==0)
        {
            c++;
            return 0;
        }
    else if(n==1)
        {
            c++;
            return 1;
        }
    else if(dp[n]!=-1)
        {
            c++;
            printf("1.%d\n",dp[n]);
            return dp[n];
        }
    else
    {
        dp[n]=fib(n-1)+fib(n-2);
        printf("2.%d\n",dp[n]);
        return dp[n];
    }
}
int main()
{
    for(int i=0; i<2000; i++)
        dp[i]=-1;
    int n;
    scanf("%d",&n);
    fib(n);
    for(int i=2; i<=c; i++)
        printf("%d ",dp[i]);
    return 0;
}
