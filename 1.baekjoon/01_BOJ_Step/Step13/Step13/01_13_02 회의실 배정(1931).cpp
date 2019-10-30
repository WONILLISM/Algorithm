#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, limit, ans;
typedef struct info { int s, e; };
bool compare(info a, info b) { 
	if (a.e == b.e)return a.s < b.s;
	else return a.e < b.e;
}
vector<info> inf;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		inf.push_back({ a,b });
	}
	sort(inf.begin(), inf.end(), compare);
}
void Process() {
	for (int i = 0; i < N; i++) {
		if (inf[i].s >= limit) {
			ans++;
			limit = inf[i].e;
		}
	}
	cout << ans << endl;
}
void Solution() {
	Input();
	Process();
}
int main() {
	Solution();
	return 0;
}