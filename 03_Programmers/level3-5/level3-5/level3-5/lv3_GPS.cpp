#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N, M, K, ans;
vector<vector<int>> g;
int dp[101][201];
void Init(vector<vector<int>> edge_list) {
	for (int i = 0; i < K; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = M + 1;
	for (int i = 0; i < edge_list.size(); ++i) {
		int u = edge_list[i][0], v = edge_list[i][1];
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	N = n, M = m, K = k;
	ans = M + 1;
	g.assign(n + 1, vector<int>());
	Init(edge_list);

	dp[0][gps_log[0]] = 0;//�����
	for (int i = 1; i < K - 1; ++i) {		//�ð��뺰 �ý� ��ġ
		for (int j = 1; j <= N; ++j) {	//��� ���� �˻�
			int a = 0;
			if (gps_log[i] != j) a = 1;	//�����ؾ��� �κ��� ���
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);//���ڸ��� ���
			for (int l = 0; l < g[j].size(); ++l)
				dp[i][j] = min(dp[i][j], dp[i - 1][g[j][l]] + a);//������ �������� ���� ���
		}
	}
	int b = gps_log.back();
	for (int i = 0; i < g[b].size(); ++i)
		ans = min(ans, dp[gps_log.size() - 2][g[b][i]]);
	if (ans == M + 1)return -1;
	return ans;
}
int main() {
	vector<vector<int>> el =
	{
		{1, 2},{1, 3},{2, 3},
		{2, 4},{3, 4},{3, 5},
		{4, 6},{5, 6},{5, 7},{6, 7} 
	};
	vector<int> gl = { 1,2,3,3,6,7 };
	cout << solution(7, 10, el, 6, gl) << endl;
	return 0;
}