#include<cstdio>
const int MAX = 100;
char Map[MAX][MAX + 1];
int c_Step[MAX][MAX];
bool Visit[MAX][MAX];
int N, Ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
typedef struct Pos {
	int x, y;
	int step;
}Pos;
void Init() {
	Ans = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Map[i][j] = '\0';
			Visit[i][j] = false;
			c_Step[i][j] = 0;
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", Map[i]);
}
void DFS(int x, int y, int step) {
	Pos cur = { x,y,step };
	/*
	 * ���������� �������� �� ù��° ����̸� �� = ����ð�
	 * ù��° ��ΰ� �ƴϸ鼭 �ּڰ��� �ƴϸ� �� = ����ð�
	 */
	if (cur.y == N - 1 && cur.x == N - 1) {
		if (Ans==0)Ans = cur.step;
		else if (Ans > cur.step) Ans = cur.step;
		return;
	}
	/*
	 * ��θ� �� �� �̻� Ž�� ���� �� ��θ� �����϶����� �����ð��� ���� ���Ͽ�
	 * �����ð��� �� Ŀ���� ���� -> �� �̻� Ž���� �ʿ䰡 ����.
	 */
	if (Ans > 0 && Ans < cur.step)return;
	/*
	 * ù��° Ž���� ���� �����ð��� ����ؼ� �������ش�.
	 * ù��° Ž���� �ƴѰ�� ����� �����ð��� ���� Ž������ �����ð��� ���Ͽ�
	 * �ش� ��α����� �����ð��� �ּҷ� �ٲ��ְ� 
	 * ���� Ž������ ����� �����ð��� ����� �����ð����� ������ ���� -> �� �̻� Ž���� �ʿ䰡 ����.
	 */
	if (c_Step[cur.y][cur.x] == 0) c_Step[cur.y][cur.x] = cur.step;
	else {
		if (c_Step[cur.y][cur.x] > cur.step) c_Step[cur.y][cur.x] = cur.step;
		else return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[i];
		int ny = cur.y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N&&ny < N) {
			if (!Visit[ny][nx]) {
				Visit[ny][nx] = true;
				DFS(nx, ny, cur.step + (Map[ny][nx] - '0'));
				Visit[ny][nx] = false;
			}
		}
	}
}
int main() {
	freopen("WEEK6(1249).in.txt", "r", stdin);
	scanf("%*d");
	//freopen("Test.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		DFS(0, 0, 0);
		printf("#%d %d\n", tc, Ans);
	}
	return 0;
}

//#include<cstdio>
//const int MAX = 100;
//char Map[MAX][MAX + 1];
//int Visit[MAX][MAX];
////int Step[1000000];
//int Top, N, Ans, Min_Step;
//int dx[2] = { 1,0 };
//int dy[2] = { 0,1 };
//typedef struct Pos {
//	int x, y;
//	int step;
//}Pos;
//
//Pos Q[MAX*MAX];
//int f, r;
//
//void push(int x, int y, int s) {
//	Q[r++] = { x,y,s };
//}
//Pos pop() {
//	return Q[f++];
//}
//void Init() {
//	Min_Step = 1 << 30;
//	for (int i = 0; i < MAX; i++) {
//		for (int j = 0; j < MAX; j++) {
//			Map[i][j] = 0;
//			Visit[i][j] = 0;
//		}
//	}
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//		scanf("%s", Map[i]);
//}
//void BFS() {
//	Pos cur = { 0,0,0 };
//	Visit[cur.y][cur.x] = 0;
//	push(cur.x, cur.y, cur.step);
//	while (f != r) {
//		cur = pop();
//		int nx, ny;
//		for (int i = 0; i < 2; i++) {
//			nx = cur.x + dx[i];
//			ny = cur.y + dy[i];
//			if (nx >= 0 && ny >= 0 && nx < N&&ny < N) {
//				if (!Visit[ny][nx]) {
//
//					Visit[ny][nx] = cur.step + Map[ny][nx] - '0';
//					push(nx, ny, cur.step + Map[ny][nx] - '0');
//				}
//			}
//		}
//	}
//}
//int main() {
//	freopen("WEEK6(1249).in.txt", "r", stdin);
//	//freopen("Test.txt", "r", stdin);
//	scanf("%*d");
//	for (int tc = 1; tc <= 10; tc++) {
//		Init();
//		Ans = Min_Step;
//		printf("#%d %d\n", tc, Ans);
//	}
//	return 0;
//}