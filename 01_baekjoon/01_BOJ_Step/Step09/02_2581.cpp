#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;
int M, N, Sum, Min;
bool Num[10001];
void solution_2581();
int main() {
	solution_2581();
	return 0;
}
void solution_2581() {
	scanf("%d %d", &M, &N);

	/* 에라토스테네스의 채 */
	Num[0] = true;
	Num[1] = true;
	for (int i = 2; i <= 10000; i++)
		for (int j = 2; j <= 100; j++)
			if (i*j <= 10000 && !Num[i*j])Num[i*j] = true;
	
	for (int i = M; i <= N; i++) {
		if (Min == 0 && !Num[i])Min = i;
		if (!Num[i])Sum += i;
	}
	if (Min == 0)printf("-1\n");
	else printf("%d\n%d\n", Sum, Min);
}