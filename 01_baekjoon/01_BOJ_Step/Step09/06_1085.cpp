#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;


void solution_1085() {
	int x,y,w,h;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	printf("%d\n", (w - x < x ? w - x : x) < (h - y < y ? h - y : y) ? (w - x < x ? w - x : x) : (h - y < y ? h - y : y));
	/*int a = w - x < x ? w - x: x;
	int b = h - y < y ? h - y: y;
	int c = a < b ? a : b;
	printf("%d\n", c);*/
}
int main() {
	solution_1085();
	return 0;
}
