#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
using namespace std;
//1 1 2 3 6 7 30
int solution(vector<int> w) {
	sort(w.begin(), w.end());
	int sum = 0;
	for (auto num : w) {
		if (sum + 1 >= num)sum += num;
		else break;
	}
	return sum + 1;
}
int main() {
	vector<int> w = { 3,1,6,2,7,30,1 };
	cout << solution(w) << endl;
}