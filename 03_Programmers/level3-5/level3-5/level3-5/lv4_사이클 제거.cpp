#include<iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> Graph;
int visit[5001];
bool Check;
void InitVisit() {
	for (int i = 0; i < 5001; i++)visit[i] = 0;
}
vector<vector<int>> makeGraph(int n, vector<vector<int>> edges) {
	int m = edges.size();
	vector<vector<int>> g(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int u = edges[i][0], v = edges[i][1];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return g;
}
void dfs(int cur, int prev) {
	for (int i = 1; i < Graph[cur].size(); i++) {
		int next = Graph[cur][i];
		if (prev != next) {
			if (next != 0) {
				if (!visit[next]) {
					visit[next] = visit[cur] + 1;
					dfs(next, cur);
					visit[next] = visit[cur];
				}
				else if (visit[cur] > visit[next]) {
					Check = true;
					return;
				}
			}
		}
	}
}

int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	Graph = makeGraph(n, edges);
	vector<int> tmp;
	for (int i = 1; i < Graph.size(); i++) {
		tmp.push_back(0);
		for (int j = 1; j < Graph[i].size(); j++) {
			tmp.push_back(Graph[i][j]);
			Graph[i][j] = 0;
		}
		Check = false;
		for (int j = 1; j < Graph.size(); j++) {
			if (i != j) {
				InitVisit();
				dfs(j, j);
			}
		}
		for (int j = 1; j < Graph[i].size(); j++) {
			Graph[i][j] = tmp[j];
		}
		tmp.clear();
		if (Check)answer += i;
	}
	return answer;
}
int main() {
	vector<vector<int>> e = { {1,2},{1,3},{2,3},{2,4},{3,4} };
	//vector<vector<int>> e = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 1}, {2, 7}, {3, 6}};
	cout << solution(4, e);
	return 0;
}






//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//const int MAX = 5001;
//int matrix[MAX][MAX];
//int visit[MAX];
//int tmp[MAX];
//int N, Ans;
//bool flag;
//vector<int> nodes;
//vector<int> Stack;
//void visitInit() {
//	for (int i = 0; i <= MAX; i++)
//		visit[i] = 0;
//}
//void mkMatrix(vector<vector<int>> edges) {
//	nodes.push_back(edges[0][0]);
//	nodes.push_back(edges[0][1]);
//	matrix[edges[0][0]][edges[0][1]] = 1;
//	matrix[edges[0][1]][edges[0][0]] = 1;
//	for (int i = 1; i < edges.size(); i++) {
//		matrix[edges[i][0]][edges[i][1]] = 1;
//		matrix[edges[i][1]][edges[i][0]] = 1;
//		int ns = nodes.size();
//		for (int k = 0; k < edges[i].size(); k++) {
//			bool chk = false;
//			for (int j = 0; j < ns; j++) {
//				if (nodes[j] == edges[i][k]) {
//					chk = true;
//				}
//			}
//			if(!chk)nodes.push_back(edges[i][k]);
//		}
//	}
//}
//void dfs(int cur) {
//	visit[cur] = 1; 
//	for (int i = 1; i <= nodes.back(); i++) {
//		if (matrix[cur][i] == 1) {
//			if (!visit[i]) {
//				dfs(i);
//			
//			}
//			else if (visit[i] < visit[cur]) {
//				flag = true;
//				return;
//			}
//		}
//	}
//}
//void process() {
//	for (int i = 0; i < nodes.size(); i++) {
//		int a = nodes[i];
//		int tmp[MAX];
//		for (int j = 1; j <= nodes.back(); j++) {
//			tmp[j] = matrix[a][j];
//			matrix[a][j] = 0;
//			matrix[j][a] = 0;
//		}
//		flag = false;
//		for (int k = 0; k < nodes.size(); k++) {
//			if (i != k) {
//				visitInit();
//				dfs(nodes[k]);
//			}
//		}
//		if (!flag)Ans += a;
//		for (int j = 1; j <= nodes.back(); j++) {
//			matrix[a][j] = tmp[j];
//			matrix[j][a] = tmp[j];
//		}
//	}
//}
//int solution(int n, vector<vector<int>> edges) {
//	N = n;
//	mkMatrix(edges);
//	sort(nodes.begin(), nodes.end());
//	process();
//	return Ans;
//}
//int main() {
//	vector<vector<int>> e = { {1,2},{1,3},{2,3},{2,4},{3,4} };
//	//vector<vector<int>> e = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 1}, {2, 7}, {3, 6}};
//	cout << solution(4, e);
//	return 0;
//}