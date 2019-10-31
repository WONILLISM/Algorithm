#include<iostream>
#include <string>
#include <vector>

using namespace std;

int CNT, M, N;
vector<vector<int> > A, B;	//key, lock

void Rotate(){
	vector<vector<int> > tmp(M, vector<int>(M, 0));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			tmp[j][M - i - 1] = A[i][j];
	A = tmp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	A = key; B = lock;
	M = A.size(); N = B.size();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (B[i][j] == 0)
				CNT++;

	for (int r = 0; r < 4; r++){//È¸Àü
		for (int i = -25; i <= 25; i++){
			for (int j = -25; j <= 25; j++){
				int cnt = 0, fail = 0;
				for (int y = 0; y < M; y++) {
					for (int x = 0; x < M; x++) {
						int ny = i + y, nx = j + x;
						if (0 <= ny && ny < N && 0 <= nx && nx < N) {
							if (B[ny][nx] == 1 && A[y][x] == 1) fail = 1;
							else if (B[ny][nx] == 0 && A[y][x] == 1) cnt++;
						}
					}
				}
				if (cnt == CNT && fail == 0) return true;
			}
		}
		Rotate();
	}
	return false;
}
int main() {
	freopen("2.in", "r", stdin);
	cin >> N >> M;
	vector<vector<int>> k;
	vector<vector<int>> l;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		k.push_back(v);
	}
	for (int i = 0; i < M; i++) {
		vector<int> v;
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		l.push_back(v);
	}
	cout << solution(k, l) << endl;

	return 0;
}