#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;
int N,Cnt;

void solution_1978();
int main() {
	solution_1978();
	return 0;
}
void solution_1978() {
    scanf("%d", &N);
	while (N--) {
		int a;
		bool chk = false;
		scanf("%d", &a);
		for (int i = 2; i < a; i++) {
			chk = a % i == 0 ? true : false;
			if (chk)break;
		}
		if (a != 1 && !chk)Cnt++;
	}
	printf("%d", Cnt);
}