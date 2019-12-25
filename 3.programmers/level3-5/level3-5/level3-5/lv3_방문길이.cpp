#include <iostream>
#include <string>
#include<vector>
using namespace std;
int dp[11][11][4];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
struct Pos { int x, y; };
vector<Pos> v;
int ans;
int command(char d) {
	if (d == 'R')return 0;
	if (d == 'D')return 1;
	if (d == 'L')return 2;
	if (d == 'U')return 3;
}
/*
  0 1   0 1
0         1
1   1
*/
int solution(string dirs) {
	Pos cur = { 5,5 };
	v.push_back(cur);
	for (int i = 0; i < dirs.size(); i++) {
		cur = v.back(); v.pop_back();
		int d = command(dirs[i]);
		int nx = cur.x + dir[d][0], ny = cur.y + dir[d][1];
		if (nx >= 0 && ny >= 0 && nx < 11 && ny < 11) {
			int nd = (d + 2) % 4;
			if (!dp[ny][nx][nd]&& !dp[cur.y][cur.x][d]) {
					ans++;
			}
			dp[cur.y][cur.x][d]++;
			dp[ny][nx][nd]++;
			v.push_back({ nx,ny });
		}
		else v.push_back(cur);
	}
	return ans;
}
int main() {
	string s = { "ULURRDLLU" };
	cout << solution(s) << endl;

	return 0;
}