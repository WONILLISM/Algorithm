#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_11720();

int main() {
	solution_11720();
	return 0;
}

void solution_11720()
{
	int n, sum = 0;
	char a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &a);
		sum += a - 48;
	}
	printf("%d", sum);
}


