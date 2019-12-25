#include<cstdio>
int main() {
	int h, m;
	scanf("%d%d", &h, &m);
	if (m - 45 < 0) {
		if (h == 0)printf("23 %d\n", 60 - (45 - m));
		else printf("%d %d\n", h - 1, 60 - (45 - m));
	}
	else printf("%d %d", h, m - 45);
	return 0;
}