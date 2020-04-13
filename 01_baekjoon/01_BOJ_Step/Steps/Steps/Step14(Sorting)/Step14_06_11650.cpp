#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 1000000;
int n;

int solution() {
	int answer = 0;
	string num = to_string(n);
	for (int i = 1; i <= MAX; i++) {
		string tmp = to_string(i);
		answer = i;
		int order = tmp.size() - 1;
		for (int j = 0; j < tmp.size(); j++) {
			int a = tmp[j] - '0';
			answer += a;
		}
		if (answer == n)return i;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << solution();
	return 0;
}
//int process(int m) {
//	int sum = m;
//	while (m != 0) {
//		int r = m % 10;
//		sum += r;
//		m /= 10;
//	}
//	return sum;
//}
//void solution_2231() {
//	scanf("%d", &n);
//	for (int i = 1; i<=MAX; i++) {
//		if (process(i) == n) {
//			printf("%d\n", i);
//			return;
//		}
//	}
//	printf("0\n");
//}
//int main() {
//	solution_2231();
//	return 0;
//}
