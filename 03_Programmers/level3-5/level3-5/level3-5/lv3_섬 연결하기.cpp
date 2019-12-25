#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
//parents[i] ���� i�� �θ� ������ ����
int parents[101];

bool compare(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}
//�ֻ��� �θ� ã�� �Լ�
int find(int node) {
	//�θ��尡 �ڱ��ڽ��̸� ���� ��尡 �ֻ��� ���
	if (node == parents[node])return node;
	//�ƴ϶�� �ֻ��� �θ��带 ã��
	else {
		parents[node] = find(parents[node]);
		return parents[node];
	}
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	//ó������ ��� �ڱ��ڽ��� �θ���
	for (int i = 0; i < n; i++) parents[i] = i;
	//����ġ �������� ����
	sort(costs.begin(), costs.end(), compare);

	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];

		//start�� end�� ����Ǿ����� �ʴٸ�
		if (start != end) {
			//start�� �θ� end
			parents[start] = end;
			//������ ����ġ ����
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