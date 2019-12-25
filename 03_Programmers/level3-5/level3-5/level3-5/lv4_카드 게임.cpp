#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
const int MAX = 2000;
vector<int> LC, RC;
int N;
int dp[MAX][MAX];
int process(int l, int r) {
	if (l >= N || r >= N)return 0;//카드 다씀
	if (dp[l][r])return dp[l][r];
	else {
		if (LC[l] > RC[r]) //왼쪽 카드가 오른쪽 카드보다 더 클 때
		{
			int a = process(l + 1, r);			//1.왼쪽 카드만 버릴 수 있다.
			int b = RC[r] + process(l, r + 1);	//2.오른쪽 카드만 버릴 수 있다.
			int c = process(l + 1, r + 1);		//3.왼쪽 오른쪽 둘 다 버릴 수 있다.
			int d = a > c ? a : c;				//1, 3 중 누가 더 크냐?
			dp[l][r] = b > d ? b : d;			//d랑 2 중 누가 더 크냐?
		}
		else //왼쪽 카드가 오른쪽 카드보다 더 작을 때
		{
			int a = process(l + 1, r);			//1.왼쪽 카드만 버릴 수 있다.
			int c = process(l + 1, r + 1);		//3.왼쪽 오른쪽 둘 다 버릴 수 있다.
			dp[l][r] = a > c ? a : c;
		}
		return dp[l][r];
	}
}
int solution(vector<int> left, vector<int> right) {
	N = left.size(), LC = left, RC = right;
	int ans = process(0, 0);
	return ans;
}
int main() {
	vector<int> l = { 3,2,5 };
	vector<int> r = { 2,4,1 };
	cout << solution(l,r) << endl;
	return 0;
}