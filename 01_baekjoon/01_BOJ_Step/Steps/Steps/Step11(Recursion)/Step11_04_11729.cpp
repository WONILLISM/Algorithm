#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int N;
void process(int n,int from, int to, int ex) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}

	process(n - 1, from, ex, to);
	printf("%d %d\n", from, to);
	process(n - 1, ex, to, from);

}
void solution_11729() {
	scanf("%d", &N);
	printf("%d\n", (2 << N-1) - 1);
	process(N, 1, 3, 2);
}
int main() {
	solution_11729();
	return 0;
}
