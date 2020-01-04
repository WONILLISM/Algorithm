#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;


void solution_3009() {
	int x[4], y[4];
	for (int i = 0; i < 3; ++i)
		scanf("%d %d", &x[i], &y[i]);
	sort(x, x + 3);
	sort(y, y + 3);
	printf("%d %d", x[0] == x[1] ? x[2] : x[0], y[0] == y[1] ? y[2] : y[0]);
}
int main() {
	solution_3009();
	return 0;
}
