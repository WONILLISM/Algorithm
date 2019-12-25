#include<cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n%d\n%d\n%d\n", a*(b % 10), a*((b / 10) % 10), a*(b / 100), a*b);
}
//int main() {
//	int a, b, c[3];
//	scanf("%d%d", &a, &b);
//	c[0] = a * (b % 10), b /= 10;
//	c[1] = a * (b % 10), b /= 10;
//	c[2] = a * (b % 10); b = 0;
//	for (int i = 0; i < 3; i++) {
//		printf("%d\n", c[i]);
//		for (int j = 0; j < i; j++)
//			c[i] *= 10;
//		b += c[i];
//	}
//	printf("%d", b);
//	return 0;
//}
