#include<cstdio>
char Arr[500], opStack[500];
int numStack[500];
int opTop, numTop, N, Result;
void Init() {
	opTop = numTop = N = Result = 0;
	scanf("%d", &N);
	scanf("%s", Arr);
}
int Cal(int a, int b, char op) {
	switch (op) {
	case '*': return a * b;
	case '+': return a + b;
	default: break;
	}
}
void Process() {
	for (int i = 0; i < N; i++) {
		char c = Arr[i];
		if (c >= '0'&&c <= '9')numStack[numTop++] = c - '0';
		else if (c == '(')opStack[opTop++] = c;
		else if (c == ')') {
			while (opStack[--opTop] != '(') {
				int cal = Cal(numStack[numTop - 2], numStack[numTop - 1], opStack[opTop]);
				numTop -= 2;
				numStack[numTop++] = cal;
			}
		}
		else {
			if ((c == '+' || c == '*') && (opStack[opTop - 1] == '*')){
				while (opStack[opTop-1] == '*') {
					int cal = Cal(numStack[numTop - 2], numStack[numTop - 1], opStack[opTop - 1]);
					numTop -= 2;
					opTop--;
					numStack[numTop++] = cal;
				}
			}
			opStack[opTop++] = c;
		}
	}
	while (opTop != 0) {
		int cal = Cal(numStack[numTop - 2], numStack[numTop - 1], opStack[opTop - 1]);
		numTop -= 2;
		opTop--;
		numStack[numTop++] = cal;
	}
}
int main() {
	//freopen("WEEK4(1222).in.txt", "r", stdin);
	freopen("WEEK4(1223).in.txt", "r", stdin);
	//freopen("WEEK4(1224).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		Process();
		printf("#%d %d\n", tc, numStack[numTop - 1]);
	}
	return 0;
}