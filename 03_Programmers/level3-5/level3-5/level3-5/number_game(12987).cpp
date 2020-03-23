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
// 1 3 5 7
// 2 2 6 8	
int solution(vector<int> A, vector<int> B) {
	int answer = 0, save = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {	// A team
		for (int j = save; j < B.size(); j++) {		// B team
			if (A[i] < B[j]) {
				answer++;
				save = j;
				save++;
				break;
			}
		}
	}

	return answer;
}

int main() {
	cout << solution({ 5,1,3,7 }, { 2,2,6,8 }) << endl;
	return 0;
}