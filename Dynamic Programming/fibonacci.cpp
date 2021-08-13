#include<bits/stdc++.h>
using namespace std;
int function_call_count = 0;


int fib(int n) {
    printf("Function is called %d times\n", ++function_call_count);
    if (n <= 1) return n;
    int a = fib(n -1);
    int b = fib(n - 2);
    return a + b;

}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}
