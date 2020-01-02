#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;
//vector<int> answer;
//int process(int s, int n) {
//	if (n == 1) {
//		answer.push_back(s);
//		return s;
//	}
//	else {
//		int a = s / n;
//		int b = s - s / n;
//		answer.push_back(a);
//		process(b, n - 1);
//	}
//}

vector<int> solution(int n, int s) {
	vector<int> answer;
	if (n > s) //집합을 만들 수 없는 경우
		answer.push_back(-1);
	else {
		int div = s / n;
		int diff = s % n;
		int pos = n - 1;
		answer.assign(n, div); //  합을 원소개수로 나눈 몫으로 집합을 먼저 채움
		for (int i = diff; i > 0; i--)  //나머지를 위해 집합의 마지막 원소부터 순차적으로 1을 더해줌
			answer[pos--]++;
	}
	return answer;
}
int main() {
	for (auto a : solution(2, 1)) {
		cout << a;
	}
	return 0;
}
