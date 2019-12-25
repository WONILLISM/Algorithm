#include <cstdio>
#include <algorithm>
using namespace std;

int n, lis[1001], len, num;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		auto lowerPos = lower_bound(lis, lis + len, num);
		if (*lowerPos == 0) len++;
		*lowerPos = num;
	}
	printf("%d\n", len);
	for (int j = 0; j < len; j++) {
		printf("%d ", lis[j]);
	}
	return 0;
}


