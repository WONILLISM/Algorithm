#include<cstdio>
int main() {
	int a;
	scanf("%d", &a);
	printf("%d", (a % 4 == 0 && a % 100 != 0) ? 1 : (a % 4 == 0 && a % 400 == 0) ? 1 : 0);
}