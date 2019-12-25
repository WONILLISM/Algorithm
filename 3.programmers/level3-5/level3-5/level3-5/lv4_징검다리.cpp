#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	int l = 1;
	int r = distance;
	// 1 2 3 4 5 6 7 8  25
	while (l <= r) {
		int mid = (l + r) / 2;
		int del = 0;
		int lastIdx = -1;
		for (int i = 0; i <= rocks.size(); ++i) {
			int d;
			if (lastIdx == -1)d = rocks[i];
			else {
				if (i == rocks.size())d = distance - rocks.back();
				else d = rocks[i] - rocks[lastIdx];
			}
			if (d < mid) {
				del++;
			}
			else lastIdx = i;
		}
		if (del > n) {
			r = mid - 1;
		}
		else if (del <= n) {
			l = mid + 1;
			answer = answer < mid ? mid : answer;
		}
	}
	return answer;
}
int main() {
	vector<int> r = { 2, 14, 11, 21, 17 };
	cout << solution(25, r, 2);
	return 0;
}