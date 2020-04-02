#include<iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	queue<int> q;
	q.push(0);
	answer.push_back(arr[0]);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = cur; i < arr.size(); i++) {
			if (arr[cur] != arr[i]) {
				q.push(i);
				answer.push_back(arr[i]);
				break;
			}
		}
	}
	return answer;
}
int main() {
	for (auto a : solution({ 1,1,3,3,0,0,1,1 }))
		cout << a << endl;
	return 0;
}