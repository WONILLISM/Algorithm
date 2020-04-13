#include<iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string name) {
	int answer = 0;
	int answer1 = 0;
	int c1 = 0;
	int answer2 = 0;
	int c2 = 0;

	for (int i = 0; i < name.size(); i++) {
		int up = name[i] - 'A', down = 'Z' - name[i] + 1;
		int tmp = up < down ? up : down;
		if (name[i] == 'A')	c1++;
		else c1 = 0;
		answer1 += tmp;
		answer1++;
	}
	answer1--;
	answer1 -= c1;

	answer2 += name[0] - 'A';
	answer2++;
	for (int i = name.size() - 1; i > 0; i--) {
		int up = name[i] - 'A', down = 'Z' - name[i] + 1;
		int tmp = up < down ? up : down;
		if (name[i] == 'A')	c2++;
		else c2 = 0;
		answer2 += tmp;
		answer2++;
	}
	answer2--;
	answer2 -= c2;

	answer = min(answer1, answer2);
	return answer;
}
int main() {
	/*cout << solution("JEROEN") << endl;
	cout << solution("JAN") << endl;*/
	//cout << solution("ABABAAAAABA") << endl;
	cout << solution("Y") << endl;
	return 0;
}