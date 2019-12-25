#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_1011();
int main() {
	solution_1011();
	return 0;
}
void solution_1011() {
	int t, a, b, answer;
	scanf("%d", &t);
	while (t--) {
		unsigned int gap, pos = 1;
		answer = 1;
		scanf("%d %d", &a, &b);
		gap = b - a;
		for (int i = 2; pos < gap; i++) {
			pos += i / 2;
			answer++;
		}
		if (pos > gap) answer--;
		printf("%d\n", answer);
	}
}