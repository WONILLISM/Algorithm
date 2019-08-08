#include<cstdio>
int N, Top, Avl;
char Str[500], Stack[300];
void Process() {
	for (int i = 0; i < N; i++) {
		// (,) : 40,41 [,] : 91,93, {,} : 123,125, <,> : 60,62
		if (Str[i] == '(' || Str[i] == '[' || Str[i] == '{' || Str[i] == '<')Stack[Top++] = Str[i];
		else {
			if (Stack[--Top] / 10 != Str[i] / 10) {//
				Avl = 0;
				break;
			}
		}
	}
	if (Top != 0)Avl = 0;
}
int main() {
	freopen("WEEK3(1218).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &N);
		scanf("%s", Str);
		Top = 0;
		Avl = 1;
		Process();
		printf("#%d %d\n", tc, Avl);
	}
	//printf("%d %d %d %d\n%d %d %d %d\n", '(', '[', '{', '<', ')', ']', '}', '>');
	return 0;
}

/*else if (Str[i] == ')') {
			if (Stack[Top - 1] == '(')pop();
			else {
				Avl = 0;
				break;
			}
		}
		else if (Str[i] == ']') {
			if (Stack[Top - 1] == '[')pop();
			else {
				Avl = 0;
				break;
			}
		}
		else if (Str[i] == '}') {
			if (Stack[Top - 1] == '{')pop();
			else {
				Avl = 0;
				break;
			}
		}
		else if (Str[i] == '>') {
			if (Stack[Top - 1] == '<')pop();
			else {
				Avl = 0;
				break;
			}
		}*/