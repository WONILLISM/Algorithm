/* 야근 지수 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

typedef struct factor {
	int x;
	bool operator<(const factor &n)const {
		return x < n.x;
	}
};
ll solution(int n, vector<int> works) {
	ll ans = 0;
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++)
		pq.push(works[i]);
	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		if (n >0) {
			if (cur - 1 >= 0)pq.push(cur - 1);
			n -= 1;
		}
		else {
			ans += cur * cur;
		}
	}
	return ans;
}
int main() {
	vector<int> v = { 4,3,3 };
	cout << solution(4, v) << endl;
	return 0;
}
