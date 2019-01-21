#include<bits/stdc++.h>
using namespace std;
#define M 10000
#define Int input_int()
int a[M],block[1000];
int bl_size;
int input_int()
{
    int a;
    scanf("%d",&a);
    return a;
}
void update(int value,int idx)
{
    int bl_idx=idx/bl_size;
    block[bl_idx]+=a[idx]-value;
    a[idx]=value;
}
int query(int l,int r)
{
    int sum=0;
    while(l<r && l%bl_size!=0 && l!=0)sum+=a[l++];
    while(l+bl_size<=r)sum+=block[l/bl_size],l+=bl_size;
    while(l<=r)sum+=a[l++];
    return sum;
}
void preprocess(int n)
{
   int bl_idx=0;
   for(int i=0;i<n;i++)
   {
       if(i%bl_size==0)bl_idx++;
       block[bl_idx]+=a[i];
   }
   for(int i=0;i<=bl_size;i++)
    printf("%d ",block[i]);
}
int main()
{
    int n=Int;
    bl_size=sqrt(n);
    for(int i=0; i<n; i++)a[i]=Int;
    preprocess(n);
    int l,r,m=Int;
    for(int i=0; i<m; i++)
    {
        l=Int,r=Int;
        printf("%d\n",query(l,r));
    }
    return 0;
}

