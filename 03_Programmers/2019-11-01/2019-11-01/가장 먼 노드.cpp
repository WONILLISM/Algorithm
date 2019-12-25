#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;
int Visit[20001], ans, Max;
int Mat[20001][20001];
queue<int> q;
//void process(int n, vector<vector<int>> matrix) {
void process(int n){
	int cur = 1;
	Visit[cur] = 1;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (Mat[cur][i] && !Visit[i]) {
				Visit[i] = Visit[cur] + 1;
				q.push(i);
				if (Max < Visit[i])Max = Visit[i];
			}
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	/*vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < edge.size(); i++) 
		matrix[edge[i][0]][edge[i][1]] = matrix[edge[i][1]][edge[i][0]]= 1;*/
	for (int i = 0; i < edge.size(); i++)
		Mat[edge[i][0]][edge[i][1]] = Mat[edge[i][1]][edge[i][0]] = 1;
	//process(n, matrix);
	process(n);
	for (int i = 1; i <= n; i++)
		if (Max == Visit[i])ans++;
	answer = ans;
	return answer;
}

int main() {
	int n;
	vector<vector<int>> edge;
	cin >> n;
	edge.push_back({ 3,6 });
	edge.push_back({ 4,3 });
	edge.push_back({ 3,2 });
	edge.push_back({ 1,3 });
	edge.push_back({ 1,2 });
	edge.push_back({ 2,4 });
	edge.push_back({ 5,2 });
	cout << solution(n, edge) << "\n";
	return 0;
}