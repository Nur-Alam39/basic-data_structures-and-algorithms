/*DP-01: Top down - Memorization*/

#include<bits/stdc++.h>
using namespace std;
int dp[100] = {-1};
int function_call_count = 0;

void initialize() {
    for (int i = 0; i < 100; i++) dp[i] = -1;
}

int fib(int n) {
    printf("Function is called %d times\n", ++function_call_count);
    if (n <= 1) return n;

    int a, b;

    if (dp[n - 1] == -1) {
        a = fib(n - 1);
    }
    else a = dp[n - 1];

    if (dp[n - 2] == -1) {
        b = fib(n - 2);
    }
    else b = dp[n - 2];

    dp[n] = a + b;

    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    initialize();
    printf("%d\n", fib(n));
    return 0;
}
