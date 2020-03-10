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

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	int start = 1;			// 시작점
	int end = distance;		// 끝점

	// 이분탐색 시작
	while (start <= end) {
		int mid = (start + end) / 2;
		int del = 0;			// 지운 바위 개수
		int lastIdx = -1;		
		
		//cout << "시작점: " << start << " 끝점: " << end << " 중간값: " << (start + end) / 2 << endl;
		for (int i = 0; i <= rocks.size(); i++) {
			int d;				// 두 바위 사이의 거리
			if (lastIdx == -1)d = rocks[i]; 
			else {
				if (i == rocks.size())d = distance - rocks[lastIdx];
				else d = rocks[i] - rocks[lastIdx];
			}
			// if (mid == 12) cout << "i: " << i << " lstidx: " << lastIdx << " d: " << d << endl;
			if (d < mid)del++;		// 두 바위 사이의 거리가 mid 보다 작으면 바위 하나 지움
			else lastIdx = i;		// mid 길이 이상 탐색 했다면 인덱스 교체
		}
		 //cout << del << endl;
		if (del > n) end = mid - 1;	// 지운 바위 수가 n보다 많으면 끝점 = mid - 1
		else if(del<=n){
			start = mid + 1;			// 지운 바위 수가 n보다 작거나 같으면 시작점 = mid + 1
			answer = mid;
		}
	}

	return answer;
}
int main() {
	//cout << solution(25, { 2,14,11,21,17 }, 2) << endl;
	//cout << solution(34, { 5,19,28 }, 2) << endl;
	cout << solution(1234, { 1,2,3 }, 3) << endl;
	return 0;
}