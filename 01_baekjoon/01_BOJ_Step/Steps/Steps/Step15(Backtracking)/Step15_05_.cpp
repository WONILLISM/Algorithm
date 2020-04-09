// ������ ���� �Ǿ����ϴ�. �̷� ���� �Լ� ������ ����Ǿ�, ������ �ڵ�� �������� ���� �� �ֽ��ϴ�.
// ���ο� �Լ� ������ �����Ϸ��� [�ڵ� �ʱ�ȭ] ��ư�� ��������. ��, [�ڵ� �ʱ�ȭ] ��ư�� ������ �ۼ� ���� �ڵ�� ������ϴ�.
#include <vector>
#include<algorithm>
using namespace std;
const int MAX = 2001;
vector<int> LC, RC;
int N;
int dp[MAX][MAX];
int process(int l, int r) {
	if (l >= N || r >= N)return 0;//ī�� �پ�
	if (dp[l][r])return dp[l][r];
	else {
		if (LC[l] > RC[r]) //���� ī�尡 ������ ī�尡 �� Ŭ ��
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
			int b = process(l + 1, r + 1);		//2.���� ������ �� �� ���� �� �ִ�.
			dp[l][r] = a > b ? a : b;
		}
		return dp[l][r];
	}
}
int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	N = left.size(), LC = left, RC = right;
	//int ans = process(0, 0);
	
	//int l = left.size(), r = right.size();
	//for (int i = l - 1; i >= 0; i--) {
	//	for (int j = r - 1; j >= 0; j--) {
	//		if (left[i] > right[j]) dp[i][j] = dp[i][j + 1] + right[j];
	//		else dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
	//	}
	//}
	//answer = dp[0][0];
	return answer;
}