#include<cstdio>
#include<algorithm>
using namespace std;
int Num[500000];
int Tmp[500000];
int Cnt[8001];
int Max;
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &Num[i]);
		sum += Num[i];
		Cnt[Num[i] + 4000]++;
		if (Max < Cnt[Num[i] + 4000])Max = Cnt[Num[i] + 4000];
	}
	sort(Num, Num + n);
	int j = 0, frq;
	for (int i = 0; i < 8001; i++) {
		if (Cnt[i] == Max) {
			frq = i - 4000;
			j++;
			if (j == 2) {
				frq = i - 4000;
				break;
			}
		}
	}
	printf("%.0f\n", sum / (double)n);
	printf("%d\n", Num[n / 2]);
	printf("%d\n", frq);
	printf("%d\n", Num[n - 1] - Num[0]);
	return 0;
}