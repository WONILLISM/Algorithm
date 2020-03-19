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
#define PIS pair<int,string>

using namespace std;
int answer = 0;
int area;

int solution(int n, vector<int> stations, int w){
	int answer = 0;
	int idx = 0;

	for (int i = 1; i <= n; i++) {
		if (idx < stations.size() && i >= stations[idx] - w) {
			i = stations[idx] + w;
			idx++;
		}
		else {
			i += (2 * w);
			if (i > n)
				i = n;
			answer++;
		}
	}

	return answer;
}
int main() {
	cout << solution(16, { 9 }, 2) << endl;
	//cout << solution(11, { 4,11 }, 1) << endl;
	return 0;
}