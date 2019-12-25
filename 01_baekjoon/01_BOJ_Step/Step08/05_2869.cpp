#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_2869();
int main() {
	solution_2869();
	return 0;
}
void solution_2869() {
int a, b, v;
	scanf("%d%d%d", &a, &b, &v);
	v -= a;
	printf("%d", v % (a - b) == 0 ? v / (a - b) + 1 : v / (a - b) + 2);
}