#include<iostream>
#include<cmath>
using namespace std;
int ans;
/*
    n - 1  / plus + 1
	plus >=2 n % 3 == 0 ÀÏ ¶§ plus -2 n/3
*/
void process(int n, int plus) {
	if (pow(3, plus / 2) > n)return;
	if (n == 3) {
		if (plus == 2) ans++;
	}
	else if (n > 3) {
		if (plus >= 2 && n % 3 == 0)process(n / 3, plus - 2);
		process(n - 1, plus + 1);
	}
}
int solution(int n) {
	process(n, 0);
	return ans;
}
int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}