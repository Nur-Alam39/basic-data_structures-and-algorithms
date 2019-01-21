#include<bits/stdc++.h>
using namespace std;
int lcs(char *a,char*b,int m,int n)
{
    int L[m+1][n+1],p=0;
    char c[max(m,n)+1];
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
        {
            cout<<a[i-1]<<" "<<b[j-1]<<endl;
            if(i==0||j==0)
                L[i][j]=0;
            else if(a[i-1]==b[j-1])///abcdgh
                ///aedfhr
                {
                    c[p++]=a[i-1];
                    L[i][j]=1+L[i-1][j-1];

                }
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);

        }
        c[p]='\0';
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
            cout<<L[i][j]<<" ";
        cout<<endl;
    }
    printf("LCS : %s\n",c);
    return L[m][n];
}
int main()
{
    char a[100],b[100];
    scanf("%s%s",&a,&b);
    int m,n,l;
    m=strlen(a);
    n=strlen(b);
    l=lcs(a,b,m,n);
    cout<<"Longest common subsequence:"<<l<<endl;
    return 0;
}
