#include<bits/stdc++.h>
using namespace std;
int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		if (n % 2 == 0) {
			printf("%d\n", n / 2);
		}
		else {
			printf("%d\n" , (n - 1) / 2);
		}
	}
	retrun 0;
}
