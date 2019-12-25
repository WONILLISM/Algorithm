#include<cstdio>
int n;
void hanoi(int num, int start, int mid, int defi) {
	if (num == 1)printf("%d %d\n", start, defi);
	else {
		hanoi(num - 1, start, defi, mid);
		printf("%d %d\n", start, defi);
		hanoi(num - 1, mid, start, defi);
	}
}
int main() {
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoi(n, 1, 2, 3);
	return 0;
}