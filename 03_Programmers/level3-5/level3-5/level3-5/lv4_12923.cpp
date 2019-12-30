#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

ll checkPrimenum(ll x) {
	ll i;
	for (i = 2; i*i < x; i++) {
		if (x%i == 0)break;
	}
	if (i*i > x)return 1;	//소수이면 1 반환
	return x / i;			//소수가 아니면 최대 약수 반환
}
vector<int> solution(long long begin, long long end) {
	vector<int> answer;
	for (int i = begin; i <= end; i++) {
		if (i == 1)answer.push_back(0);
		else {
			int j;
			for (j = 2; j*j < i; j++) {
				if (i%j == 0)break;
			}
			if (j*j > i)answer.push_back(1);
			else answer.push_back(i / j);
		}
	}
	//if (begin == 1) {
	//	answer.push_back(0);
	//	begin++;
	//}
	//for (ll i = begin; i <= end; i++)
	//	answer.push_back(checkPrimenum(i));
	return answer;
}
int main() {
	for (auto a : solution(1, 10)) {
		cout << a;
	}
	return 0;
}
