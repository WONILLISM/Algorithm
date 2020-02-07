#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

struct word { string s; int idx; };
int visit[50];
bool chkStr(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < b.size(); i++)
		if (a[i] != b[i])cnt++;
	return cnt == 1 ? true : false;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	for (int i = 0; i < words.size(); i++) {
		if (chkStr(begin, words[i])) {
			//dfs
			vector<word> w;
			string cur = words[i];
			int cur_idx = i;
			visit[i] = 1;
			w.push_back({ cur, cur_idx });
			while (!w.empty()) {
				cur = w.back().s, cur_idx = w.back().idx;
				w.pop_back();
				if (cur == target)return visit[cur_idx];
				for (int i = 0; i < words.size(); i++) {
					int next = i;
					if (!visit[next] && chkStr(cur, words[next])) {
						visit[next] = visit[cur_idx] + 1;
						w.push_back({ words[next],next });
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
	return 0;
}