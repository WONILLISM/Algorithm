#include<cstdio>
int MAX = -1000000;
int min = 1000000;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (MAX < a)MAX = a;
		if (min > a)min = a;
	}
	printf("%d %d\n", min, MAX);
	return 0;
}