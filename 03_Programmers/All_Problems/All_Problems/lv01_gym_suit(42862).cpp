#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include<algorithm>
#include<list>
#define PII pair<int,int>
#define endl '\n'
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				answer++;
				reserve.erase(reserve.begin() + j);
				lost.erase(lost.begin() + i);
				break;
			}
		}
	}
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (abs(lost[i] - reserve[j]) <= 1) {
				answer++;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}

	}
	return answer;
}
int main() {
	//cout << solution(5, { 2,4 }, { 1,2,5 }) << endl;
	cout << solution(8, { 4,5 }, { 5,6 }) << endl;
	return 0;
}