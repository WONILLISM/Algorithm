#include<iostream>
using namespace std;
const int MAX = 100;
int R, C, M, ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
//(r,c) s�ӷ�, d����, zũ��
typedef struct Shark {
	int s, d, z;
};
Shark Map[MAX][MAX];

void Input() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Map[r][c] = { s,d - 1,z };
	}
}
void Catch(int t) {
	for (int i = 0; i < R; i++) {
		if (Map[i][t].z) {
			ans += Map[i][t].z;
			Map[i][t] = { 0,0,0 };
		}
	}
}
//(r,c) s�ӷ�, d����, zũ��
//d: 0�� 1�Ʒ� 2���� 3��
void MoveShark() {
	Shark tmp[MAX][MAX];
	 
}
void Process() {
	for (int t = 0; t < C; t++) {

	}
}
void Solution() {
	Input();
	Process();
	cout << ans << "\n";
}
int main() {
	freopen("23.in", "r", stdin);
	Solution();
	return 0;
}