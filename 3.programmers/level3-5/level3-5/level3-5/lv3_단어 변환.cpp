#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;

bool chkString(string a, string b) {
	int cnt = 0;
	for (int j = 0; j < b.size(); j++) {
		if (a[j] != b[j])cnt++;
	}
	return cnt == 1 ? true : false;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int n = words.size();
	for (int i = 0; i < n; i++) {
		if (chkString(begin, words[i])) {
			vector<int> visit(n, 0);
			vector<pair<string, int>> v;
			string cur = words[i];
			int curIdx = i;
			visit[i] = 1;
			v.push_back({ cur,curIdx });
			while (!v.empty()) {
				cur = v.back().first, curIdx = v.back().second;
				v.pop_back();
				if (cur == target)return visit[curIdx];
				for (int next = 0; next < words.size(); next++) {
					if (!visit[next] && chkString(cur, words[next])) {
						visit[next] = visit[curIdx] + 1;
						v.push_back({ words[next], next});
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	string a, b;
	a = "hit";
	b = "cog";
	vector<string> c = { "hot", "dot", "dog", "lot", "log" };
	/*vector<string> c;
	c.push_back("hot");
	c.push_back("dot");
	c.push_back("dog");
	c.push_back("lot");
	c.push_back("log");
	c.push_back("cog");*/
	cout << solution(a, b, c) << "\n";
	
	return 0;
}


vector<string> W;
typedef struct info {
	string s;
	int step;
};
queue<info> q;
int Visit[50];
string S, E;
void isChange(string s, int step) {
	for (int i = 0; i < W.size(); i++) {
		int cnt = 0;
		if (!Visit[i]) {
			for (int j = 0; j < W[i].size(); j++) {
				if (W[i][j] != s[j])cnt++;
			}
			if (cnt == 1) {
				Visit[i] = true;
				q.push({ W[i], step + 1 });
			}
		}
	}
}
int process() {
	info cur = { S,0 };
	isChange(cur.s, cur.step);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.s == E)return cur.step;
		if (cur.step >= W.size())return 0;
		isChange(cur.s, cur.step);
	}
	return 0;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	W = words;
	S = begin;
	E = target;
	answer = process();
	return answer;
}
