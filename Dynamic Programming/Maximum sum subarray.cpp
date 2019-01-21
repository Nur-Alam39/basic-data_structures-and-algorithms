#include<bits/stdc++.h>
using namespace std;
void contiguousSubArrayWithLargestsum(int a[], int size)
{

    int startIndex = 0, endIndex = 0;
    int index;
    int currStartIndex = 0;

    int maxSum = 0;
    int currentSum = 0;

    for(index = 0 ; index < size; index++)
    {
        currentSum  = currentSum + a[index];
        /// case 1 : When ith element can be included
        /// Change the end index and also update the start index.
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
            endIndex = index;
            startIndex = currStartIndex;
        }
        ///*case 2 : When ith index cannot be included and
        ///we need to start with i+1 index. till now our max sum
        ///and start and end index of that sum remain same *///
        if(currentSum < 0)
        {
            currStartIndex = index + 1;
            currentSum = 0;
        }
    }
    printf("\nMaximum Sum : %d", maxSum);
    printf("\nBetween (%d, %d)", startIndex, endIndex);
}

///Driver program
int main()
{
    int intArr[] = {-1, 3, -5, 4, 6, -1, 2, -7, 13, -3};
    int size = sizeof(intArr)/sizeof(intArr[0]);
    contiguousSubArrayWithLargestsum(intArr, size);
    return 0;
}

