#include<cstdio>
int MAX = 0;
int main() {
	freopen("2562.in", "r", stdin);
	int a, idx;
	for (int i = 0; scanf("%d", &a) != EOF; i++) {
		if (MAX < a) {
			MAX = a;
			idx = i + 1;
		}
	}
	printf("%d\n%d", MAX, idx);	
	return 0;
}