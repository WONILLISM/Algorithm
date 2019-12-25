#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_1712();
int main() {
	solution_1712();
	return 0;
}
void solution_1712() {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	c -= b;
	if (c <= 0)printf("-1\n");
	else printf("%lld\n", (a / c) + 1);
}