#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100]="abcdgh",b[100]="aedfhr";
    int l1,l2,p=0;
    //scanf("%s%s",&a,&b);
    l1=strlen(a),l2=strlen(b);
    int dp[l1+1][l2+1];
    char c[max(l1,l2)+1];
    for(int i=0; i<=l1; i++)
        for(int j=0; j<=l2; j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                c[p++]=a[i-1];
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    c[p]='\0';
    printf("LCS Length: %d\nLCS : %s\n",dp[l1][l2],c);
    return 0;
}
