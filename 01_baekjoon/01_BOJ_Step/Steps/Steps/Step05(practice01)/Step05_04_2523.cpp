#include<cstdio>
int main() {
	int c, k = 1;
	scanf("%d", &c);
	for (int i = 1; i > 0; i += k) {
		for (int j = 0; j < i; j++) printf("*");
		printf("\n");
		if (i > c - 1) k *= -1;
	}
}
//#include<iostream>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n; cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= i; j++) {
//			cout << "*";
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			cout << "*";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}