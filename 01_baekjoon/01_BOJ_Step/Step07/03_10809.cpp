#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_10809();
int main() {
	solution_10809();
	return 0;
}

void solution_10809()
{
	//char S[101];
	//int Alphabet[26];
	//bool Check[26];
	//memset(Alphabet, 0, sizeof(Alphabet));
	//memset(Check, false, sizeof(Check));
	//scanf("%s", S);
	//int i = 0;
	//while (S[i]) {
	//	int n = S[i] - 97;
	//	if (!Check[n]) {
	//		Alphabet[n] = i;
	//		Check[n] = true;
	//	}
	//	i++;
	//}
	//for (int i = 0; i < 26; i++) {
	//	if (!Check[i]) Alphabet[i] = -1;
	//	printf("%d ", Alphabet[i]);
	//}
	char S[101];
	int Check[26];
	fill(Check[0], Check[26], 0);
	memset(Check, 0, sizeof(Check));
	scanf("%s", S);
	for (int i = 0; S[i] != '\0'; i++) {
		int n = S[i] - 'a';
		if (!Check[n]) Check[n] = i + 1;
	}
	for (int i = 0; i < 26; i++) {
		if (!Check[i]) printf("-1 ");
		else printf("%d ", Check[i] - 1);
	}
}