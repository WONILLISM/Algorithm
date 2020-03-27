#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int process(int n) {
	if (n == 1 || n == 0)return 1;
	return n * process(n - 1);
}
void solution_10872() {
	int n;
	scanf("%d", &n);
	printf("%d\n", process(n));
}
int main() {
	solution_10872();
	return 0;
}