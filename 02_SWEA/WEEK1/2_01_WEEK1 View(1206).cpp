#include<cstdio>
int data[1001];
int Testcase;
int View;
void Input() {
	for (int i = 0; i < Testcase; i++)
		scanf("%d", &data[i]);
}
void Init() {
	for (int i = 0; i < Testcase; i++)
		data[i] = 0;
	View = 0;
}
void Process() {
	for (int i = 2; i < Testcase - 2; i++) {
		if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
			if (data[i] > data[i - 2] && data[i] > data[i + 2]) {
				int a = data[i - 1] > data[i - 2] ? data[i - 1] : data[i - 2];
				int b = data[i + 1] > data[i + 2] ? data[i + 1] : data[i + 2];
				View += data[i] - (a > b ? a : b);
			}
		}
	}
}
int main() {
	freopen("D2(1206).in.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &Testcase);
		Init();
		Input();
		Process();
		printf("#%d %d\n", i, View);
	}
	return 0;
}