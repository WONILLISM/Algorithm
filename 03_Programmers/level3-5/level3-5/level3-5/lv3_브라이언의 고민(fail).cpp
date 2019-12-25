#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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