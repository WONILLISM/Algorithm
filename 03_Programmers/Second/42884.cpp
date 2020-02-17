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

int answer = 1;
vector<vector<int>> R;
void process(int start, int idx) {
	if (idx >= R.size() - 1)return;
	int nEnd = R[idx][1];
	int nnStart = R[idx + 1][0];

	if (start > nEnd) start = nEnd;
	if (start < nnStart) {
		answer++;
		start = R[idx + 1][1];
	}
	process(start, idx + 1);
}
int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end());
	R = routes;
	process(routes[0][1], 1);
	return answer;
}

int main() {
	vector<vector<int>> r = {{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}};
	cout << solution(r) << endl;
	return 0;
}