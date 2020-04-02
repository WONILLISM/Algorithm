#include<iostream>
#include<vector>
#include<queue>
#define PII pair<int,int>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {	// 최대공약수 구하기
	while (b) {
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}
long long solution(int w, int h){
	ll answer = w * h;
	int GCD = gcd(w, h);
	return answer - (w + h - GCD);
}
int main() {
	cout << solution(8, 12);
	return 0;
}

//ll solution(int w, int h) {
//	ll answer = w * h;
//	int GCD = gcd(w, h);
//	int mw = w / GCD, mh = h / GCD;
//	vector<vector<int>> visit(mh, vector<int>(mw, 0));
//	int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
//	queue<PII> q;
//	q.push({ 0,0 });
//	visit[0][0] = 1;
//	while (!q.empty()) {
//		PII cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cur.second + dx[i];
//			int ny = cur.first + dy[i];
//			if (nx >= 0 && nx < mw&&ny >= 0 && ny < mh) {
//				if (!visit[ny][nx]) {
//					visit[ny][nx] = visit[cur.first][cur.second] + 1;
//					q.push({ ny,nx });
//				}
//			}
//		}
//	}
//	answer -= visit[mh - 1][mw - 1] * GCD;
//	return answer;
//}