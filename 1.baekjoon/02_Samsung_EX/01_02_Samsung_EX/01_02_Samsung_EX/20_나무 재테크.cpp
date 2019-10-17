#include<iostream>

using namespace std;
const int MAX = 10;
int N, M, K;
int A[MAX][MAX];

typedef struct Pos{
	int x, y, z;
};
Pos tree[MAX*MAX];
void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {

	}
}
void Process() {

}
void Solution() {
	Input();
	Process();
}
int main() {
	Solution();
	return 0;
}