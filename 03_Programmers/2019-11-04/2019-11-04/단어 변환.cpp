#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
vector<string> W;
typedef struct info{
	string s;
	int step;
};
queue<info> q;
int Visit[50];
string S, E;
void isChange(string s,int step) {
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

int main() {
	string a, b;
	a = "hit";
	b = "cog";
	vector<string> c;
	c.push_back("hot");
	c.push_back("dot");
	c.push_back("dog");
	c.push_back("lot");
	c.push_back("log");
	c.push_back("cog");

	cout << solution(a, b, c) << "\n";
	
	return 0;
}