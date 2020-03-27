#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_2941();
int main() {
	solution_2941();
	return 0;
}


int Search_2941(char *a, char *b) {
	int cnt = 0, i = 0;
	while (1) {
		if (!b[i]) return cnt;
		if (a[i] != b[i]) return 0;
		if (b[i] && a[i] == b[i]) {
			i++;
			cnt++;
		}
	}
}
void solution_2941()
{
	char S[101];
	char CroatiaAp[8][4] = {
		{'c','='}, {'c','-'}, {'d','z','='}, {'d','-'},
		{'l','j'}, {'n','j'}, {'s','='}, {'z','='}
	};
	scanf("%s", S);
	int i = 0, answer = 0;
	while (S[i]) {
		int n = 0;
		for (int k = 0; k < 8; k++) {
			n = Search_2941(&S[i], CroatiaAp[k]);
			if (n > 0) {
				answer++;
				i += n;
				break;
			}
		}
		if (n == 0) {
			answer++;
			i++;
		}
	}
	printf("%d\n", answer);
}