#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
//��ü ����� �� 33�� ���۰� �� ����
//���� ����� ���� ��� ������ ���� �׷���
struct Map { int score, next; };
Map graph[33];


bool visit[33]; //�湮 üũ
int player[4], dice[10], ans; // �� 4���� ��ġ, 10���� �ֻ��� ���, ����
int cnt, sum;
void solution() {
	while (1) {
		

	}
}
int main() {
	//path 1 0~21
	//path 2(5�� ����) 22~24
	//path 3(10�� ����) 26~27
	//path 4(15�� ����) 28~30
	//25���� ���� �� 31~32
	for (int i = 0; i <= 20; i++)graph[i] = { i * 2, i + 1 };
	graph[5] = { 10 ,22 };
	for (int i = 22; i <= 24; i++)graph[i] = { 10 + (i - 21) * 3 ,i + 1 };
	graph[10] = { 20,26 };
	graph[26] = { 22,27 };
	graph[27] = { 24,25 };
	graph[28] = { 28,29 };
	graph[29] = { 27,30 };
	graph[30] = { 26,25 };
	graph[25] = { 30,31 };
	graph[31] = { 30,32 };
	graph[32] = { 35,20 };

	for (int i = 0; i < 10; i++)cin >> dice[i];
	solution();

	return 0;
}







//�־��� ����Ǽ� 4^10 
//int ans, sum;
//struct Pos { int score, player; };//��ġ�� ������ ���� ��ġ�� �ִ� ���� ��ȣ
//vector<vector<Pos>> Path;
//vector<int> Dice;
//vector<int> checkDice;
//bool playerchk[5];
//
//void setPath() {
//	Path.assign(5, vector<Pos>());
//	for (int i = 0; i < 21; i++) {
//		Path[0].push_back({ i * 2,0 });
//	}
//	for (int i = 0; i <= 4; i++) {
//		if (i == 4)Path[1].push_back({ 25,0 });
//		else Path[1].push_back({ 10 + i * 3 ,0});
//	}
//	for (int i = 0; i <= 3; i++) {
//		if (i == 3)Path[2].push_back({ 25,0 });
//		else Path[2].push_back({ 20 + i * 2,0 });
//	}
//	for (int i = 0; i <= 4; i++) {
//		if (i == 4)Path[3].push_back({ 25,0 });
//		else Path[3].push_back({ 30 - i * 2,0 });
//	}
//	for (int i = 0; i <= 3; i++)
//		Path[4].push_back({ 25 + i * 5,0 });
//	for (int i = 0; i < 10; i++) {
//		int a;
//		cin >> a;
//		Dice.push_back(a);
//	}
//}
//void dfs(int dice, int path, int idx, int player,int sum) {
//	int cur_idx = idx, cur_path = path, cur_dice = dice;
//	if (cur_dice == 9) {
//		ans = max(ans, sum);
//		return;
//	}
//	Path[cur_path][cur_idx].player = player;
//	
//	int next_idx, next_path, next_player, next_dice;
//	next_path = cur_path;
//	next_dice = cur_dice + 1;
//	next_idx = cur_idx + Dice[cur_dice];
//	
//	if (cur_path == 0) {
//		if (next_idx == 5) {
//			next_path = 1;
//			next_idx = 0;
//		}
//		if (next_idx == 10) {
//			next_path = 2;
//			next_idx = 0;
//		}
//		if (next_idx == 15) {
//			next_path = 3;
//			next_idx = 0;
//		}
//	}
//	else if (cur_path == 1) {
//		if (next_idx > 4) {
//			next_path = 4;
//			next_idx -= 5;
//		}
//	}
//	else if (cur_path == 2) {
//		if (next_idx > 3) {
//			next_path = 4;
//			next_idx -= 4;
//		}
//	}
//	else if (cur_path == 3) {
//		if (next_idx > 4) {
//			next_path = 4;
//			next_idx -= 4;
//		}
//	}
//	if (player<=4&&Path[next_path].size() > next_idx) {
//		if (!Path[next_path][next_idx].player) {
//			Path[next_path][next_idx].player = player;
//			sum += Path[next_path][next_idx].score;
//			dfs(next_dice, next_path, next_idx, player, sum);
//			Path[next_path][next_idx].player = 0;
//		}
//		else {
//
//		}
//		//���ο� ���� �߰��� ����...
//		
//	}
//	
//	
//	
//}
//void solution() {
//	dfs(0, 0, 0, 1, 0);
//	cout << ans << endl;
//}
//int main() {
//	setPath();
//	solution();
//	
//	return 0;
//}