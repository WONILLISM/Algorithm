#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
void solution() {
	while (q.size() > 1) {
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		q.push(b);
	}
	int ans = q.front();
	q.pop();
	cout << ans << endl;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
	solution();
	return 0;
}