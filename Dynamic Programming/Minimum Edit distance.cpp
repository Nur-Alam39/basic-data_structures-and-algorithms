#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="aaa",b="aabaaaa";

    int s1,s2;
    s1=a.size();
    s2=b.size();
    int d[s1+1][s2+1];
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s2;j++)
        {
            cout<<a[i-1]<<" "<<b[j-1]<<endl;
            if(i==0)
                d[i][j]=j;
            else if(j==0)
                d[i][j]=i;
            else if(a[i-1]==b[j-1])
                d[i][j]=d[i-1][j-1];
            else
                {
                    int f;
                    f=min(d[i-1][j],d[i-1][j-1]);
                    d[i][j]=1+min(f,d[i][j-1]);
                }
        }
    }
    cout<<a<<endl<<b<<endl<<d[s1][s2];
    return 0;
}
