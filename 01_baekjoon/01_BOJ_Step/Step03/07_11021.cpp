#include<cstdio>
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", i + 1, a + b);
	}
	return 0;
}