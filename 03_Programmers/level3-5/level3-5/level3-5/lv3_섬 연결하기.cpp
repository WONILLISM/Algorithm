#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
//parents[i] 정점 i의 부모 정점을 보관
int parents[101];

bool compare(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}
//최상위 부모를 찾는 함수
int find(int node) {
	//부모노드가 자기자신이면 현재 노드가 최상위 노드
	if (node == parents[node])return node;
	//아니라면 최상위 부모노드를 찾음
	else {
		parents[node] = find(parents[node]);
		return parents[node];
	}
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	//처음에는 모두 자기자신이 부모노드
	for (int i = 0; i < n; i++) parents[i] = i;
	//가중치 오름차순 정렬
	sort(costs.begin(), costs.end(), compare);

	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];

		//start와 end가 연결되어있지 않다면
		if (start != end) {
			//start의 부모를 end
			parents[start] = end;
			//간선의 가중치 누적
			answer += cost;
		}
	}
	
	return answer;
}
int main() {
	vector<vector<int>> c;
	c.push_back({ 0,1,1 });
	c.push_back({ 0,2,2 });
	c.push_back({ 1,2,5 });
	c.push_back({ 1,3,1 });
	c.push_back({ 2,3,8 });
	cout << solution(4, c) << endl;
	return 0;
}