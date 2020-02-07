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

int N, M, K, A, B, T, cnt, ans; // ����â�� ��, ���� â�� ��, �� ��, �̿� â��(a,b), �ð�, ó�� ī��Ʈ, ����
int a[10], b[10], tk[1001]; //���� â��, ���� â�� ó���ð� , �� �����ð�

queue<int> rec_q, rep_q;	// ��� ť

struct desk { int idx, time; };	
struct customer{ int a, b; };  
desk recept[10], repair[10];
customer c_info[1001];
void solution() {

	while (1) {
		// ������ ������� ���� ��� ť�� push
		for (int i = 1; i <= K; i++)
			if (tk[i] == T) rec_q.push(i);
		
		// ���� ó���� �����ٸ� ���� ��� ť�� push
		for (int i = 1; i <= N; i++) {
			if (recept[i].time == T && recept[i].idx != 0) {
				rep_q.push(recept[i].idx);
				recept[i].idx = 0; // ���� â�� ���
			}
		}

		// ���� �����ٸ� ī��Ʈ ����
		for (int i = 1; i <= M; i++) {
			if (repair[i].time == T && repair[i].idx != 0) {
				repair[i].idx = 0;	// ���� â�� ���
				cnt++;
			}
		}

		// ���� ������� ������ ó��
		for (int i = 1; i <= N; i++) {
			if (rec_q.empty()) break;
			if (recept[i].idx == 0) {
				recept[i].idx = rec_q.front(); rec_q.pop(); // �� ��ȣ
				recept[i].time = T + a[i]; // �ش� ���� â�� ó���ð� + ���� �ð�
				c_info[recept[i].idx].a = i; // �ش� ���� â���� �̿��ϴ� ���� ������ â�� ��ȣ�� �־���
			}
		}

		// ���� ������� ������ ó��
		for (int i = 1; i <= M; i++) {
			if (rep_q.empty()) break;
			if (repair[i].idx == 0) {
				repair[i].idx = rep_q.front(); rep_q.pop(); // �� ��ȣ
				repair[i].time = T + b[i]; // �ش� ���� â�� ó���ð� + ���� �ð�
				c_info[repair[i].idx].b = i; // �ش� ���� â���� �̿��ϴ� ���� ������ â�� ��ȣ�� �־���
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