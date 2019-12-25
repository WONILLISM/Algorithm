#include<iostream>
#define endl "\n";
using namespace std;

const int MAX = 1000;
typedef long long ll;
typedef struct Pos{
	int x;
	int y;
}Pos;
Pos P[MAX];
typedef struct Edge {
	int i, j;
	ll edge;
}Edge;
Edge Q[MAX*MAX / 2];
int f, r;
ll N, Ans;
double E;
ll calDist(int i, int j) {
	return (P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y)*(P[i].y - P[j].y);
}
void Init() {
	N = Ans = 0;
	E = 0.0;
	f = r = 0;
	for (int i = 0; i < MAX; i++) {
		P[i].x = -1;
		P[i].y = -1;
	}
}
void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> P[i].x;
	for (int i = 1; i <= N; i++)cin >> P[i].y;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ll Dist = calDist(i, j);
			Q[r++] = { i,j,Dist };
		}
	}
	cin >> E;
}
//E*L*L
int main() {
	scanf("%*d");
	for (int tc = 1; tc <= 10; tc++) {

		printf("#%d %lld\n", tc, Ans);
	}
	return 0;
}