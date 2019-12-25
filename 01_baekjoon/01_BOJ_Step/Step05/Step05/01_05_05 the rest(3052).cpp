#include<cstdio>
int n[42];
int main() {
	int a, b, cnt = 10;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		b = a % 42;
		n[b]++;
		if (n[b] > 1)cnt--;
	}
	printf("%d", cnt);
	return 0;
}