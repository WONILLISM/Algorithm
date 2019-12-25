#include<iostream>

using namespace std;
const int MAX_A = 100;
int N;
long Max = -2000000000, Min = 2000000000;
long A[MAX_A];
int cal[4];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> cal[i];
}
//µ¡¼À »¬¼À °ö¼À ³ª´°¼À
//int Div(int a, int b) {
//	if (a > 0 && b > 0) return a / b;
//	else if (a < 0 && b>0)return -((-a) / b);
//	else if (a > 0 && b<0)return -(a / (-b));
//	else if (a < 0 && b < 0)return (-a) / (-b);
//}
void Process(int n, int total, int idx, int i) {
	if (n <= 1) {
		if (Max < total)Max = total;
		if (Min > total)Min = total;
		return;
	}
	if (cal[idx] == 0)return;
	int tot;
	if (idx == 0) tot = total + A[i];
	else if (idx == 1) tot = total - A[i];
	else if (idx == 2) tot = total * A[i];
	//else if (idx == 3) tot = Div(total, A[i]);
	else if (idx == 3) tot = total / A[i];
	for (int k = 0; k < 4; k++) {
		cal[idx] -= 1;
		Process(n - 1, tot, k, i + 1);
		cal[idx] += 1;
	}
}
void Solution() {
	Input();
	for (int i = 0; i < 4; i++)
		Process(N, A[0], i, 1);
	cout << Max << "\n" << Min << "\n";
	//cout << (1 << 30);
}
int main() {
	freopen("10.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}