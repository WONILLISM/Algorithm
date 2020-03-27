#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

int N;
bool Num[246913];
void solution_4948() {
	Num[0] = true;
	Num[1] = true;
	int i = 2, j = 2;
	for (int i = 2; i <= 123456; i++)
		for (int j = 2; j*i <= 246912; j++)
			if (i*j <= 246912 && !Num[i*j])Num[i*j] = true;

	while (1) {
		scanf("%d", &N);
		int Cnt = 0;
		if (!N) break;
		for (int i = N+1; i <= 2 * N; i++)
			if (!Num[i])Cnt++;
		printf("%d\n", Cnt);
	}
}
int main() {
	solution_4948();
	return 0;
}
