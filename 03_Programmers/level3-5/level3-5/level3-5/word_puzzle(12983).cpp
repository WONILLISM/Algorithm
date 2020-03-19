#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define PIS pair<int,string>

using namespace std;
const int MAX_INT = 1 << 30;

set<string> s;
vector<int> dp;
int solution(vector<string> strs, string t){
	int answer = 0;
	int size = t.size();
	dp.assign(size + 1, MAX_INT);
	dp[size] = 0;
	for (auto a : strs)
		s.insert(a);
	for (int i = size - 1; i >= 0; i--) {
		string tmp;
		for (int j = i; j < size; j++) {
			tmp += t[j];
			if (s.count(tmp) != 0) {	// 단어가 있으면
				if (dp[j + 1] != MAX_INT)
					dp[i] = min(dp[i], dp[j + 1] + 1);
			}
			if (j > i + 5)break;
		}
	}
	if (dp[0] != MAX_INT)answer = dp[0];
	else answer = -1;

	return answer;
}
int main() {
	cout << solution({ "app", "ap", "p", "l", "e", "ple", "pp" }, "apple") << endl;
	cout << solution({ "ba", "na", "n", "a" }, "banana") << endl;
	
	return 0;
}