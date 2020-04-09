// 문제가 개편 되었습니다. 이로 인해 함수 구성이 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <vector>
#include<algorithm>
using namespace std;
const int MAX = 2001;
vector<int> LC, RC;
int N;
int dp[MAX][MAX];
int process(int l, int r) {
	if (l >= N || r >= N)return 0;//카드 다씀
	if (dp[l][r])return dp[l][r];
	else {
		if (LC[l] > RC[r]) //왼쪽 카드가 오른쪽 카드가 더 클 때
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
			int b = process(l + 1, r + 1);		//2.왼쪽 오른쪽 둘 다 버릴 수 있다.
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