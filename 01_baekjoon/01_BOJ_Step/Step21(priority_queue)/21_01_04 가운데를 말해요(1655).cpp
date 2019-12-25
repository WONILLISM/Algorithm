#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int N;

void solution() {
	priority_queue<int, vector<int>, less<int>> MaxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;
	int x,tmp;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (MaxQ.size() == minQ.size()) {
			if (MaxQ.empty())MaxQ.push(x);
			else {
				if (MaxQ.top() >= x)MaxQ.push(x);
				else minQ.push(x);
			}
		}
		else if (MaxQ.size() > minQ.size()) {
			if (MaxQ.top() > x) {
				tmp = MaxQ.top(), MaxQ.pop();
				MaxQ.push(x);
				minQ.push(tmp);
			}
			else minQ.push(x);
		}
		else if (MaxQ.size() < minQ.size()) {
			if (minQ.top() < x) {
				tmp = minQ.top(), minQ.pop();
				minQ.push(x);
				MaxQ.push(tmp);
			}
			else MaxQ.push(x);
		}
		if (MaxQ.size() >= minQ.size()) cout << MaxQ.top() << "\n";
		else cout << minQ.top() << "\n";
	}
}
int main() {
	freopen("04.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	solution();
	return 0;
}