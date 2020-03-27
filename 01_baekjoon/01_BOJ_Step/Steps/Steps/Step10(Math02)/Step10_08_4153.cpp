#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

void solution_4153() {
	while (1) {
		int a[3], tmp;
		for (int i = 0; i < 3; i++)scanf("%d", &a[i]);
		if (a[0] == 0 || a[1] == 0 || a[2] == 0)break;
		if (a[2] * a[2] == a[1] * a[1] + a[0] * a[0])printf("right\n");
		else printf("wrong\n");
	}
}
int main() {
	solution_4153();
	return 0;
}
