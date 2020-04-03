#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		int idx = 0;	// 선수 스킬 체크 인덱스
		bool chk = false;	// 스킬 트리 가능 여부
		for (int j = 0; j < skill_trees[i].size(); j++) {
			chk = false;
			char cur = skill_trees[i][j];
			for (int k = 0; k < skill.size(); k++) {
				if (cur == skill[k]) {
					if (idx != k) {
						chk = false;
						break;
					}
					else {
						idx++;
						chk = true;
						break;
					}
				}
				else chk = true;
			}
			if (!chk)break;
		}
		if (chk)answer++;
	}
	return answer;
}
int main() {
	cout << solution("CBD", { "BACDE","CBADF","AECB","BDA" }) << endl;
	return 0;
}