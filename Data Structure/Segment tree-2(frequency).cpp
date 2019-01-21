#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
#define S 100000
#define MAX2 1000000
int N,Q,cnt[MAX],start[MAX],n[MAX],sTree[MAX2];
void makeTree(int nodeNumber,int s,int e)
{
    if(s==e)
    {
        sTree[nodeNumber]=cnt[n[s]];
        return;
    }
    int mid=(s+e)/2;
    int left=(2*nodeNumber)+1;
    int right=(2*nodeNumber)+2;
    makeTree(left,s,mid);
    makeTree(right,mid+1,e);
    printf("%d %d %d\n",sTree[left],sTree[nodeNumber],sTree[right]);
    if(sTree[left]>=sTree[right])sTree[nodeNumber]=sTree[left];
    else sTree[nodeNumber]=sTree[right];
}
int makeQuery( int nodeNumber,int s,int e,int r1,int r2)
{
    int ret ;
    if(e<r1||s>r2)return -1;
    if(s>=r1&&e<=r2)return sTree[nodeNumber];
    int mid=(s+e)/2;
    int left=(2*nodeNumber)+1;
    int right=(2*nodeNumber)+2;
    int v1=makeQuery(left,s,mid,r1,r2);
    int v2=makeQuery(right,mid+1,e,r1,r2);
    if(v1==-1||v1<v2)return v2;
    else if(v2==-1||v1>=v2)return v1;
}
int main()
{
    int i,j;
    while(scanf("%d",&N)==1)
    {
        if(N==0)break;
        scanf("%d",&Q);
        memset(cnt,0,sizeof(cnt));
        memset(start,-1,sizeof(cnt));
        for(i=0;i<N;i++)
        {
            scanf("%d",&n[i]);
            n[i]+=S;
            cnt[n[i]]++;
            if(cnt[n[i]]==1)start[n[i]]=i;
        }
        makeTree(0,0,N-1);
        int a,b;
        for(i=0;i<Q;i++)
        {
            scanf("%d %d",&a,&b);
            a--;
            b--;
            if(n[a]==n[b])
            {
                printf("%d\n",b-a+1);
                continue;
            }
            int ans ;
            int v1=cnt[n[a]]-a+start[n[a]];
            int v2=b-start[n[b]]+1;
            if(v1>v2)ans=v1;
            else ans=v2;
            int r1=start[n[a]]+cnt[n[a]];
            int r2=start[n[b]]-1;
            if(r1<=r2)
            {
                int var=makeQuery(0,0,N-1,r1,r2);
                if(var>ans)ans=var;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
