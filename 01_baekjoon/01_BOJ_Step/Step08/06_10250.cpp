#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_10250();
int main() {
	solution_10250();
	return 0;
}
void solution_10250() {
	int t, h, w, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &h, &w, &n);
		int row = n % h == 0 ? h : n % h;
		int col = n % h == 0 ? n / h : (n / h) + 1;
		printf("%d%02d\n", row, col);
		//int x = 1;
		//while (n>h) {
		//	n -= h;
		//	x++;
		//}
		//printf("%d%02d\n", n, x);
	}
}