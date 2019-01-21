#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];
int segtree[3*mx];
void constructTree(int node,int b,int e)
{
    if(b==e)
    {
        segtree[node]=arr[b];
        return ;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    constructTree(left,b,mid);
    constructTree(right,mid+1,e);
    segtree[node]=segtree[left]+segtree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(b>=i&&e<=j)return segtree[node];
    if(i>e||j<b)return 0;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
    return p+q;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(b>=i&&e<=i)
    {
        segtree[node]=newvalue;
        return;
    }
    if(b>i||e<i)return ;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    segtree[node]=segtree[left]+segtree[right];
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&arr[i]);
    constructTree(1,1,n);
    for(int i=1; i<=n*3; i++)printf("%d ",segtree[i]);
    for(int i=1; i<=100; i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",query(1,1,n,x,y));
    }
    return 0;
}
