#include <iostream>
#include <string>
#include <vector>

using namespace std;

int process(int x) {		// 1의 개수 카운팅
	int cnt = 0;
	while (x) {
		if (x % 2 == 1) cnt++;
		x /= 2;
	}
	return cnt;
}
int solution(int n) {
	int answer = 0;
	int cur = process(n);
	int next = 0;

	while (cur != next) {
		next = process(++n);
	}
	return answer;
}
int main() {
	cout << solution(15) << endl;
	return 0;
}