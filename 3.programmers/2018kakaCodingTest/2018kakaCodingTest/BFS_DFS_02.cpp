#include<iostream>
#include<vector>
using namespace std;
//int Q[200 * 200], f, r, cnt;
int visit[200];

void dfs(int n, vector<vector<int>> &map, int v) {
	visit[v] = 1;
	for (int i = 0; i < n; i++) {
		if (!visit[i] && map[v][i]) {
			visit[i] = 1;
			dfs(n, map, i);
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			answer++;
			dfs(n, computers, i);
		}
	}
	return answer;
}
//void bfs(int n, vector<vector<int>> &map) {
//	vector<int> visit(n, 0);
//	for (int k = 0; k < n; k++) {
//		if (!visit[k]) {
//			int cur = k;
//			Q[r++] = cur;
//			visit[cur] = 1;
//			while (f != r) {
//				cur = Q[f++];
//				for (int i = cur + 1; i < n; i++) {
//					if (map[i][cur] && !visit[i]) {
//						visit[i] = 1;
//						Q[r++] = i;
//					}
//				}
//			}
//			cnt++;
//		}
//	}
//}
//int solution(int n, vector<vector<int>> computers) {
//	int answer = 0;
//	bfs(n, computers);
//	return answer = cnt;
//}

int main() {
	vector<vector<int>> c;
	c.push_back({ 1,1,0 });
	c.push_back({ 1,1,0 });
	c.push_back({ 0,0,1 });
	cout << solution(3, c) << endl;
	return 0;
}