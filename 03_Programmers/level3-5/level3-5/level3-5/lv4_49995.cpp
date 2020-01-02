#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;
int solution(vector<int> cookie) {
	int answer = 0;
	int size = cookie.size();
	vector<int> sum;
	sum.push_back(0);
	sum.push_back(cookie[0]);
	for (int i = 1; i < size; i++)
		sum.push_back(sum[i] + cookie[i]);
	size++;//0 Ãß°¡
	for (int s = 0; s < size; s++) {
		for (int e = size - 1; e > s; e--) {
			int total = sum[e] - sum[s];
			if (total % 2 == 0 && total / 2 > answer) {
				for (int i = e; i > s; i--) {
					if (sum[i] - sum[s] == total / 2) {
						if (total / 2 > answer) {
							answer = total / 2;
							break;
						}
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	cout << solution({ 1,2,4,5 }) << endl;
	return 0;
}
