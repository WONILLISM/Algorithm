#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector<int> num;
	vector<ll> fac;
	fac.push_back(1);
	//남아있는 수
	for (int i = 1; i <= n; i++)
		num.push_back(i);
	//1~n-1! 까지 저장
	for (int i = 1; i <= n - 1; i++)
		fac.push_back(i*fac[i - 1]);
	for (int i = 0; i < n; i++) {
		int a = k / fac[n - i - 1];
		ll b = k % fac[n - i - 1];
		a = b == 0 ? a : a + 1;
		answer.push_back(num[a - 1]);
		num.erase(num.begin() + a - 1);
		k = b == 0 ? fac[n - i - 1] : b;
	}	
	return answer;
}
int main() {
	for (auto a : solution(5, 25)) {
		cout << a;
	}
	return 0;
}
