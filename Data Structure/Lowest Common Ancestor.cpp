#include<bits/stdc++.h>
#define M 100000
using namespace std;
vector<int>g[M];
int T[M],L[M],P[M][30];
void dfs(int u,int v,int l)
{
    T[v]=u;
    L[v]=l;
    for(int i=0; i<(int)g[v].size(); i++)
    {
        int c=g[v][i];
        if(c==u)continue;
        dfs(v,c,l+1);
    }
}
void init_lca(int n)
{
    memset(P,-1,sizeof(P));
    for(int i=0; i<n; i++)P[i][0]=T[i];
    for(int j=1; 1<<j<n; j++)
        for(int i=0; i<n; i++)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}
int query(int n,int p,int q)
{
    if(l[p]<l[q])swap(p,q);
}
int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    dfs(-1,0,0);
    init_lca(9);
    return 0;
}
