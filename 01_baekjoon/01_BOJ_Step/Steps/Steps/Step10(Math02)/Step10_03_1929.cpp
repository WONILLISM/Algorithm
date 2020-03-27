#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

int M, N;
bool Num[1000001];
void solution_1929() {
	Num[0] = true;
	Num[1] = true;
	scanf("%d %d", &M, &N);
	int i = 2, j = 2;
	while (i*j <= 1000000) {
		for (int j = 2; j*i <= 1000000; j++)
			if (!Num[i*j])Num[i*j] = true;
		i++;
	}
	for (int i = M; i <= N; i++)
		if (!Num[i])printf("%d\n", i);
}
int main() {
	solution_1929();
	return 0;
}