#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Max;
int visit[10001];
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<vector<int>> matrix;
	sort(nodeinfo.begin(), nodeinfo.end());

	return answer;
}

int main() {
	vector<vector<int>> inf;
	inf.push_back({ 5,3 });
	inf.push_back({ 11,5 });
	inf.push_back({ 13,3 });
	inf.push_back({ 3,5 });
	inf.push_back({ 6,1 });
	solution(inf);
	return 0;
}