#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
const int MAX = 2000;
vector<int> LC, RC;
int N;
int dp[MAX][MAX];
int process(int l, int r) {
	if (l >= N || r >= N)return 0;//ī�� �پ�
	if (dp[l][r])return dp[l][r];
	else {
		if (LC[l] > RC[r]) //���� ī�尡 ������ ī�庸�� �� Ŭ ��
		{
			int a = process(l + 1, r);			//1.���� ī�常 ���� �� �ִ�.
			int b = RC[r] + process(l, r + 1);	//2.������ ī�常 ���� �� �ִ�.
			int c = process(l + 1, r + 1);		//3.���� ������ �� �� ���� �� �ִ�.
			int d = a > c ? a : c;				//1, 3 �� ���� �� ũ��?
			dp[l][r] = b > d ? b : d;			//d�� 2 �� ���� �� ũ��?
		}
		else //���� ī�尡 ������ ī�庸�� �� ���� ��
		{
			int a = process(l + 1, r);			//1.���� ī�常 ���� �� �ִ�.
			int c = process(l + 1, r + 1);		//3.���� ������ �� �� ���� �� �ִ�.
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