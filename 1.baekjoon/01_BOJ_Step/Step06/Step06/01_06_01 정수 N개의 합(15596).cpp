//#include<cstdio>
//long long sum(int *a, int n) {
//	long long ans = 0;
//	for (int i = 0; i < n; i++)
//		ans += a[i];
//	return ans;
//}
//int main() {
//	int n = 10;
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%ld", sum(a, n));
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
long long sum(vector<int> &a) {
	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
	}
	return ans;
}
int main() {
	int n = 10;
	vector<int> a = { 1,2,3,4,5,6,7,8,9 };
	long long ans = sum(a);
	cout << ans;
	return 0;
}
