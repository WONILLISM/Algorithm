#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	string friends = "ACFJMNRT";

	string tmp;
	do {
		tmp = "";
		for (int i = 0; i < 8; i++)
			tmp += friends[i];

		bool chk = true;

		for (int i = 0; i < data.size(); i++) {
			char f1 = data[i][0], f2 = data[i][2];		// 비교 대상
			char comp = data[i][3];
			int dist = data[i][4] - '0';
			int pos1 = tmp.find(f1), pos2 = tmp.find(f2);

			if (comp == '>') chk = (abs(pos1 - pos2) - 1 <= dist) ? false : chk;
			else if (comp == '<') chk = (abs(pos1 - pos2) - 1 >= dist) ? false : chk;
			else  chk = (abs(pos1 - pos2) - 1) != dist ? false : chk;
		}
		if (chk)answer++;
	} while (next_permutation(friends.begin(), friends.end()));
	return answer;
}
int main() {
	cout << solution(2, { "N~F=0", "R~T>2" }) << endl;
	return 0;
}