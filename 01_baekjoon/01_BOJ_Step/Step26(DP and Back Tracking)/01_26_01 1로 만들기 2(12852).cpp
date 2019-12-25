#include<cstdio>
#include<queue>
using namespace std;
int n, visit[1000001];
queue<int> q, qn, qp;	//���� ť ���� ť �θ� ť
void process(int a) {
	if (a == n) return;
	process(visit[a]);
	printf("%d ", a);
}
void solution() {
	q.push(n); qn.push(0); qp.push(n);
	while (!q.empty()) {
		int cur = q.front(), next = qn.front(), par = qp.front();//���� ���� �θ�
		q.pop(), qn.pop(), qp.pop();
		if (!visit[cur]) {
			visit[cur] = par;
			if (cur == 1) { printf("%d\n", next); break; }
			if (cur % 3 == 0) q.push(cur / 3), qn.push(next + 1), qp.push(cur);
			if (cur % 2 == 0) q.push(cur / 2), qn.push(next + 1), qp.push(cur);
			q.push(cur - 1), qn.push(next + 1), qp.push(cur);
		}
	}
	printf("%d ", n);
	process(1);
}
int main() {
	scanf("%d", &n);
	solution();
	return 0;
}
