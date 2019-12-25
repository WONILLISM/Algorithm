#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
typedef struct RuleCharacter {	int idx; char c;}RC;
string solution(string sentence) {
	queue<RC> q;
	char tmp = sentence[0] >= 'a' ? sentence[0] : sentence[1];
	for (int i = 0; i < sentence.size(); i++) {
		char c = sentence[i];
		if (c == ' ') return "invalid";
		if (c >= 'a'&&c <= 'z') {
			q.push({i,c});
		}
	}
}

int main() {
	string s = "HaEaLaLaObWORLDb";
	solution(s);
	return 0;
}