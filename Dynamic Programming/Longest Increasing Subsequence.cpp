#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],lis[n],m=0,t;
    vector<int>sol;
    for(int i=0; i<n; i++)lis[i]=1;
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(a[j]<a[i]&&lis[i]<lis[j]+1)lis[i]=lis[j]+1;
    for(int i=0; i<n; i++)
        if(lis[i]>m)
            m=lis[i];
    t=m;
    printf("length=%d\n",m);
    for(int i=n-1; i>=0; i--)
    {
        if(lis[i]==t)
        {
            sol.push_back(a[i]);
            t--;
        }
    }
    for(int i=sol.size()-1; i>=0; i--)printf("%d ",sol[i]);
    return 0;
}
