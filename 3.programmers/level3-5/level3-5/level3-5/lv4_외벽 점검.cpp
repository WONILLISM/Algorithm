#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

const int INF = 1 << 30;
int Nsize, Wsize, Dsize;
vector<int> Dist;
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = INF;
	Nsize = n, Wsize = weak.size(), Dsize = dist.size();
	Dist = dist;
	for (int i = 0; i < Wsize; i++)
		weak.push_back(weak[i] + Nsize);
	sort(dist.begin(), dist.end());
	do {
		for (int i = 0; i < Wsize; i++) {
			int End = weak[i];
			int idx = 0;
			bool chk = false;
			for (int j = i; j < i + Wsize; j++) {
				if (weak[j] - End > Dist[idx]) {
					End = weak[j];
					idx++;
					if (idx == Dist.size()) {
						chk = true;
						break;
					}
				}
			}
			if (!chk)answer = min(answer, idx + 1);
			for (int i = 0; i < Dist.size(); i++)
				cout << Dist[i] << " ";
			cout << endl << answer << endl;
		}
	} while (next_permutation(Dist.begin(), Dist.end()));
	if (answer == INF)return -1;
	return answer;
}
int main() {
	//vector<int> weak = { 1, 3, 4, 9, 10 };
	vector<int> weak = { 1, 5, 6, 10 };//13 17 18 22
	//vector<int> dist = { 3, 5, 7 };
	vector<int> dist = { 1, 2, 3, 4 };
	cout << solution(12, weak, dist) << endl;
	return 0;
}