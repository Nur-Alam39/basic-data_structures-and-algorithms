#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={-1, 3, -5, 4, 6, -1, 2, -7, 13, -3};///{3,7,-4,6,2,-9,6,4,8,12,34,-2,4,7,-1};
    int sum=0,maxsum=0,start=0,cur_st=0,end_in=0;
    for(int i=0;i<10;i++)
    {
        sum+=a[i];
        if(sum>maxsum)
        {
            printf("Sum = %d\n",sum);
            maxsum=sum;
            start=cur_st;
            end_in=i;
        }
        if(sum<0)
        {
            sum=0;
            cur_st=i+1;
        }
    }
    printf("Maxsum = %d\nStart index = %d End index = %d\n",maxsum,start,end_in);
    for(int i=start;i<=end_in;i++)
        printf("%d ",a[i]);
    return 0;
}
