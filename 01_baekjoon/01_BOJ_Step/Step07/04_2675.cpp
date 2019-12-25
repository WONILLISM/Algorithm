#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_2675();
int main() {
	solution_2675();
	return 0;
}
void solution_2675()
{
	char S[21];
	int t, r;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d ", &r);
		scanf("%s", S);
		int i = 0;
		while (S[i]) {
			for (int j = 0; j < r; j++)	printf("%c", S[i]);
			i++;
		}
		printf("\n");
	}
}