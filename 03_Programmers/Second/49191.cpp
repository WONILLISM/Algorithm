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
	for (auto r : results)			// �¸��� ��� 
		graph[r[0]][r[1]] = true;
	
	// �ڽ����� ������� �¸��� ��� �ڽŵ� �¸� ó��
	// i�� ���İ��� ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {		// ���۳��
			for (int k = 1; k <= n; k++) {	// �������
				if (graph[j][i] && graph[i][k])
					graph[j][k] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] || graph[j][i]) cnt++;	// �Ǵ� �����Ѱ��
		}
		if (cnt == n - 1)answer++;	// �Ǵ� ������ �Ǽ��� n-1�̸� Ȯ�ΰ�����
	}
	return answer;
}
int main() {
	//cout << solution(5, { {1, 2}, {2, 3}, {3, 4}, {4,5} }) << endl;
	cout << solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} }) << endl;
	return 0;
}