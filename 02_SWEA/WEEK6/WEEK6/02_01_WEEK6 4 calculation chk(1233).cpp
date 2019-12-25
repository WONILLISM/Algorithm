#include<cstdio>
const int MAX = 200;
char Data[MAX + 2];
double Cal_Stack[MAX + 2];
int N, Ans, Top;
void Init() {
	Ans = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int j;
		char c;
		scanf("%d %c", &j, &c);
		Data[j] = c;
		if (j + j <= N)scanf("%*d");
		if (j + j + 1 <= N)scanf("%*d");
	}
}
void Search(int cur) {
	if (cur * 2 <= N)Search(cur * 2);
	if (cur * 2 + 1 <= N)Search(cur * 2 + 1);
	if (cur > N / 2 && Data[cur] < '0') {
		Ans = 0;
		return;
	}
}
int main() {
	freopen("WEEK6(1233).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		Search(1);
		printf("#%d %d\n", tc, Ans);
	}
	return 0;
}

//
//#include<cstdio>
//const int MAX = 200;
//int N, Ans,Top;
//char Data[MAX + 2];
//double Cal_Stack[MAX];
//void Init() {
//	int j, k, a, b;
//	char c;
//	Data[0] = 'x';
//	N = Top = 0;
//	Ans = 1;
//	scanf("%d", &N);
//	for (j = 0; j < N; ++j) {
//		scanf("%d %c", &k, &c);
//		Data[k] = c;
//		if (k * 2 <= N)scanf("%d", &a);
//		if (k * 2 + 1 <= N)scanf("%d", &b);
//	}
//	Data[j] = '\0';
//}
//int CtoI(char *s) {
//	int a = s[0] - '0';
//	for (int i = 1; s[i]; ++i)a = a * 10 + (s[i] - '0');
//	return a;
//}
//void CheckCal(int cur) {
//	if (cur * 2 <= N)CheckCal(cur * 2);
//	if (cur * 2 + 1 <= N)CheckCal(cur * 2 + 1);
//	if (Data[cur] > '0')Cal_Stack[Top++] = Data[cur] - '0';
//	else {
//		if (Top < 2) {
//			Ans = 0;
//			return;
//		}
//		if (Data[cur] == '+')Cal_Stack[Top-2] += Cal_Stack[Top-1];
//		else if (Data[cur] == '-')Cal_Stack[Top-2] -= Cal_Stack[Top-1];
//		else if (Data[cur] == '*')Cal_Stack[Top-2] *= Cal_Stack[Top-1];
//		else if (Data[cur] == '/') {
//			Cal_Stack[Top - 2] /= (double)Cal_Stack[Top - 1];
//		}
//		Cal_Stack[Top - 1] = -1;
//		Top--;
//		if (Top < 0)Top = 0;
//		
//	}
//	if (Top != 1)Ans = 0;
//}
//int main() {
//	freopen("WEEK6(1233).in.txt", "r", stdin);
//	//freopen("Test.txt", "r", stdin);
//	for (int tc = 1; tc <= 10; tc++) {
//		Init();
//		CheckCal(1);
//		printf("#%d %d\n", tc, Ans);
//	}
//	return 0;
//}