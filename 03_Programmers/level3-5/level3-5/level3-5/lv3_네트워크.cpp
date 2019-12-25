#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	queue<int> Q;
	vector<int> visit(n, 0);
	for (int k = 0; k < n; k++) {
		int cur = k;
		if (!visit[cur]) {
			Q.push(cur);
			visit[cur] = 1;
			answer++;
			while (!Q.empty()) {
				cur = Q.front();
				Q.pop();
				for (int i = 0; i < n; i++) {
					int next = i;
					if (!visit[next] && computers[cur][next]) {
						Q.push(next);
						visit[next] = 1;
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	vector<vector<int>> c;
	c.push_back({ 1,1,0 });
	c.push_back({ 1,1,1 });
	c.push_back({ 0,1,1 });
	cout << solution(3, c);
	return 0;
}
//#include<iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int Q[200 * 200], f, r, cnt;
//int visit[200];
//void bfs(int n, vector<vector<int>> &map) {
//	for (int k = 0; k < n; k++) {
//		if (!visit[k]) {
//			++cnt;
//			int cur = k;
//			Q[r++] = cur;
//			visit[cur] = 1;
//			while (f != r) {
//				cur = Q[f++];
//				for (int i = cur; i < n; i++) {
//					if (map[i][cur] && !visit[i]) {
//						visit[i] = 1;
//						Q[r++] = i;
//					}
//				}
//			}
//		}
//	}
//}
//int solution(int n, vector<vector<int>> computers) {
//	int answer = 0;
//	bfs(n, computers);
//	return answer = cnt;
//}  
//int main() {
//	vector<vector<int>> c;
//	c.push_back({ 1,1,0 });
//	c.push_back({ 1,1,0 });
//	c.push_back({ 0,0,1 });
//	cout << solution(3, c);
//	return 0;
//}