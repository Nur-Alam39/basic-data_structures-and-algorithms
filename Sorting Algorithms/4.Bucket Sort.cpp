#include<bits/stdc++.h>
using namespace std;
void bucket_sort(float a[],int n)
{
    int index;
    vector<float>bucket[n];
    for(int i=0; i<n; i++)
    {
        index=10*a[i];
        bucket[index].push_back(a[i]);
    }
    for(int i=0; i<n; i++)
        sort(bucket[i].begin(),bucket[i].end());
    printf("Sorted list :\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<bucket[i].size(); j++)
            printf("%.2f ",bucket[i][j]);
    printf("\n\n");
}
int main()
{
    float a[10]= {0.17,0.87,0.91,0.76,0.12,0.56,0.45,0.34,0.39,0.77};
    int n=10;
    cout<<setw(40)<<"Bucket sort"<<"\n\nGiven list :\n";
    for(int i=0; i<n; i++)
        printf("%.2f ",a[i]);
    printf("\n\n");
    bucket_sort(a,n);
    return 0;
}
