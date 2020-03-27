#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_1316();

int main() {
	solution_1316();
	return 0;
}


void solution_1316()
{
	int N, Cnt = 0;
	char S[101];
	bool Check[26];
	memset(Check, 26, 0);

	scanf("%d", &N);
	while (N--) {
		int i = 0;
		for (int j = 0; j < 26; j++) Check[j] = false;
		scanf("%s", S);
		while (S[i]) {
			int n = S[i] - 97;
			if (Check[n] && S[i] != S[i - 1])break;
			if (!Check[n]) Check[n] = true;
			i++;
		}
		if (S[i] == '\0')Cnt++;
	}
	printf("%d\n", Cnt);
}

