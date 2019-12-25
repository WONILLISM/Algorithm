#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	return answer;
}
//typedef struct Pos {
//	int a;
//	bool poll, plat;
//};
//Pos map[101][101];
//vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
//	vector<vector<int>> answer;
//	for (int i = 0; i <= n; i++) {
//		map[0][i].poll = true;
//		map[0][i].plat = false;
//	}
//	for (int i = 0; i < build_frame.size(); i++) {
//		int x = build_frame[i][0], y = build_frame[i][1];
//		int a = build_frame[i][2], b = build_frame[i][3];
//		//생성
//		if (b) {
//			if (!a) {//생성할 것이 기둥이라면
//				if (map[y][x].poll) {
//					map[y][x].a = 1;
//					if (y + 1 <= n) {
//						map[y + 1][x].poll = true;
//						map[y + 1][x].plat = true;
//					}
//				}
//			}
//			else {//생성할 것이 보라면
//				if (map[y][x].plat) {
//					map[y][x].a = 2;
//					if (x + 1 <= n) {
//						map[y][x + 1].poll = true;
//						if (x + 2 <= n && map[y][x+2].plat) {
//							map[y][x + 1].plat = true;
//						}
//					}
//				}
//			}
//		}
//		else {//삭제
//			if (!a) {//삭제할 것이 기둥이라면
//				map[y][x].a = 0;
//				
//			}
//		}
//	}
//	return answer;
//}
int main() {
	vector<vector<int>> bf = { {1, 0, 0, 1},
							  {1, 1, 1, 1},
							  {2, 1, 0, 1},
							  {2, 2, 1, 1},
							  {5, 0, 0, 1},
							  {5, 1, 0, 1},
							  {4, 2, 1, 1},
							  {3, 2, 1, 1} };

	/*vector<vector<int>> bf = { {0, 0, 0, 1}, 
								{2, 0, 0, 1}, 
								{4, 0, 0, 1}, 
								{0, 1, 1, 1}, 
								{1, 1, 1, 1}, 
								{2, 1, 1, 1}, 
								{3, 1, 1, 1}, 
								{2, 0, 0, 0}, 
								{1, 1, 1, 0}, 
								{2, 2, 0, 1} };*/
	solution(5, bf);
	return 0;
}