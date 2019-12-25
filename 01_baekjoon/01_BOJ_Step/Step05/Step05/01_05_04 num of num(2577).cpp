#include<cstdio>
int c[10];
int main() {
	int a, b = 1, d = 1, e;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a);
		b *= a;
	}
	e = b;
	while (e) {
		e /= 10;
		d *= 10;
	}
	d /= 10;
	while (d) {
		int k = b / d;
		c[k]++;
		b = b - k * d;
		d /= 10;
	}
	for (int i = 0; i < 10; i++) printf("%d\n", c[i]);
	return 0;
}