#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> Tickets;
int Max;
bool visit[10000];
vector<string> ans, temp;
void DFS(string cur, vector<string>& tmp, int cnt) {
	tmp.push_back(cur);
	if (Max < cnt) {
		Max = cnt;
		ans = tmp;	
	}
	for (int i = 0; i < Tickets.size(); i++) {
		if (cur == Tickets[i][0] && !visit[i]) {
			visit[i] = true;
			DFS(Tickets[i][1], tmp, cnt + 1);
			visit[i] = false;
		}
	}
	tmp.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
	Tickets = tickets;
	int cnt = 0;
	sort(Tickets.begin(), Tickets.end());
	DFS("ICN", temp, cnt);
	return ans;
}
int main() {
	vector<vector<string>> tickets = { 
		{"ICN", "SFO"},
		{"ICN", "ATL"},
		{"SFO", "ATL"},
		{"ATL", "ICN"},
		{"ATL", "SFO"} };
	vector<string> ans = solution(tickets);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}