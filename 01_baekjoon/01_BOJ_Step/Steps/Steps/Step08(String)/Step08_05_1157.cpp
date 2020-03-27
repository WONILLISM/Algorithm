#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_1157();

int main() {
	solution_1157();
	return 0;
}

void solution_1157()
{
	int Alphabet[26];
	char S[1000001];
	int Max = 0, Cnt = 0;
	memset(Alphabet, 0, sizeof(Alphabet));
	scanf("%s", S);
	int a, i = 0;
	while (S[i]) {
		int n = S[i] >= 97 ? S[i] - 97 : S[i] - 65;
		Alphabet[n]++;
		i++;
	}
	for (int j = 0; j < 26; j++)
		if (Max < Alphabet[j])Max = Alphabet[j];
	for (int j = 0; j < 26; j++) {
		if (Alphabet != 0 && Max == Alphabet[j]) {
			Cnt++;
			if (Cnt > 1) {
				printf("?\n");
				return;
			}
			else if (Cnt == 1) a = j;
		}
	}
	printf("%c", a + 65);
}