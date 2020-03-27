#include <iostream>
#include <vector>
#include <queue>

#define PII pair<int,int>

using namespace std;

int N;
vector<PII> p;
vector<int> Rank;

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p[i].first < p[j].first && p[i].second < p[j].second) {
				Rank[i]++;
			}
		}
	}
	for (auto a : Rank)
		cout << a << endl;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back({ x,y });
		Rank.push_back(1);
	}
	solution();
	return 0;
}