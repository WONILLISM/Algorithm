#include<cstdio>
int D[10001];
int main() {
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		D[a]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < D[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}