#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 100000;
vector<int> T;	//�� �ɻ���� �� ���� �ɻ��ϴµ� �ɸ��� ��
int N;	//�Ա��ɻ縦 ��ٸ��� ����� ��

bool func(ll time) {
	ll tmp = 0;
	for (int i = 0; i < T.size(); ++i)
		tmp += time / T[i];
	return tmp < N;
}
ll solution(int n, vector<int> times) {
	T = times, N = n;
	ll Low = 1, High = 10000000000000LL;
	while (Low <= High)			//�̺�Ž��
	{	
		ll mid = (Low + High) / 2;		//��� ��
		if (!func(mid)) High = mid - 1;			
		else Low = mid + 1;
	}
	return Low;
}
int main() {
	cout << solution(6, { 7,10 });
	return 0;
}