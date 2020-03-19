#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define PIS pair<int,string>

using namespace std;
int N;
vector<int> p;
// 1 2 3 3 4 
void solution() {
	sort(p.begin(), p.end());
	int answer = p[0];
	int tmp = answer;
	for (int i = 1; i < p.size(); i++) {
		tmp += p[i];
		answer += tmp;
	}

	cout << answer << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		p.push_back(a);
	}
	solution();
	return 0;
}