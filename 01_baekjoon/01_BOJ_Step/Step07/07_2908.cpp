#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_2908();
int main() {
	solution_2908();
	return 0;
}
void solution_2908()
{
	char Num[2][4];
	int a = 0, b = 0, c = 1;
	scanf("%s", Num[0]);
	scanf("%s", Num[1]);
	for (int i = 0; i < 3; i++) {
		a += c * (Num[0][i] - 48);
		b += c * (Num[1][i] - 48);
		c *= 10;
	}
	printf("%d", a > b ? a : b);
}