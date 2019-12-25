#include<iostream>
#define endl '\n'
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b;
	while (cin >> a >> b) {
		cout << a + b << endl;
	}
	return 0;
}

//#include<cstdio>
//
//int main() {
//	int a, b;
//	while (scanf("%d %d", &a, &b) != EOF) {
//		printf("%d\n", a + b);
//	}
//	return 0;
//}