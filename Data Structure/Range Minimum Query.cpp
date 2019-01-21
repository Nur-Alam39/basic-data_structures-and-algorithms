#include<bits/stdc++.h>
using namespace std;
const int k=16,N=1e5;
long long sparse[N][k+1];
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    ///build sparse table
    for(int i=0; i<n; i++)
        sparse[i][0]=a[i];
    for(int j=1; j<=k; j++)
        for(int i=0; i<=n-(1<<j); i++)
            sparse[i][j]=min(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
    ///queries
    int q,l,r;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        long long ans=1e5+5;
        scanf("%d%d",&l,&r);
        for(int j=k; j>=0; j--)
        {
            if(l+(1<<j)-1<=r)
            {
                ans=min(ans,sparse[l][j]);
                l+=(1<<j);
            }
        }
         printf("%lld\n",ans);
    }
    return 0;
}

