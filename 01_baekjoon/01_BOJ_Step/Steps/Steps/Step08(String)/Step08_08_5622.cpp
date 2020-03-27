#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_5622();

int main() {
	solution_5622();
	return 0;
}
void solution_5622()
{
	char S[16];
	int Time = 0;
	scanf("%s", S);
	int i = 0;
	while (S[i]) {
		int t;
		if (S[i] >= 'P'&&S[i] <= 'S') t = 8;
		else if (S[i] >= 'T'&&S[i] <= 'V')t = 9;
		else if (S[i] >= 'W'&&S[i] <= 'Z')t = 10;
		else t = (S[i] - 65) / 3 + 3;
		Time += t;
		i++;
	}
	printf("%d", Time);
}