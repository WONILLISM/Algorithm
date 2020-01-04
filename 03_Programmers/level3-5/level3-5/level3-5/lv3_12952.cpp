#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

bool Col[13];
bool Inc[25];
bool Dec[25];
int N, ans;
void process(int a) {
	if (a > N) {
		ans++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!Col[i] && !Inc[a + i] && !Dec[N + (a - i) + 1]) {
			Col[i] = Inc[a + i] = Dec[N + (a - i) + 1] = true;
			process(a + 1);
			Col[i] = Inc[a + i] = Dec[N + (a - i) + 1] = false;
		}
	}
}
int solution(int n) {
	N = n;
	process(1);
	return ans;
}
int main() {
	cout << solution(4) << endl;
	return 0;
}

