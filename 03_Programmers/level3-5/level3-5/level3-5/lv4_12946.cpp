#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

vector<vector<int>> answer;
void process(int n, int from, int to, int ex) {
	if (n == 1)answer.push_back({ from,to });
	else {
		// 위에서부터 n - 1개를 1번에서 2번으로 옮긴다
		// 나머지 바닥에 있는 한 개를 1번에서 최종 3번으로 옮긴다
		// 2번으로 옮긴 n - 1 개를 2번에서 최종 3번으로 옮긴다
		process(n - 1, from, ex, to);
		answer.push_back({ from,to });
		process(n - 1, ex, to, from);
	}
}
vector<vector<int>> solution(int n) {
	process(n, 1, 3, 2);//n번 원판을 1->3으로 옮긴다
	return answer;
}
int main() {
	for (auto a : solution(2)) {
		cout << a[0] << " " << a[1] << endl;
	}
	return 0;
}