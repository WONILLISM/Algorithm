#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
using namespace std;

int N, M, K, A, B, T, cnt, ans; // 접수창구 수, 정비 창구 수, 고객 수, 이용 창구(a,b), 시간, 처리 카운트, 정답
int a[10], b[10], tk[1001]; //접수 창구, 정비 창구 처리시간 , 고객 도착시간

queue<int> rec_q, rep_q;	// 대기 큐

struct desk { int idx, time; };	
struct customer{ int a, b; };  
desk recept[10], repair[10];
customer c_info[1001];
void solution() {

	while (1) {
		// 도착한 순서대로 접수 대기 큐에 push
		for (int i = 1; i <= K; i++)
			if (tk[i] == T) rec_q.push(i);
		
		// 접수 처리가 끝났다면 정비 대기 큐에 push
		for (int i = 1; i <= N; i++) {
			if (recept[i].time == T && recept[i].idx != 0) {
				rep_q.push(recept[i].idx);
				recept[i].idx = 0; // 접수 창구 비움
			}
		}

		// 정비가 끝났다면 카운트 증가
		for (int i = 1; i <= M; i++) {
			if (repair[i].time == T && repair[i].idx != 0) {
				repair[i].idx = 0;	// 정비 창구 비움
				cnt++;
			}
		}

		// 접수 대기중인 고객들을 처리
		for (int i = 1; i <= N; i++) {
			if (rec_q.empty()) break;
			if (recept[i].idx == 0) {
				recept[i].idx = rec_q.front(); rec_q.pop(); // 고객 번호
				recept[i].time = T + a[i]; // 해당 접수 창구 처리시간 + 진행 시간
				c_info[recept[i].idx].a = i; // 해당 접수 창구를 이용하는 고객의 정보에 창구 번호를 넣어줌
			}
		}

		// 정비 대기중인 고객들을 처리
		for (int i = 1; i <= M; i++) {
			if (rep_q.empty()) break;
			if (repair[i].idx == 0) {
				repair[i].idx = rep_q.front(); rep_q.pop(); // 고객 번호
				repair[i].time = T + b[i]; // 해당 정비 창구 처리시간 + 진행 시간
				c_info[repair[i].idx].b = i; // 해당 정비 창구를 이용하는 고객의 정보에 창구 번호를 넣어줌
			}
		}

		if (cnt >= K) {
			for (int i = 1; i <= K; i++) {
				if (c_info[i].a == A && c_info[i].b == B)
					ans += i;
			}
			break;
		}
		T++;
	}
	if (!ans)ans = -1;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_2477.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M>> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> a[i];
		for (int i = 1; i <= M; i++)
			cin >> b[i];
		for (int i = 1; i <= K; i++)
			cin >> tk[i];
		
		ans = 0, T = 0, cnt = 0;

		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}