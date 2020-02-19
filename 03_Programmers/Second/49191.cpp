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
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));	
	for (auto r : results)			// 승리한 경우 
		graph[r[0]][r[1]] = true;
	
	// 자신한테 진사람이 승리한 경우 자신도 승리 처리
	// i는 거쳐가는 노드
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {		// 시작노드
			for (int k = 1; k <= n; k++) {	// 도착노드
				if (graph[j][i] && graph[i][k])
					graph[j][k] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] || graph[j][i]) cnt++;	// 판단 가능한경우
		}
		if (cnt == n - 1)answer++;	// 판단 가능한 판수가 n-1이면 확인가능함
	}
	return answer;
}
int main() {
	//cout << solution(5, { {1, 2}, {2, 3}, {3, 4}, {4,5} }) << endl;
	cout << solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} }) << endl;
	return 0;
}