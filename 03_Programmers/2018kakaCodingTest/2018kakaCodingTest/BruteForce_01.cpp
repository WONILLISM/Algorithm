#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int a[5] = { 1,2,3,4,5 };
int b[8] = { 2,1,2,3,2,4,2,5 };
int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
using namespace std;
int compare(int a, int b) {
	return a > b ? a : b;
}
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int cnt[3] = { 0, };
	int Max = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == a[i % 5]) cnt[0]++;
		if (answers[i] == b[i % 8]) cnt[1]++;
		if (answers[i] == c[i % 10]) cnt[2]++;
	}
	Max= compare(compare(cnt[0], cnt[1]), cnt[2]);
	for (int i = 0; i < 3; i++) {
		if (cnt[i] == Max)answer.push_back(i + 1);
	}
	return answer;
}
int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	vector<int> ans = solution(a);
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}