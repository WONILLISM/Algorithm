#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int dp[2502][2502];
string rw;//정방향
string bw;//역방향
//int LCS(int i, int j) {
//	if (i == 0 || j == 0)return 0;
//	//if (dp[i][j] != -1)return dp[i][j];
//	if (dp[i][j])return dp[i][j];
//	else {
//		if (rw[i] == bw[j])dp[i][j] = LCS(i - 1, j - 1) + 1;
//		else dp[i][j] = 0;
//		return dp[i][j];
//	}
//}
//int solution(string s){
//	int answer = 0;
//	
//	for (int i = 0; i < s.size(); i++)
//		bw.push_back(s[s.size() - 1 - i]);
//	s = "0" + s;
//	rw = s;
//	bw = "0" + bw;
//	int len1 = rw.size(), len2 = bw.size();
//	for (int i = 0; i < len1; i++) {
//		for (int j = 0; j < len2; j++) {
//			int a = LCS(i, j);
//			answer = answer > a ? answer : a;
//		}
//	}
//	return answer;
//}
//int solution(string s){
//	int answer = 0;
//	rw = s;
//	bw = s;
//	reverse(rw.begin(), rw.end());
//	/*s = "0" + s;
//	rw = s;
//	bw = "0" + bw;*/
//	int len1 = rw.size(), len2 = bw.size();
//	for (int i = 0; i <= len1; i++) {
//		for (int j = 0; j <= len2; j++) {
//			if (i == 0 || j == 0)dp[i][j] = 0;
//			else if (rw[i-1] == bw[j-1])dp[i][j] = dp[i - 1][j - 1] + 1;
//			else dp[i][j] = 0;
//			int a = dp[i][j];
//			answer = answer > a ? answer : a;
//		}
//	}
//	return answer;
//}
int solution(string s){
	int answer = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		for (int subLen = len; subLen > answer; subLen--) {
			int left = i;
			int right = left + subLen - 1;
			right = right >= len ? len : right;
			while (left < right && s[left] == s[right]) {
				left++;
				right--;
			}
			if (left >= right && answer < subLen) {
				answer = subLen;
				break;
			}
		}
	}
	return answer;
}
int main() {
	freopen("input.in", "r", stdin);
	string s;
	cin >> s;
	cout << solution(s) << endl;
	return 0;
}