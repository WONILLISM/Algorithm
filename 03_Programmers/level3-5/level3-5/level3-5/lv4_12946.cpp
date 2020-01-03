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
		// ���������� n - 1���� 1������ 2������ �ű��
		// ������ �ٴڿ� �ִ� �� ���� 1������ ���� 3������ �ű��
		// 2������ �ű� n - 1 ���� 2������ ���� 3������ �ű��
		process(n - 1, from, ex, to);
		answer.push_back({ from,to });
		process(n - 1, ex, to, from);
	}
}
vector<vector<int>> solution(int n) {
	process(n, 1, 3, 2);//n�� ������ 1->3���� �ű��
	return answer;
}
int main() {
	for (auto a : solution(2)) {
		cout << a[0] << " " << a[1] << endl;
	}
	return 0;
}