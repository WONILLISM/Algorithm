#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_2292();
int main() {
	solution_2292();
	return 0;
}
void solution_2292() {
	int n, i = 1, answer = 1;
	scanf("%d", &n);
	n--;
	while (n > 0) {
		n -= 6 * i;
		i++;
		answer++;
	}
	printf("%d", answer);
}